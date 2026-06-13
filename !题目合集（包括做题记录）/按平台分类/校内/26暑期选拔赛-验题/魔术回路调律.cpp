#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n;
std::string s;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
std::map<int, int> mp, vis;
void solve() {
	std::cin >> n;
	std::cin >> s;
	s = " " + s;
	mp.clear(); vis.clear();
	int d = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'a') d++;
		else d--;
	}
	mp[0] = 0;
	vis[0] = true;
	int ans = INF, sum = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'a') sum++;
		else sum--;
		vis[sum] = true;
		mp[sum] = i;
		if(vis[sum - d]) {
			ans = std::min(ans, i - mp[sum - d]);
		} 
		
	}
	if(ans >= n) std::cout << "-1\n";
	else std::cout << ans << '\n';
}
signed main() {
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
