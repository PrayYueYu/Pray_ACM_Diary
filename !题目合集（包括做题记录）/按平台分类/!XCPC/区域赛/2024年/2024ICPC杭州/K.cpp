#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 2e6 + 10, M = 1e9 + 7, INF = 1e18;
int n, m, k, a[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

signed main() {
	int T = read();
	while(T--) {
		n = read(), m = read(), k = read();
		int tot = 0;
		vector<vector<int>> v;
		v.resize(n + 5);
		for(int i = 1; i <= n; i++) {
			v[i].push_back(0);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				a[++tot] = read();
				int x = (a[tot] - 1) / m + 1;
				v[x].push_back(tot);
			}
		}
		int ans = INF;
		for(int i = 1; i <= n; i++) {
			int t = max(m - k, 0ll);
			int now = v[i][t];
			now = max(now, m);
			ans = min(ans, now);
		}
		cout << ans << endl;
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
