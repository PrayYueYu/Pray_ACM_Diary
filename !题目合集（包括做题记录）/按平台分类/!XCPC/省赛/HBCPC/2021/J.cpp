#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n;
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
	n = read();
	for(int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		int f = false;
		int s1 = 0, s2 = 0, ans = 0;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == '-') {
				s1 = s2 = 0;
				break;
			}
			if(s[j] == '+') f = true;
			if(s[j] <= '9' && s[j] >= '0') {
				if(!f) s1 = s1 * 10 + s[j] - '0';
				else s2 = s2 * 10 + s[j] - '0';
			}
		}
		ans = s1 + s2 * 20;
		std::cout << ans << '\n';
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
/*

*/
