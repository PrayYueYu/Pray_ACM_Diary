#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e6 + 100, M = 998244353, INF = 1e18; 
int n, m;
int dx[10] = {0, 1, -1, 0, 0};
int dy[10] = {0, 0, 0, 1, -1};
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
vector<vector<int>> a, vis;
queue<pair<pair<int, int>, int>> q;
bool check(int x, int y) {
	if(x < 1 || y < 1) return false;
	if(x > n || y > m) return false;
	return true;
}
signed main() {
	//freopen("1.in", "r", stdin);
	n = read(); m = read();
	a.resize(n + 5, vector<int>(m + 5));
	vis.resize(n + 5, vector<int>(m + 5));
	for(int i = 1; i <= n; i++) {
		string s; cin >> s;
		s = " " + s;
		for(int j = 1; j <= m; j++) {
			a[i][j] = (s[j] == '.'? 0: 1);
			if(a[i][j]) q.push({{i, j}, 1});
			vis[i][j] = a[i][j];
		}
	}
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int w = q.front().second;
		q.pop();
		for(int i = 1; i <= 4; i++) {
			int sx = x + dx[i];
			int sy = y + dy[i];
			if(!check(sx, sy)) continue;
			if(vis[sx][sy]) continue;
			int num = 0;
			for(int j = 1; j <= 4; j++) {
				int ssx = sx + dx[j];
				int ssy = sy + dy[j];
				if(!check(ssx, ssy)) continue;
				if(vis[ssx][ssy] && vis[ssx][ssy] <= w) num++;
			}
			if(num != 1) continue;
			vis[sx][sy] = w + 1;
			q.push({{sx, sy}, w + 1});
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(vis[i][j]) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
