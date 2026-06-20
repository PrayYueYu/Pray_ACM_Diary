#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], b[N], vis[N], flag, rin[N], visa[N];
int ne[N], to[N], fi[N], num;
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
std::vector<int> v[N];
int cnt, now[N];
void init() {
	cnt = 0;
	for(int i = 0; i <= n + 1; i++) {
		v[i].clear();
		now[i] = 0;
		fi[i] = 0;
		vis[i] = visa[i] = false;
		rin[i] = 0;
	}
	for(int i = 0; i <= num + 2; i++) {
		ne[i] = to[i] = 0;
	}
	num = 0;
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void dfs1(int u) {
	vis[u] = true;
	if(visa[b[u]]) {
		flag = false;
		return;
	}
	visa[b[u]] = true;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(b[v] && b[v] != a[b[u]]) {
			flag = false;
			return;
		}
		if(!b[v]) b[v] = a[b[u]];
		if(vis[v]) return;
		dfs1(v);
	}
}
void dfs2(int u, int S) {
	visa[u] = true;
	cnt++;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == S) return;
		dfs2(v, S);
	}
}
void dfs3(int u, int S) {
	rin[u] = cnt;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == S) return;
		dfs3(v, S);
	}
}
void dfs4(int u, int S) {
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == S) return;
		b[v] = a[b[u]];
		dfs4(v, S);
	}
}
void dfs5(int u, int S) {
	vis[u] = true;
	cnt++;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == S) return;
		dfs5(v, S);
	}	
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		add(i, a[i]);
	}
	for(int i = 1; i <= n; i++) {
		b[i] = read();
		if(b[i] == -1) b[i] = 0;
	}
	flag = true;
	for(int i = 1; i <= n; i++) {
		if(b[i] && !vis[i]) {
			dfs1(i);
		}
	}
	if(!flag) {
		std::cout << "NO\n";
		return;
	}
	for(int i = 1; i <= n; i++) vis[i] = false;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			cnt = 0;
			dfs5(i, i);
			dfs3(i, i);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!visa[i]) {
			cnt = 0;
			dfs2(i, i);
			v[cnt].push_back(i);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!b[i]) {
			b[i] = v[rin[i]][now[rin[i]]];
			now[rin[i]]++;
			dfs4(i, i);
		}
	}
	std::cout << "YES\n";
	for(int i = 1; i <= n; i++) std::cout << b[i] << ' ';
	std::cout << '\n';
}
signed main() {
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
