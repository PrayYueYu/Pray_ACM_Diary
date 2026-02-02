#include<bits/stdc++.h>
#define ll long long
#define int long long 
using namespace std;
const int N = 2e6 + 200, INF = 2e18, M = 1e9 + 7;
int n, a[N], b[N], w[N], ans[N];
int invfac[N], fac[N], ru[N];
int ne[N], to[N], fi[N], num;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void init() {
	for(int i = 0; i <= n + 5; i++) {
		fi[i] = ne[i] = to[i] = 0;
	}
	num = 0;
}
int ksm(int x, int y) {
	int ansx = 1;
	while(y) {
		if(y & 1) ansx = (ansx * x) % M;
		x = (x * x) % M;
		y >>= 1;
	}
	return ansx;
}
void pre() {
	fac[0] = 1;
	int Nx = N - 10;
	for(int i = 1; i <= Nx; i++) {
		fac[i] = (fac[i - 1] * i) % M;
	}
	invfac[Nx] = ksm(fac[Nx], M - 2);
	for(int i = Nx - 1; i >= 0; i--) {
		invfac[i] = (invfac[i + 1] * (i + 1)) % M;
	}
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void dfs(int u, int h) {
	ans[u] = (a[u] + invfac[h] * w[u] % M) % M;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		dfs(v, h + 1);
	}
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		ans[i] = 0;
		ru[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		b[i] = read();
	}
	for(int i = 1; i <= n; i++) {
		w[i] = read();
	}
	for(int i = 1; i <= n; i++) {
		if(b[i] == i) {
			ans[i] = a[i];
			continue;
		}
		if(a[b[i]] > a[i]) {
			ans[i] = a[i] + w[i];
			ans[i] %= M;
		}
		else if(a[b[i]] + w[b[i]] <= a[i]) {
			ans[i] = a[i];
		}
		else {
			add(b[i], i);
			ru[i]++;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!ru[i]) {
			if(ans[i] != a[i]) {
				dfs(i, 1);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!ans[i]) ans[i] = a[i];
	}
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
signed main() {
	pre();
	int T = read();
	while(T--) {
		solve();
		init();
	}
    return 0;
}
/*

*/
