#include<bits/stdc++.h>
#define int long long
#define ll long long
const int N = 200 + 10, mod = 1000000007;
int a[N][N][N], b[N][N], now[N][N], c[N][N], rk[N][N], n, m;
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
ll RandLL(ll L, ll R) {
    return std::uniform_int_distribution<ll>(L, R)(rng);
}
void Matrix_Mul(int id) {
	for(int i = 1; i <= n; i++) c[1][i] = 0;
	for(int i = 1; i <= n; i++) {
		for(int k = 1; k <= n; k++) {
			c[1][i] = (c[1][i] + now[1][k] * a[id][k][i]) % mod;
		}
	}
	for(int i = 1; i <= n; i++) now[1][i] = c[1][i];
}
bool check() {
	for(int i = 1; i <= n; i++) c[1][i] = 0;
	for(int i = 1; i <= n; i++) {
		for(int k = 1; k <= n; k++) {
			c[1][i] = (c[1][i] + rk[1][k] * b[k][i]) % mod;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(c[1][i] != now[1][i]) return false;
	}
	return true;
}
void solve() {
	std::cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				std::cin >> a[i][j][k];
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			std::cin >> b[i][j];
		}
	}
	int t = 5;
	bool flag = true;
	while(t--) {
		for(int i = 1; i <= n; i++) {
			now[1][i] = RandLL(0, mod - 1);
			rk[1][i] = now[1][i];
		}
		for(int i = 1; i <= m; i++) {
			Matrix_Mul(i);
		}
		if(!check()) {
			flag = false;
			break;
		}
	}
	if(flag) std::cout << "YES\n";
	else std::cout << "NO\n";
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
	Writer: ÔÂö§Þ±‹¬ 
*/
