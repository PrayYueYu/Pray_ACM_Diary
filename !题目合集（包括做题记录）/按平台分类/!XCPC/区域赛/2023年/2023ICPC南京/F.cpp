#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 4e6 + 100, M = 1e9 + 7, INF = 1e9; 
int n, m, f[N], ans[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
priority_queue<int> q;
void init() {
	for(int i = 0; i <= m + 10; i++) f[i] = 0;
	while(!q.empty()) q.pop();
}

void solve() {
	n = read(), m = read();
	vector<vector<int>> v;
	v.resize(m + 10);
	for(int i = 1; i <= n; i++) {
		int num = read();
		for(int j = 1; j <= num; j++) {
			int x = read();
			v[x].push_back(i);
		}
	}
	vector<vector<int>> to;
	to.resize(n + 5);
	for(int i = 1; i <= m; i++) {
		sort(v[i].begin(), v[i].end());
		int sz = v[i].size() - 1;
		for(int j = 0; j < sz; j++) {
			to[v[i][j]].push_back(v[i][sz]);
			f[v[i][sz]]++;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!f[i]) q.push(i);
	}
	int tot = 0;
	while(!q.empty()) {
		int u = q.top();
		q.pop();
		ans[++tot] = u;
		for(int i = 0; i < to[u].size(); i++) {
			int v = to[u][i];
			f[v]--;
			if(!f[v]) q.push(v);
		}
	}
	int F = false;
	for(int i = 1; i <= n; i++) {
		if(ans[i] != i) F = true;
	}
	if(!F) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
	for(int i = 1; i <= n; i++) {
		cout << ans[i];
		if(i != n) cout << " ";
	}
	cout << endl;
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

*/
