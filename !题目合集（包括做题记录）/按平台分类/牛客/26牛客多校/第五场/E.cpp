#include<bits/stdc++.h>
#define int long long
const int N = 1e7 + 10, mod = 998244353, INF = 1e18;
int f[N + 1], v[2000010], num, n, c, h[100], g[N];
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
void Pre() {
	f[1] = 1;
	for(int i = 2; i <= N; i++) {
	    if(!f[i]) {
	        v[++num] = i;
	        f[i] = i;
	        for(int j = 2; j <= N; j++) {
	            if(i * j > N) break;
	            f[i * j] = i;
	        }
	    }
	}
}
void solve() {
	std::cin >> n >> c;
	Pre(); int ans = 0, pc = 1;
	for(int i = 1; i <= n; i++) {
		int sum = 1, now = i;
		if(i != 1) {
			sum = g[i / f[i]] + 1;
			g[i] = sum;
		}
		pc = pc * c % mod;
		ans = (ans + pc * h[sum] % mod) % mod;
	}
	std::cout << ans << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	h[1] = 1;
	h[2] = 2;
	h[3] = 3;
	h[4] = 5;
	h[5] = 7;
	h[6] = 11;
	h[7] = 13;
	h[8] = 17;
	h[9] = 19;
	h[10] = 23;
	h[11] = 29;
	h[12] = 31;
	h[13] = 37;
	h[14] = 41;
	h[15] = 43;
	h[16] = 47;
	h[17] = 53;
	h[18] = 59;
	h[19] = 61;
	h[20] = 67;
	h[21] = 71;
	h[22] = 73;
	h[23] = 79;
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
