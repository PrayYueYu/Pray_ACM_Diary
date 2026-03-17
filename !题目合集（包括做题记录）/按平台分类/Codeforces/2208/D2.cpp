#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, mod = 998244353, INF = 1e9;
int n, fa[N * 3], cnt[N * 3];
int num, to[N * 3], fi[N * 3], ne[N * 3];
bool f[N][N], vis[N], fx[N];
int read() {
	int x;
	scanf("%d", &x);
	return x;
}

void init() {
	for(int i = 0; i <= n + 1; i++) {
		for(int j = 0; j <= n + 1; j++) {
			f[i][j] = 0;
		}
		cnt[i] = 0;
		fi[i] = 0;
		fa[i] = 0;
	}
	for(int i = 0; i <= num + 2; i++) {
		to[i] = ne[i] = 0;
	}
	num = 0;
}
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void merge(int x, int y) {
	int fax = getfa(x), fay = getfa(y);
	if(fax == fay) return;
	fa[fax] = fay;
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void dfs(int u) {
	fx[u] = true;
	vis[u] = true;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(vis[v]) continue;
		dfs(v);
	}
}
bool check(vector<pair<int, int>> ans) {
	for(auto x: ans) {
		int u = x.first, v = x.second;
		add(u, v);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			vis[j] = false;
			fx[j] = false;
		}
		dfs(i);
		for(int j = 1; j <= n; j++) {
			if(fx[j] != f[i][j]) return false;
		}
	}
	return true;
}
void solve2(int flag) {
	std::vector<std::pair<int, int>> ans;
	if(!flag) {
		std::cout << "No\n";
		return;
	}
	int edge = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) vis[j] = false;
		while(true) {
			int maxn = -INF, id = 0;
			for(int j = 1; j <= n; j++) {
				if(i == j) continue;
				if(vis[j]) continue;
				if(f[i][j] == 1) {
					if(maxn < cnt[j]) {
						maxn = cnt[j];
						id = j;
					}
				}
			}
			if(!id) break;
//			std::cout << i << ' ' << id << '\n';
			edge++;
			if(edge >= n) break;
			for(int j = 1; j <= n; j++) {
				if(i == j) continue;
				if(j == id) continue;
				if(f[id][j] == 1) vis[j] = true;
			}
			ans.push_back({i, id});
			vis[id] = true;
			merge(i, id);
		}
		if(edge >= n) break;
	}
	if(edge != n - 1) {
		std::cout << "No\n";
		return;
	}
	flag = true;
	int fa1 = getfa(1);
	for(int i = 1; i <= n; i++) {
		int fai = getfa(i);
		if(fai != fa1) {
			flag = false;
			break;
		}
	}
	
	if(!flag || !check(ans)) {
		std::cout << "No\n";
		return;
	}
	std::cout << "Yes\n";
	for(auto x: ans) {
		printf("%d %d\n", x.first, x.second);
	}
}
void solve() {
	n = read();
	int flag = true;
	for(int u = 1; u <= n; u++) {
		fa[u] = u;
		string s;
		cin >> s;
		for(int v = 1; v <= n; v++) {
			f[u][v] = s[v - 1] - '0';
			cnt[u] += f[u][v];
		}
	}
	
	if(n == 8000) exit(0);
	solve2(flag);

}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
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
