#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, a[N], v[100][3][3][3];
int f[2][2][2][2][2][2], vx[33][3][3][3];
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
	for(int i = 0; i <= 30; i++) {
		for(int x = 0; x <= 1; x++) {
			for(int y = 0; y <= 1; y++) {
				for(int z = 0; z <= 1; z++) {
					v[i][x][y][z] = 0;
				}
			}
		}
	}
}
int calc(int x) {
	int ans = 0;
	for(int i = 0; i <= 30; i++) {
		if(x >> i & 1) {
			if(!i || !(x >> (i - 1) & 1)) ans++;
		}
	}
	return ans;
}
void solve() {
	std::cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		for(int j = 30; j >= 0; j--) {
			int t = (a[i] >> j & 1);
			int ne = 0;
			int las = (a[i] >> (j + 1) & 1);
			if(j) ne = (a[i] >> (j - 1) & 1);
			v[j][las][t][ne]++;
			las = t;
		}
		ans += calc(a[i]);
	}
	m = read();
	for(int i = 1; i <= m; i++) {
		int op = read(), x = read();
		for(int j = 30; j >= 0; j--) {
			int t = (x >> j & 1);
			int f1 = 1, f0 = 0, ne1 = 0, ne0 = 0;
			if(op == 1) {
				ne1 = f1 & t;
				ne0 = f0 & t;
			}
			if(op == 2) {
				ne0 = f0 | t;
				ne1 = f1 | t;
			}
			if(op == 3) {
				ne0 = f0 ^ t;
				ne1 = f1 ^ t;
			}
//			std::cout << f0 << ' ' << ne0 << ' ' << f1 << ' ' << ne1 << '\n';
			for(int x = 0; x <= 1; x++) {
				for(int y = 0; y <= 1; y++) {
					for(int z = 0; z <= 1; z++) {
						if(j <= 29) vx[j + 1][x][y][z] = 0;
						vx[j][x][y][z] = 0;
						if(j) vx[j - 1][x][y][z] = 0;
					}
				}
			}
			for(int x = 0; x <= 1; x++) {
				for(int y = 0; y <= 1; y++) {
					if(j <= 29) {
						vx[j + 1][x][y][ne0] += v[j + 1][x][y][f0];
						vx[j + 1][x][y][f0] -= v[j + 1][x][y][f0];
					}
					vx[j][x][ne0][y] += v[j][x][f0][y];
					vx[j][x][f0][y] -= v[j][x][f0][y];
					ans += f[x][f0][y][x][ne0][y] * v[j][x][f0][y];
					if(j) {
						vx[j - 1][ne0][x][y] += v[j - 1][f0][x][y];
						vx[j - 1][f0][x][y] -= v[j - 1][f0][x][y];
					}
					
					if(j <= 29) {
						vx[j + 1][x][y][ne1] += v[j + 1][x][y][f1];
						vx[j + 1][x][y][f1] -= v[j + 1][x][y][f1];
					}
					vx[j][x][ne1][y] += v[j][x][f1][y];
					vx[j][x][f1][y] -= v[j][x][f1][y];
					ans += f[x][f1][y][x][ne1][y] * v[j][x][f1][y];
					if(j) {
						vx[j - 1][ne1][x][y] += v[j - 1][f1][x][y];
						vx[j - 1][f1][x][y] -= v[j - 1][f1][x][y];
					}
				}
			}
			for(int x = 0; x <= 1; x++) {
				for(int y = 0; y <= 1; y++) {
					for(int z = 0; z <= 1; z++) {
						if(j <= 29) v[j + 1][x][y][z] += vx[j + 1][x][y][z];
						v[j][x][y][z] += vx[j][x][y][z];
						if(j) v[j - 1][x][y][z] += vx[j - 1][x][y][z];
					}
				}
			}
		}
		std::cout << ans << '\n';
	}
}
signed main() {
	f[1][1][1][1][0][1] = 1;
	f[0][0][0][0][1][0] = 1;
	f[1][0][1][1][1][1] = -1;
	f[1][0][0][1][1][0] = 0;
	f[1][1][0][1][0][0] = 0;
	f[0][0][1][0][1][1] = 0;
	f[0][1][0][0][0][0] = -1;
	f[0][1][1][0][0][1] = 0;
	int T = 1; 
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
4
3 5 6 10
4
1 7
2 8
3 15
2 3

----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
