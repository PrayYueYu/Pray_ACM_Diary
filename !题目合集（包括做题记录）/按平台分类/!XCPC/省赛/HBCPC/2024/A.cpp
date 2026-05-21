#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int vis[1000];
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
void solve() {
	std::string s;
	std::cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(!vis[s[i]] && s[i] != 'i') {
			cnt++;
			vis[s[i]] = true;
		}
	}
	std::cout << cnt;
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
