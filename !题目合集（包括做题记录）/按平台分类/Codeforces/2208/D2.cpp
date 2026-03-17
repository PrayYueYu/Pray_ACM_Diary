#include<bits/stdc++.h>
const int N = 1e4 + 10, mod = 998244353, INF = 1e9;
int n, fa[N], cnt[N];
int num, to[N], fi[N], ne[N];
int fx[N][N], f[N][N], vis[N];
std::string s[N];
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
std::set<int> p[N];
void init() {
	for(int i = 0; i <= n + 1; i++) {
		for(int j = 0; j <= n + 1; j++) {
			fx[i][j] = f[i][j] = 0;
		}
		p[i].clear();
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
void dfs(int S, int u) {
	fx[S][u] = true;
	vis[u] = true;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(vis[v]) continue;
		dfs(S, v);
	}
}
bool check(std::vector<std::pair<int, int>> d) {
	for(auto x: d) {
		int u = x.first, v = x.second;
		add(u, v);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			vis[j] = false;
		}
		dfs(i, i);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(f[i][j] != fx[i][j]) return false;
		}
	}
	return true;
}
void solve() {
	n = read();
	int flag = true;
	std::queue<int> q;
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
		std::cin >> s[i];
		for(int j = 0; j < n; j++) {
			if(s[i][j] == '0') {
				if(j + 1 == i) {
					flag = false;
				}
			}
			else cnt[i]++; 
			f[i][j + 1] = s[i][j] - '0';
		}
		if(cnt[i] == 1) {
			q.push(i);
		}
	}
	if(!flag) {
		std::cout << "No\n";
		return;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			if(s[i][j - 1] == '1' && s[j][i - 1] == '1') {
				std::cout << "No\n";
				return;
			}
		}
	}
	
	int edge = 0;
	std::vector<std::pair<int, int>> ans;
	for(int i = 1; i <= n; i++) {
		while(true) {
			int maxn = -INF, id = 0;
			for(int j = 1; j <= n; j++) {
				if(i == j) continue;
				if(s[i][j - 1] == '1') {
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
				if(f[id][j] == 1) s[i][j - 1] = '0';	
			}
			ans.push_back({i, id});
			s[i][id - 1] = '0';
			merge(i, id);
		}
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
		std::cout << x.first << ' ' << x.second << '\n';
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
/*
1
4
1000
0110
0010
1111
*/
