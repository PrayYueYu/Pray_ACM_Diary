#include<bits/stdc++.h>
#define int long long
#define ll long long
const int N = 200 + 10, mod = 1000000007;
int n, m, a[N][N][N], c[N][N], now[N][N], b[N][N], cnt[22];
bool ans[22][5000005];
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
ll RandLL(ll L, ll R) {
    return std::uniform_int_distribution<ll>(L, R)(rng);
}
void Matrix_Mul(int id) {
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			c[i][j] = 0;
		}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				c[i][j] = (c[i][j] + now[i][k] * a[id][k][j]) % mod;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			now[i][j] = c[i][j];
		}
	}
}
bool solve(int Minn, int Maxn, int Minm, int Maxm, bool f) {
	n = RandLL(Minn, Maxn);
	m = RandLL(Minm, Maxm);
	std::cout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) now[i][j] = 1;
			else now[i][j] = 0;
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				a[i][j][k] = RandLL(0, mod - 1);
				std::cout << a[i][j][k] << ' ';
			}
			std::cout << '\n';
		}
		Matrix_Mul(i);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(!f) b[i][j] = RandLL(0, mod - 1);
			else b[i][j] = now[i][j];
			std::cout << b[i][j] << ' ';
		}
		std::cout << '\n';
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(b[i][j] != now[i][j]) return false;
		}
	}
	return true;
}
signed main() {
	for(int tt = 1; tt <= 1; tt++) {
		std::string s = std::to_string(tt) + ".in";
		freopen(s.c_str(), "w", stdout);
		
		int Maxn = 0, Maxm = 0, Minn = 1, Minm = 1, T = 0;
		if(tt == 1) {
			Minn = Maxn = 200;
			Minm = Maxm = 12;
			T = 10;
		}
		else if(tt == 2) {
			Minn = Maxn = 150;
			Minm = Maxm = 150;
			T = 1;
		}
		else if(tt <= 10) {
			Minn = 1, Minm = 1;
			Maxn = 10, Maxm = 10;
			T = 5000;
		}
		else if(tt <= 15) {
			Minn = 1, Minm = 1;
			Maxn = 50, Maxm = 50;
			T = 40;
		}
		else {
			Minn = 1, Minm = 1;
			Maxn = 100, Maxm = 100;
			T = 5;
		}
		cnt[tt] = T;
		std::cout << T << '\n';
		for(int i = 1; i <= T; i++) {
			bool f = RandLL(0, 1);
			ans[tt][i] = solve(Minn, Maxn, Minm, Maxm, f);
		}
	}
	for(int tt = 1; tt <= 1; tt++) {
		std::string s = std::to_string(tt) + ".out";
		freopen(s.c_str(), "w", stdout);
		for(int i = 1; i <= cnt[tt]; i++) {
			if(ans[tt][i]) std::cout << "YES\n";
			else std::cout << "NO\n";
		}
	}
	return 0;
}
/*
	Writer: ÔÂö§Þ±‹¬ 
*/
