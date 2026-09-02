#include<bits/stdc++.h>
const int N = 5e5 + 10, M = 998244353, INF = 2e9;
int num = 1, ne[N], to[N], fi[N], w[N], n, m, vis[N], k;
int s, t, nowfi[N], h[N];
std::string sx[100000];
std::queue<int> q;
void init() {
	while(!q.empty()) q.pop();
	for(int i = 1; i <= n + k + 2; i++) {
		vis[i] = 0;
		nowfi[i] = fi[i];
		h[i] = 0;
	}
}
void add(int u, int v, int val) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
	w[num] = val;
	
	std::swap(u, v);
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
	w[num] = 0;
}
bool BFS() {
	vis[s] = true;
	h[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = fi[u]; i; i = ne[i]) {
			int v = to[i];
			if(w[i] <= 0) continue;
			if(vis[v]) continue; 
			h[v] = h[u] + 1;
			vis[v] = true;
			q.push(v);
			if(v == t) return true;
		}
	}
	return false;
}
int dfs(int u, int flow) {
	if(u == t) return flow;
	int sum = 0;
	for(int i = nowfi[u]; i; i = ne[i]) {
		int v = to[i];
		nowfi[u] = i;
		if(w[i] <= 0) continue;
		if(h[v] == h[u] + 1) {
			int now = dfs(v, std::min(flow - sum, w[i])); 
			w[i] -= now;
			w[i ^ 1] += now;
			sum += now;
			if(sum == flow) break;
		}
	}
	return sum;
}

void solve() {
	std::cin >> n >> k;
	s = 1, t = n + k + 2;
	for(int i = 1; i <= n; i++) std::cin >> sx[i];
	int l = 0, r = n / k + 1;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		num = 1;
		for(int i = 1; i <= n + k + 2; i++) {
			vis[i] = 0;
			nowfi[i] = 0;
			h[i] = 0;
			fi[i] = 0;
		}
		for(int i = 1; i <= n; i++) {
			add(1, i + 1, 1);
			for(int j = 0; j < k; j++) {
				if(sx[i][j] == '1') {
					add(i + 1, n + j + 2, 1);
				}
			}
		}
		for(int i = 1; i <= k; i++) add(n + 1 + i, t, mid);
		
		int ans = 0;
		while(true) {
			if(BFS()) ans += dfs(s, INF);
			else break;
			init();
		}
		if(ans == mid * k) l = mid;
		else r = mid - 1;
		
		for(int i = 0; i <= num + 2; i++) {
			w[i] = to[i] = ne[i] = 0;
		}
	}
	std::cout << l << '\n';
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
