#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 100;
int n, k, q;
int num, ne[N], to[N], fi[N];
int dfn[N], scc[N], vis[N], low[N], cntx, top, tot, st[N];

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
void init() {
	for(int i = 0; i <= num; i++) {
		ne[i] = to[i] = 0;
	}
	num = 0;
	for(int i = 1; i <= n; i++) {
		dfn[i] = low[i] = vis[i] = scc[i] = fi[i] = 0;
	}
	top = cntx = tot = 0;
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	vis[x]=1;st[++top]=x;
	for(int i=fi[x];i;i=ne[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v])low[x]=min(low[x],dfn[v]);
	}
	int temp;
	if(low[x]==dfn[x])
	{
        ++cntx;//一定要从0开始加，这样才是拓扑序
		while((temp=st[top--]))
        {
            vis[temp]=0;
            scc[temp]=cntx;//此处scc为连通块编号
            if(x==temp)break;
        }
	}
}
int calc(int l, int r) {
	int len = r - l + 1;
	if(len == 1) return 0;
	return ((len - 1) * len) / 2;
}
void solve() {
	n = read(), k = read(), q = read();
	vector<vector<int>> a, sum, L, R;
	a.resize(k + 5, vector<int>(n + 5, 0));
	sum.resize(k + 5, vector<int>(n + 5, 0));
	L.resize(k + 5, vector<int>(n + 5, 0));
	R.resize(k + 5, vector<int>(n + 5, 0));
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= n; j++) {
			a[i][j] = read();
			if((j - 1)) add(a[i][j - 1], a[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) tarjan(i);
	}
	scc[0] = -1;
	for(int i = 1; i <=  k; i++) {
		for(int j = 1; j <= n; j++) {
			if(scc[a[i][j]] != scc[a[i][j - 1]] || j == 1) {
				L[i][j] = j;
				sum[i][j] = sum[i][j - 1];
			}
			else {
				L[i][j] = L[i][j - 1];
				sum[i][j] = sum[i][L[i][j] - 1] + calc(L[i][j], j);
			}
		} 
	}
	for(int i = 1; i <= k; i++) {
		for(int j = n; j >= 1; j--) {
			if(scc[a[i][j]] != scc[a[i][j + 1]] || j == n) {
				R[i][j] = j;
			}
			else R[i][j] = R[i][j + 1];
		}
	}
	int ans = 0;
	for(int i = 1; i <= q; i++) {
		int id = read(), l = read(), r = read();
		id = ((id + ans) % k) + 1;
		l = ((l + ans) % n) + 1;
		r = ((r + ans) % n) + 1;
		if(scc[a[id][l]] == scc[a[id][r]]) {
			ans = calc(l, r);
			cout << ans << '\n';
			continue;
		}
		ans = sum[id][L[id][r] - 1] - sum[id][R[id][l]];
		ans += calc(l, R[id][l]);
		ans += calc(L[id][r], r);
		cout << ans << '\n';
	}
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
