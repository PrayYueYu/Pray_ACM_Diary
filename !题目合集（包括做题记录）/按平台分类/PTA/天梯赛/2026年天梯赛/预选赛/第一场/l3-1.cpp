#include<bits/stdc++.h>
#define int long long
const int N = 2e3 + 10, mod = 998244353, INF = 1e18;
int dx[10] = {0, -1, 1, 0, 0};
int dy[10] = {0, 0, 0, -1, 1};
int n, m, a[N][N], d[N][N];
std::pair<int, int> fr[N][N];
std::queue<std::pair<int, int>> q;
std::vector<int> ans;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int getstep(int x, int y, int sx, int sy) {
	if(x == sx) {
		if(y < sy) return 3;
		else return 4;
	}
	else {
		if(x < sx) return 1;
		else return 2;
	}
}
void solve() {
	n = read(), m = read();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			a[i][j] = read();
		}
	}
	q.push({0, 0});
	d[0][0] = 1;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
//		std::cout << x << ' ' << y << '\n';
		q.pop();
		for(int i = 1; i <= 4; i++) {
			int sx = x + dx[i];
			int sy = y + dy[i];
			if(sx < 0 || sy < 0 || sx >= n || sy >= m) continue;
			if(!a[sx][sy]) continue;
			if(d[sx][sy]) continue;
			d[sx][sy] = d[x][y] + 1;
			fr[sx][sy] = {x, y};
			q.push({sx, sy});
		}
	}
	if(!d[n - 1][m - 1]) {
		std::cout << "Just Monika";
		return;
	}
	int x = n - 1, y = m - 1;
	while(true) {
		if(!x && !y) break;
		ans.push_back(getstep(x, y, fr[x][y].first, fr[x][y].second));
		int sx = fr[x][y].first;
		int sy = fr[x][y].second;
		x = sx, y = sy;
	}
	for(int i = ans.size() - 1; i >= 0; i--) {
		std::cout << ans[i];
	}
	std::cout << '\n';
	std::cout << d[n - 1][m - 1] - 1;
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
