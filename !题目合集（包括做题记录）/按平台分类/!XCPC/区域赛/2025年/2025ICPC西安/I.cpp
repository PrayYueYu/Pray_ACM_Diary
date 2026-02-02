#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3 + 100, INF = 1e18;
int n, a[N][N], ru[N], vis[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
queue<pair<int, int>> q;
vector<int> p[N];
int calc(int u, int v) {
	if(u > v) swap(u, v);
	return a[u][v];
}
void dfs(int u, int fa) {
	for(auto v: p[u]) {
		if(vis[v]) continue;
		ru[v]--;
	}
	for(auto v: p[u]) {
		if(vis[v]) continue;
		if(!ru[v]) {
			vis[v] = true;
			q.push({u, v});
			dfs(v, u);
		}
	}
}
signed main() {
	n = read(); int num = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			a[i][j] = read();
			a[j][i] = a[i][j];
		}
	}
	for(int i = 2; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int x = calc(1, i) ^ calc(i, j) ^ calc(1, j);
			//cout << i << " " << j << " " << x << endl;
			if(x != i && x != j) continue;
			if(x == i) {
				p[i].push_back(j);
				ru[j]++;
			}
			else {
				p[j].push_back(i);
				ru[i]++;
			}
		}
	}
	for(int i = 2; i <= n; i++) {
		p[1].push_back(i);
		ru[i]++;
	}
	vis[1] = true;
	dfs(1, 0);
	while(!q.empty()) {
		auto ans = q.front();
		q.pop();
		cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}
