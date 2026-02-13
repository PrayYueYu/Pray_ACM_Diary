#include<bits/stdc++.h>
#define re register
const int N = 4e5 + 10, mod = 998244353, INF = 1e9;
int dis[N], d[N], vis[N], r[N], f[N], n, m;
int num, fi[N], to[N], ne[N];
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
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
std::map<int, int> mp;
std::queue<std::pair<int, int>> q;
void solve() {
	n = read(), m = read();
	for(re int i = 1; i <= m; i++) {
		int u = read(), v = read();
		add(u, v); add(v, u);
		d[u]++, d[v]++;
	}
	for(re int i = 1; i <= n; i++) {
		r[i] = d[i];
	}
	std::sort(r + 1, r + n + 1);
	int cnt = 0;
	for(re int i = 1; i <= n; i++) {
		if(!mp[r[i]]) mp[r[i]] = ++cnt;
	}
	for(re int i = 1; i <= n; i++) {
		d[i] = mp[d[i]];
		r[i] = mp[r[i]];
		f[i] = INF;
	}
	for(re int i = cnt; i >= 1; i--) {
		for(re int j = 1; j <= n; j++) {
			if(d[j] == i) q.push({j, 0});
		}
		while(!q.empty()) {
			int u = q.front().first;
			int dis = q.front().second;
			q.pop();
			if(vis[u] == i) continue;
			vis[u] = i;
			
			for(re int j = fi[u]; j; j = ne[j]) {
				int v = to[j];
				if(vis[v] == i) continue;
				if(d[v] < i) {
					q.push({v, dis + 1});
					f[v] = std::min(f[v], dis + 1);
				}
			}
		}
	}
	for(re int i = 1; i <= n; i++) {
		if(f[i] == INF) std::cout << -1 << ' ';
		else std::cout << f[i] << ' ';
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
