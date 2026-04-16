#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 100;
int n, k;
std::map<std::string, char> mp;
void solve() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::string s; char c;
		std::cin >> s >> c;
		mp[s] = c;
	}
	std::cin >> k;
	std::vector<int> ans;
	for(int i = 1; i <= k; i++) {
		int cnt; std::cin >> cnt;
		int f = true;
		for(int j = 1; j <= cnt; j++) {
			std::string s;
			std::cin >> s;
			if(mp[s] == 'e') f = false;
		}
		if(f) ans.push_back(i);
	}
	if(!ans.size()) std::cout << "None";
	else {
		for(int i = 0; i < ans.size(); i++) {
			if(i) std::cout << ' ';
			std::cout << ans[i];
		}
	}
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
