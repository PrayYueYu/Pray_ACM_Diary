#include<bits/stdc++.h>
#define int long long
#define ll long long
const int N = 2000 + 10, mod = 1000000007;
int a[N][N], b[N][N], now[N][2][N], c[N][N], n, m;
int B[N][2][N], rk[N][2][N];
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
ll RandLL(ll L, ll R) {
    return std::uniform_int_distribution<ll>(L, R)(rng);
}
int read() {
	int x = 0, f = 1; char ch = getchar();
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
void Mul_A(int id) {
	for(int i = 1; i <= n; i++) c[1][i] = 0;
	for(int i = 1; i <= n; i++) {
		for(int k = 1; k <= n; k++) {
			c[1][i] = (c[1][i] + now[id][1][k] * a[k][i]) % mod;
		}
	}
	for(int i = 1; i <= n; i++) now[id][1][i] = c[1][i];
}
void Mul_B(int id) {
	for(int i = 1; i <= n; i++) B[id][1][i] = 0;
	for(int i = 1; i <= n; i++) {
		for(int k = 1; k <= n; k++) {
			B[id][1][i] = (B[id][1][i] + rk[id][1][k] * b[k][i]) % mod;
		}
	}
}
void solve() {
	n = read(), m = read(); 
	for(int t = 1; t <= 5; t++) {
		for(int i = 1; i <= n; i++) {
			now[t][1][i] = RandLL(0, mod - 1);
			rk[t][1][i] = now[t][1][i];
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				a[j][k] = read();
			}
		}
		for(int t = 1; t <= 5; t++) {
			Mul_A(t);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			b[i][j] = read();
		}
	}
	int flag = true;
	for(int t = 1; t <= 5; t++) {
		Mul_B(t);
		for(int i = 1; i <= n; i++) {
			if(now[t][1][i] != B[t][1][i]) {
				flag = false;
				break;
			}
		}
	}
	if(flag) std::cout << "YES\n";
	else std::cout << "NO\n";
}
signed main() {
	freopen("1.in", "r", stdin);
	int T; 
	T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
	Writer: ÔÂö§Þ±‹¬ 
*/
