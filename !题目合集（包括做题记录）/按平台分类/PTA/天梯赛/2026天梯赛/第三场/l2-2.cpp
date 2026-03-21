#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m;
std::map<std::string, int> mp;
std::map<std::string, std::set<std::string>> to;
void solve() {
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		std::string s;
		int cnt;
		std::cin >> s >> cnt;
		mp[s] = cnt + 1;
	}
	for(int i = 1; i <= m; i++) {
		std::string op, name, s;
		std::cin >> op >> name >> s;
		if(op == "store") {
			if(!mp[s]) std::cout << "Can't store " << s << '\n';
			else if(mp[s] == 1) std::cout << "No place for " << s << '\n';
			else {
				std::cout << s << " stored\n";
				mp[s]--;
				to[s].insert(name);
			}
		}
		else {
			if(!mp[s]) std::cout << "We don't have " << s << " here\n";
			else {
				auto it = to[s].find(name);
				if(it == to[s].end()) std::cout << s << " not found\n";
				else {
					mp[s]++;
					to[s].erase(it);
					std::cout << s << " taken\n";
				}
			} 
		}
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
