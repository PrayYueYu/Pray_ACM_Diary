#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, fa[N], p[N], l[N], r[N], siz[N], sum[N];
int fmx[N], fmn[N];
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
void build() {
	int u = 1;
	for(int i = 2; i <= n; i++) {
		while(true) {
			if(p[u] > p[i]) {
				if(!fa[u]) {
					fa[u] = i;
					l[i] = u;
					u = i;
					break;
				}
				else u = fa[u];
			}
			else {
				int rs = r[u];
				r[u] = i;
				fa[i] = u;
				if(rs) {
					fa[rs] = i;
					l[i] = rs;
				}
				u = i;
				break;
			}
		}
	}
}
void dfs(int u) {
	if(l[u]) dfs(l[u]);
	if(r[u]) dfs(r[u]);
	siz[u] = siz[l[u]] + siz[r[u]] + 1;
	sum[u] = sum[l[u]] + sum[r[u]] + p[u];
	int tmx = fmx[l[u]] + fmx[r[u]] + p[u] * u;
	int tmn = fmn[l[u]] + fmn[r[u]] + p[u] * u;
	int L = u - siz[l[u]], R = u + siz[r[u]];
	fmx[u] = std::max(tmx, (L + R) * sum[u] - tmn);
	fmn[u] = std::min(tmn, (L + R) * sum[u] - tmx);
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) p[i] = read();
	build();
	int root = 0;
	for(int i = 1; i <= n; i++) {
		if(!fa[i]) root = i;
	}
	dfs(root); 
	std::cout << fmx[root] << ' ' << fmn[root];
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
6
4 3 1 5 2 6
*/
