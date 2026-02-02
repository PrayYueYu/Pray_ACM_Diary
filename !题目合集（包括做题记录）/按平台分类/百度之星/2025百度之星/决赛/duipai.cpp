#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 100, INF = 2e18;
int ans, vis[N], a[N], b[N], n, fx;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void dfs(int t) {
	if(t == n + 1) {
		int sum = 0, ansx = 0;
		for(int i = 2; i <= n; i++) {
			sum += b[vis[i - 1]];
			if(sum == a[vis[i]]) {
				ansx++;
				if(a[vis[i]] == 4 && i == 5) {
					fx++;
					for(int j = 1; j <= n; j++) {
						cout << b[vis[j]] << ' ';
					}cout << '\n';
				}
			}
		}
//		fx++;
//		for(int i = 1; i <= n; i++) {
//			cout << vis[i] << ' ';
//		}
//		cout << " | " << ansx << '\n';
		ans += ansx;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		vis[i] = t;
		dfs(t + 1);
		vis[i] = false;
	}
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) b[i] = read();
	dfs(1);
	cout << ans;
	cout << endl << fx;
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
