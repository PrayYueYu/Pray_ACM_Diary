#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, fa[N], cnt[N];
bool f[N][N], vis[N];

char s[N];
int read() {
	int x;
	scanf("%d", &x);
	return x;
}std::vector<int> w[N];

int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void merge(int x, int y) {
	int fax = getfa(x), fay = getfa(y);
	fa[fay] = fax;
}
void dfs(int u) {
	vis[u] = true;
	for(auto v: w[u]) {
		if(vis[v]) continue;
		dfs(v);
	}
}
void solve() {
	n = read();	
	for(int i = 0; i <= n + 2; i++) {
		w[i].clear();
		cnt[i] = 0;
		vis[i] = false;
	}
	int flag = true;
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
		scanf("%s", s);
		for(int j = 1; j <= n; j++) {
			f[i][j] = s[j - 1] - '0';
			cnt[i] += f[i][j];
			if(i == j && !f[i][j]) flag = false;
		}
	}
	
	if(!flag) {
		cout << "No\n";
		return;
	}
	int edge = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) vis[j] = false;
		vis[i] = true;
		while(true) {
			if(edge == n) break;
			int maxn = -1, id = 0;
			for(int j = 1; j <= n; j++) {
				if(vis[j]) continue;
				if(!f[i][j]) continue;
				if(maxn < cnt[j]) {
					maxn = cnt[j];
					id = j;
				}
			}
			if(!id) break;
			w[i].push_back(id);
			edge++;
			merge(i, id);
			for(int j = 1; j <= n; j++) {
				if(i == j) continue;
				if(f[id][j]) vis[j] = true;
			}
		}
	}
	if(edge != n - 1) {
		cout << "No\n";
		return;
	}
	int fa1 = getfa(1);
	for(int i = 1; i <= n; i++) {
		if(getfa(i) != fa1) {
			cout << "No\n";
			return;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) vis[j] = false;
		dfs(i);
		for(int j = 1; j <= n; j++) {
			if(vis[j] != f[i][j]) {
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
	for(int i = 1; i <= n; i++) {
		for(auto x: w[i]) {
			cout << i << ' ' << x << '\n';
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = read();
	while(T--) {
		solve();
	}
	return 0;
}
/*
1
4
1000
0110
0010
1111
*/
