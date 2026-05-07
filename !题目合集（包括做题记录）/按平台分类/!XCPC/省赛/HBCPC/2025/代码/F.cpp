#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e6 + 10, INF = 1e13 + 7, M = 1e15;
int n, num, to[N], ne[N], fi[N], vis[N];
int L[N], fa[N], f[N / 2][30], a[N], dep[N];
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
void dfs(int u, int fa, int h) {
	L[a[u]] = u; vis[u] = true;
	dep[u] = h;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		if(vis[v]) continue;
		if(L[a[v] + 1]) f[v][0] = L[a[v] + 1];
		dfs(v, u, h + 1);
	}
	L[a[u]] = 0;
}
int main() {
	//freopen("1.in", "r", stdin);
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 2; i <= n; i++) {
		int v = read();
		add(i, v); add(v, i);
		fa[v] = i;
	}
	dfs(1, 0, 1);
	for(int j = 1; j <= 20; j++) {
		for(int i = 1; i <= n; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	int q = read();
	while(q--) {
		int s = read(), t = read();
		int now = s;
		while(true) {
			int F = false, p = 0;
			for(int i = 0; i <= 20; i++) {
				if(dep[f[now][i]] == dep[t]) {
					p = i;
					F = true;
					break;
				}
				else if(dep[f[now][i]] < dep[t]) {
					p = i - 1;
					break;
				}
			}
			if(p == -1) break;
			now = f[now][p];
		}
		int ans = a[now] - a[s] + 1;
		cout << ans << endl;
	}
	return 0;
}
/*

*/
