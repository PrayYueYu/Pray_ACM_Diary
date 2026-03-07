#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], b[N], l[N], r[N], visl[N], visr[N];
int pos[N], d[N];
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
int get_tree(int l1, int r1, int l2, int r2) {
	if(l1 > r1 || l2 > r2) return -1;
	int root = b[r2], x = pos[root];
	int y = (x - l1) + l2 - 1;
	l[root] = get_tree(l1, x - 1, l2, y);
	r[root] = get_tree(x + 1, r1, y + 1, r2 - 1);
	return root;
}
void dfs_l(int u, int fa) {
	d[u] = d[fa] + 1;
	if(!visl[d[u]]) visl[d[u]] = u;
	if(l[u] >= 1) dfs_l(l[u], u);
	if(r[u] >= 1) dfs_l(r[u], u);
}
void dfs_r(int u, int fa) {
	if(!visr[d[u]]) visr[d[u]] = u;
	if(r[u] >= 1) dfs_r(r[u], u);
	if(l[u] >= 1) dfs_r(l[u], u);
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		pos[a[i]] = i;
	}
	for(int i = 1; i <= n; i++) b[i] = read();
	int s = get_tree(1, n, 1, n);
	dfs_l(s, 0);
	dfs_r(s, 0);
	std::cout << "R: ";
	for(int i = 1; i <= n; i++) {
		if(visr[i]) std::cout << visr[i] << ' ';
	}
	std::cout << "\nL: ";
	for(int i = 1; i <= n; i++) {
		if(visl[i]) std::cout << visl[i] << ' ';
	}
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
