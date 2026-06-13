#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, u[N], v[N], fa[N], m;
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
int getfa(int x) {
	if(fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % mod;
		x = x * x % mod;
		y >>= 1;
	} 
	return ans;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		u[i] = read(), v[i] = read();
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	int id = m + 1, cnt = n;
	for(int i = m; i >= 1; i--) {
		int fau = getfa(u[i]);
		int fav = getfa(v[i]);
		if(fau == fav) continue;
		if(cnt == 2) {
			id = i + 1;
			break;
		}
		cnt--;
		fa[fau] = fav;
	}
	int ans = 0;
	for(int i = 1; i < id; i++) {
		int fau = getfa(u[i]);
		int fav = getfa(v[i]);
		if(fau == fav) continue;
		ans += ksm(2, i); ans %= mod;
	}
	std::cout << ans << '\n';
	
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

*/
