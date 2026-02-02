#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7, INF = 1e18;
int ne[N], to[N], fi[N], num, w[N];
int n, m, k, cnt[N];
int f[N][22], dep[N], wx[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
void add(int u, int v, int c) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
	w[num] = c;
}
void dfs1(int u, int fa) {
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for(int i = 1; i <= 20; i++) {
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs1(v, u);
		wx[v] = w[i];
	}
}
void dfs2(int u, int fa) {
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs2(v, u);
		cnt[u] += cnt[v];
	}
}
int lca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 20; i >= 0; i--) { //20对应log(1e6)
        if(dep[f[x][i]] >= dep[y]) {
            x = f[x][i];
        }
    }
    if(x == y) return x;//一定注意这里需要判断！！否则后面会出问题
    for(int i = 20; i >= 0; i--) {
        if(f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    //这里的x和y差一个相等，所以返回x的father
    return f[x][0];
}
priority_queue<pair<int, int>> q;
void solve() {
	n = read(), m = read(), k = read();
	for(int i = 1; i < n; i++) {
		int u = read(), v = read(), c = read();
		add(u, v, c); add(v, u, c);
	}
	dfs1(1, 0);
	int las = 1;
	for(int i = 1; i <= m; i++) {
		int now = read();
		cnt[now]++;
		cnt[las]++;
		cnt[lca(now, las)] -= 2; 
		las = now;
	}
	dfs2(1, 0);
	for(int i = 1; i <= n; i++) {
		if(cnt[i])
			q.push({cnt[i] * (wx[i] - wx[i] / 2), i});
	}
	for(int i = 1; i <= k; i++) {
		if(q.empty()) break;
		int s = q.top().first;
		int u = q.top().second;
		q.pop();
		wx[u] /= 2;
		if(wx[u])
			q.push({cnt[u] * (wx[u] - wx[u] / 2), u});
	}
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += cnt[i] * wx[i];
	}
	cout << sum;
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
