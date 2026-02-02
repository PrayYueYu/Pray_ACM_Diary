#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 2e6 + 200, INF = 2e18;
int n, m, ne[N], to[N], fi[N], w[N], num;
int d[300005][2], vis[300005];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void add(int u, int v, int c) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
	w[num] = c;
}
priority_queue<pair<int, int>> q;
void dij(int s, int t) {
	for(int i = 1; i <= n; i++) {
		d[i][t] = INF;
		vis[i] = false;
	}
	d[s][t] = 0;
	q.push({0, s});
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = fi[u]; i; i = ne[i]) {
			int v = to[i];
			if(d[v][t] > max(d[u][t], w[i])) {
				d[v][t] = max(d[u][t], w[i]);
				q.push({-d[v][t], v});
			}
		}
	}
} 
signed main() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read(), c = read();
		add(u, v, c);
		add(v, u, c);
	}
	dij(1, 0);
	dij(n, 1);
	int ans = INF;
	//枚举最大边即可不用求次大边 
	for(int i = 1; i <= n; i++) {
		for(int j = fi[i]; j; j = ne[j]) {
			int v = to[j];
			if(d[i][0] <= w[j] && d[v][1] <= w[j]) {
				ans = min(ans, w[j] + max(d[i][0], d[v][1]));
			}
		}
	}
	for(int i = fi[1]; i; i = ne[i]) {
		int v = to[i];
		if(v == n) {
			ans = min(ans, w[i]);
		}
	}
	cout << ans;
    return 0;
}
/*

*/
