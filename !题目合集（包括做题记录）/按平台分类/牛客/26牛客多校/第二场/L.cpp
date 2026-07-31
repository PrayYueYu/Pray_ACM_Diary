#include<bits/stdc++.h>
#define int long long
const int N = 5e6 + 10, mod = 998244353, INF = 1e18;
int n, p[N], pre[100], f[N];
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
	std::cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i++) p[i] = read();
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(p[i] > p[j]) {
				pre[j] |= (1 << i);
				cnt++;
			}
		}
	}
	f[0] = 1;
	int ALL = (1 << n) - 1;
	for(int i = 0; i <= ALL; i++) {
		for(int j = 0; j < n; j++) {
			if((i >> j & 1)) continue;
			int ne = (i | (1 << j));
			if((i & pre[j]) == pre[j]) {
				f[ne] = (f[ne] + f[i]) % mod;
			}
		}
	}
	if(!cnt) std::cout << f[ALL] << '\n';
	else std::cout << f[ALL] * 2 % mod << '\n';
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
	Writer: ÔÂö§Þ±‹¬ 
*/
