#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3 + 100;
int vis[N * N], a[N][N], n, m;
int read() {
	int x = 0;
	scanf("%lld", &x);
	return x;
}
void solve() {
	n = read(), m = read();
	int tot = 0;
	for(int i  = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			a[i][j] = 0;
		}
	}
	tot = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j]) continue;
			int ix = i, jx = j;
			while(true) {
				a[ix][jx] = ++tot;
				ix++;
				jx--;
				if(ix > n || jx < 1) break;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m - 1; j++) {
			int t = a[i][j] + a[i][j + 1];
			if(vis[t]) {
				cout << "No\n";
				return;
			}
			vis[t] = true;
		}
	}
	for(int i = 1; i <= n - 1; i++) {
		for(int j = 1; j <= m; j++) {
			int t = a[i][j] + a[i + 1][j];
			if(vis[t]) {
				cout << "No\n";
				return;
			}
			vis[t] = true;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m - 1; j++) {
			int t = a[i][j] + a[i][j + 1];
			vis[t] = false;
		}
	}
	for(int i = 1; i <= n - 1; i++) {
		for(int j = 1; j <= m; j++) {
			int t = a[i][j] + a[i + 1][j];
			vis[t] = false;
		}
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
}
signed main(){
	int T = read();
	while(T--) {
		solve();
	}
	return 0;
}
