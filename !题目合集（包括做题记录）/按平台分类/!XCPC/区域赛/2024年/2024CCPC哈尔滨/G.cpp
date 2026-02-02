#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 100;
int n, vis[N];
int m, k, a[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
queue<int> q;
vector<int> p[N], ans[N];
void solve() {
	n = read(), m = read(), k = read();
	for(int i = 1; i <= k; i++) {
		a[i] = read();
		vis[a[i]] = true;
	}
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		if(!vis[u]) {
			p[u].push_back(v);
		}
		if(!vis[v]) {
			p[v].push_back(u);
		}
	}
	int id = 0;
	for(int i = 1; i <= n; i++) {
		if(!id) {
			if(!vis[i]) id = i;
		}
		vis[i] = false;
	}
	if(!id) {
		cout << "No\n";
		return;
	}
	q.push(id);
	vis[id] = true;
	int num = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		int f = false;
		for(auto v: p[u]) {
			if(vis[v]) continue;
			vis[v] = true;
			if(!f) {
				f = true, num++;
				ans[num].push_back(u);
			}
			ans[num].push_back(v);
			q.push(v);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
	cout << num << endl;
	for(int i = 1; i <= num; i++) {
		cout << ans[i][0] << " " << ans[i].size() - 1 << " ";
		for(int j = 1; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
