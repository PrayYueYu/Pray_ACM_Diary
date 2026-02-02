#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int g[2][N], h[2][N];
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

int calc_len(std::string s) {
	int now = 0, len = s.size() - 1;
	for(int i = 1; i <= len; i++) {
		h[now][i] = g[now][i] = 0;
	}
	h[now][0] = 1;
	g[now][0] = 0;
	for(int i = 1; i <= len; i++) {
		int t = now;
		now = 1 - now;
		for(int j = 0; j <= len; j++) {
			h[now][j] = g[now][j] = 0;
		}
		for(int j = 0; j < i; j++) {
			if(!h[t][j]) continue;
			h[now][j] = (h[now][j] + h[t][j]) % mod;
			g[now][j] = (g[now][j] + g[t][j]) % mod;
			if(s[i] == '(') {
				h[now][j + 1] = (h[now][j + 1] + h[t][j]) % mod;
				g[now][j + 1] = (g[now][j + 1] + g[t][j] + h[t][j]) % mod;
			}
			if(s[i] == ')') {
				if(j <= 0) continue;
				h[now][j - 1] = (h[now][j - 1] + h[t][j]) % mod;
				g[now][j - 1] = (g[now][j - 1] + g[t][j] + h[t][j]) % mod;
			}
		}	
	}
	return g[now][0];
}
int calc_cnt(std::string s) {
	int now = 0, len = s.size() - 1;
	for(int i = 1; i <= len; i++) {
		h[now][i] = g[now][i] = 0;
	}
	h[now][0] = 1;
	g[now][0] = 0;
	for(int i = 1; i <= len; i++) {
		int t = now;
		now = 1 - now;
		for(int j = 0; j <= len; j++) {
			h[now][j] = g[now][j] = 0;
		}
		for(int j = 0; j < i; j++) {
			if(!h[t][j]) continue;
			h[now][j] = (h[now][j] + h[t][j]) % mod;
			g[now][j] = (g[now][j] + g[t][j]) % mod;
			if(s[i] == '(') {
				h[now][j + 1] = (h[now][j + 1] + h[t][j]) % mod;
				g[now][j + 1] = (g[now][j + 1] + g[t][j] + h[t][j]) % mod;
			}
			if(s[i] == ')') {
				if(j <= 0) continue;
				h[now][j - 1] = (h[now][j - 1] + h[t][j]) % mod;
				g[now][j - 1] = (g[now][j - 1] + g[t][j] + h[t][j]) % mod;
			}
		}	
	}
	return h[now][0] - 1;
}
signed main() {
	std::string s;
	std::cin >> s;
	s = " " + s;
	std::cout << calc_len(s) << ' ' << calc_cnt(s) << '\n';
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
