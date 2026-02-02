#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200, M = 1e9 + 7;
int n, m, a[N][N], b[N], vis[N], ans, fac[N];
int v[500000][50];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
map<vector<int>, bool> mp;
void dfs(int x) {
	if(x == m + 1) {
		int f = 0;
		vector<int> s;
		s.resize(n + 5);
		for(int i = 1; i <= m; i++) {
			if(!vis[i]) continue;
			if(!f) {
				for(int j = 1; j <= n; j++) {
					s[j] = a[i][j];
				}
				f = 1;
				continue;
			}
			for(int j = 1; j <= n; j++) b[j] = s[j];
			for(int j = 1; j <= n; j++) {
				s[j] = b[a[i][j]];
			}
		}
		if(!mp[s]) {
			mp[s] = true;
			ans++;
		}
		return;
	}
	vis[x] = true;
	dfs(x + 1);
	vis[x] = false;
	dfs(x + 1);
}
void bfs() {
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		int num = cnt;
		vector<int> c;
		c.resize(n + 5);
		for(int j = 1; j <= num; j++) {
			for(int k = 1; k <= n; k++) {
				c[k] = v[j][a[i][k]];
			}
			if(!mp[c]) {
				mp[c] = true;
				cnt++;
				ans++;
				for(int j = 1; j <= n; j++) 
					v[cnt][j] = c[j];
			}
		}
		for(int j = 1; j <= n; j++) c[j] = a[i][j];
		if(!mp[c]) {
			mp[c] = true;
			ans++;
			cnt++;
			for(int j = 1; j <= n; j++) v[cnt][j] = c[j];
		}
	}
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			a[i][j] = read();
		}
	}
	int f = 0;
	if(m >= 30) f = 2;
	else if(n >= 10) f = 1;
	else {
		int x = 1 << m, y = fac[n];
		if(x > y) f = 2;
		else f = 1;
	} 
	if(f == 1) {
		dfs(1);
		ans--;
	}
	else {
		bfs();
	}
	cout << ans;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	srand(time(0));
	int T = 1;
	while(T--) {
		fac[0] = 1;
		for(int i = 1; i <= 10; i++) fac[i] = fac[i - 1] * i;
		solve();
	}

	return 0;
} 
