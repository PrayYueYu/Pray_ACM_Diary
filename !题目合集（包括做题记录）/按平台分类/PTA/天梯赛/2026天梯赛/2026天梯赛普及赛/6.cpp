#include<bits/stdc++.h>
#define int long long
const int N = 2e3 + 100;
std::map<int, int> mp;
void solve() {
	int f = 0;
	while(true) {
		int x; std::cin >> x;
		if(x == -1) break;
		if(mp[x] && !f) f = x;
		mp[x] = true;
	}
	if(f) std::cout << f << '\n';
	else std::cout << "None\n";
}
signed main() {
	int T; std::cin >> T;
	while(T--) {
		solve();
		mp.clear();
	}
	return 0;
} 
