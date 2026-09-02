#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, INF = 1e18;
int tr[N][3], c[N], a[N], n, k, q;
int p[3][N], mod[4];
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
	for(int i = 0; i <= n + 1; i++) {
		for(int j = 1; j <= 2; j++) {
			tr[i][j] = 0;
		}
	}
}
long long RandLL(long long L, long long R) {
    return (rand() * rand()) % (R - L + 1) + L;
}
int lowbit(int x) {return x & (-x);}
int ksm(int x, int y, int Mod) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % Mod;
		x = x * x % Mod;
		y >>= 1;
	}
	return ans;
}
void add(int x, int y, int t) {
	while(x <= n) {
		tr[x][t] += y;
		tr[x][t] %= mod[t];
		x += lowbit(x);
	}
}
int query(int x, int t) {
	int ans = 0;
	while(x) {
		ans += tr[x][t];
		ans %= mod[t];
		x -= lowbit(x);
	}
	return ans;
}
void solve() {
	std::cin >> n >> q >> k;
	for(int i = 1; i <= n; i++) std::cin >> a[i];
	for(int i = 1; i <= n; i++) std::cin >> c[i];
	mod[1] = 998244353;
	mod[2] = 1000000007;
	for(int i = 1; i <= 2; i++) {
		int sum = 0;
		for(int j = 0; j <= k - 2; j++) {
			p[i][j] = RandLL(0, mod[i] - 1);
			sum = (sum + p[i][j]) % mod[i];
		}
		p[i][k - 1] = mod[i] - sum;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 2; j++) {
			int now = a[i] * p[j][c[i]] % mod[j];
			add(i, now, j);
		}
	}
	for(int i = 1; i <= q; i++) {
		int op; std::cin >> op;
		if(op == 1) {
			int px, x, cx;
			std::cin >> px >> x >> cx;
			for(int j = 1; j <= 2; j++) {
				int now = a[px] * p[j][c[px]] % mod[j];
				add(px, -now, j);
				now = x * p[j][cx] % mod[j];
				add(px, now, j);
			}
			a[px] = x; c[px] = cx;
		}
		else {
			int l, r, f = true;
			std::cin >> l >> r;
			for(int j = 1; j <= 2; j++) {
				int s = query(r, j) - query(l - 1, j);
				s = (s % mod[j] + mod[j]) % mod[j];
				if(s) f=  false;
			}
			if(f) std::cout << "YES\n";
			else std::cout << "NO\n";
		}
	}
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	srand(time(0));
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
