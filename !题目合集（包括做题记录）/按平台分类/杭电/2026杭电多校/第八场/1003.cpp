#include<bits/stdc++.h>
#define int long long
const int mod = 998244353, N = 1e5 + 10;
int n, q, f[320][2 * N];
int invfac[2 * N], fac[2 * N];
int ksm(int x, int y) {
	int ansx = 1;
	while(y) {
		if(y & 1) ansx = ansx * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ansx;
}
void pre() {
	fac[0] = fac[1] = 1;
	for(int i = 2; i <= 2 * N - 1; i++) fac[i] = fac[i - 1] * i % mod;
	invfac[2 * N - 1] = ksm(fac[2 * N - 1], mod - 2);
	for(int i = 2 * N - 2; i >= 0; i--) {
		invfac[i] = (i + 1) * invfac[i + 1] % mod;
	}
}
int calc(int x, int k) {
    int t = std::max(0ll, n - (x + k) + 1);
    int ansx = (f[k][n + k] - f[k][x] * f[k][n - x + 1] % mod + mod) % mod;
    return ansx;
}
int C(int x, int y) {
	if(y > x) return 0;
	int ansx = fac[x];
	ansx = ansx * invfac[y] % mod;
	ansx = ansx * invfac[x - y] % mod;
	return ansx;
}
int calcx(int x, int k) {
	int ansx = 0;
	for(int t = 1; t <= (x - 1) / k + 1; t++) {
		ansx = (ansx + C(x - (k - 1) * (t - 1), t)) % mod;
	}
	return (ansx + 1) % mod;
}
void solve() {
	std::cin >> n >> q;
    for(int k = 1; k <= sqrt(n); k++) {
    	f[k][1] = 1;
        for(int i = 2; i <= n + k; i++){
	    	int t = std::max(0ll, i - k);
	        f[k][i] = (f[k][i - 1] + f[k][t]) % mod;
	    }
	}
    for(int i = 1; i <= q; i++) {
    	int x, k;
        std::cin >> x >> k;
        if(k <= std::sqrt(n)) {
        	std::cout << calc(x, k) << '\n';
		}
		else {
		    int t = std::max(0ll, n - (x + k) + 1);
			int L = std::max(0ll, x - k);
			int R = std::max(0ll, n - x - k + 1); 
			int ansx = calcx(n, k) - calcx(L, k) * calcx(R, k) % mod;
			ansx = (ansx % mod + mod) % mod;
			std::cout << ansx << '\n';
		}
    }
}
signed main(){
    std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	pre();
	int T = 1;
    std::cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
