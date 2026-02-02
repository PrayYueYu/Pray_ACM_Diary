#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
#define y2 y_2
#define y1 y_1
using namespace std;
const int N = 2e3 + 10, M = 1e9 + 7, INF = 1e18;
int n, x1, x2, y1, y2, f[N][N], vis[N][N];
int dx[10] = {0, 1, -1, 0, 0};
int dy[10] = {0, 0, 0, 1, -1};
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
queue<pair<int, pair<int, int>>> q;
void solve() {
	n = read(), x1 = read(), y1 = read();
	x2 = read(), y2 = read();
	for(int i = 1; i <= n; i++) {
		int x = read(), y = read();
		vis[x][y] = true;
	}
	for(int i = 0; i <= 1010; i++) {
		for(int j = 0; j <= 1010; j++) {
			f[i][j] = INF;
		}
	}
	q.push({0, {x1, y1}});
	f[x1][y1] = 0;
	while(!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		for(int i = 1; i <= 4; i++) {
			int sx = x + dx[i];
			int sy = y + dy[i];
			if(sx < 0 || sy < 0 || sx > 1010 || sy > 1010) continue;
			if(vis[sx][sy]) {
				if(f[sx][sy] > f[x][y] + 1) {
					f[sx][sy] = f[x][y] + 1;
					q.push({-f[sx][sy], {sx, sy}});
				}
			}
			else {
				if(f[sx][sy] > f[x][y]) {
					f[sx][sy] = f[x][y];
					q.push({-f[sx][sy], {sx, sy}});
				}
			}
		}
	}
	cout << f[x2][y2];
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
