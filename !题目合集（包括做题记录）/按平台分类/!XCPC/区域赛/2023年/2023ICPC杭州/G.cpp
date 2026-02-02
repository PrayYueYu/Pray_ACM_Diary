#include<bits/stdc++.h>
#define ll long long
#define int long long 
using namespace std;
const int N = 3e3 + 200, INF = 2e18;
int n, m, k, a[N][N], d[N][N], vis[N][N], visx[N][N];
int dx[10] = {0, 1, -1, 0, 0};
int dy[10] = {0, 0, 0, 1, -1};
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct Dot {
	int x, y;
} sn[100005];
priority_queue<pair<int, pair<int, int>>> q;
bool check(int x, int y) {
	if(x < 1 || y < 1) return true;
	if(x > n || y > m) return true;
	return false;
}
void solve() {
	n = read(), m = read(), k = read();
	for(int i = 1; i <= k; i++) {
		sn[i].x = read();
		sn[i].y = read();
		a[sn[i].x][sn[i].y] = 2;
		vis[sn[i].x][sn[i].y] = k - i + 1;
	}
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++) {
			int t = 0;
			d[i][j + 1] = INF;
			if(a[i][j + 1] == 2) continue;
			if(s[j] == '#') t = 1;//ÕÏ°­ 
			a[i][j + 1] = t;
		}
	}
	q.push({0, {sn[1].x, sn[1].y}});
	d[sn[1].x][sn[1].y] = 0;
	while(!q.empty()) {
		auto u = q.top();
		int x = u.second.first, y = u.second.second;
		int w = -u.first;
		q.pop();
		if(visx[x][y]) continue;
		visx[x][y] = true;
		for(int i = 1; i <= 4; i++) {
			int sx = x + dx[i];
			int sy = y + dy[i];
			if(check(sx, sy)) continue;
			if(a[sx][sy] == 1) continue;
			if(a[sx][sy] == 2) {
				if(d[x][y] + 1 < vis[sx][sy]) {
					if(d[sx][sy] > vis[sx][sy]) {
						d[sx][sy] = vis[sx][sy];
						q.push({-d[sx][sy], {sx, sy}});
					}
					continue;
				}
				
			}
			if(d[sx][sy] > d[x][y] + 1) {
				d[sx][sy] = d[x][y] + 1;
				q.push({-d[sx][sy], {sx, sy}});
			}
		}
	}
	unsigned long long ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(d[i][j] == INF) d[i][j] = 0;
			ans += (unsigned ll)(d[i][j] * d[i][j]);
		}
	}
	cout << ans;
}
signed main() {
	int T = 1; 
	while(T--) {
		solve();
	}
    return 0;
}
