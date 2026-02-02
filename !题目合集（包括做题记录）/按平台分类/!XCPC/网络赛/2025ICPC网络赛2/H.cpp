#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const ll N = 3e3 + 10, M = 998244353;
int n, num, to[N], ne[N], fi[N], f[N][30], dep[N], fac[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void dfs(int u, int fa) {
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for(int i = 1; i <= 13; i++) {
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs(v, u);
	}
}
int lca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 13; i >= 0; i--) { 
        if(dep[f[x][i]] >= dep[y]) {
            x = f[x][i];
        }
    }
    if(x == y) return x;
    for(int i = 13; i >= 0; i--) {
        if(f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
int solve(int x, int y) {
	int fa = lca(x, y);
	return dep[x] + dep[y] - 2 * dep[fa] + 1;
}
void init() {
	for(int i = 0; i <= num + 5; i++) {
		fi[i] = 0;
		ne[i] = 0;
		to[i] = 0;
	}
	num = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 13; j++) f[i][j] = 0;
		dep[i] = 0;
	}
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = read();
	fac[0] = 1;
	for(int i = 1; i <= N - 10; i++) {
		fac[i] = (fac[i - 1] * i) % M;
	}
	while(T--) {
		n = read();
		for(int i = 1; i < n; i++) {
			int u = read();
			int v = read();
			add(u, v);
			add(v, u);
			
		}
		dfs(1, 0);
		int ans = 1;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				int l = solve(i, j);
				ans = (ans + fac[l]) % M;
				ans = (ans - 2 * fac[l - 1] % M + M) % M;
				ans = (ans + fac[l - 2]) % M;
			}
		}
		cout << ans << endl;
		init();
	}
    return 0;
}
/*


*/
