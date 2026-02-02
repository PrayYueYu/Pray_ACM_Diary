#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, sum[N];
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
void init() {
	for(int i = 0; i <= n + 2; i++) {
		sum[i] = 0;
	}
}

void solve() {
	n = read();
	std::cin >> s;
	s = " " + s;
	int ans = -1, las = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '(') las = i;
	}
	for(int i = 1; i <= n; i++) {
		if(s[i] == ')' && s[i + 1] == '(') {
			if(i + 1 == las) continue;
			ans = n - 2;
			break;
		}
	}
	std::cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
