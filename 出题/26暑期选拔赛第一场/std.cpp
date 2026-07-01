#include<bits/stdc++.h>
#define int long long
const int N = 1e3 + 10, mod = 998244353, INF = 1e18;
bool a[N][N][2], vis[N][N][2];
int dx[10] = {0, 1, -1, 0, 0};
int dy[10] = {0, 0, 0, 1, -1};
int n, m;
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
std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>> q;
void init() {
	for(int i = 0; i <= n + 2; i++) {
		for(int j = 0; j <= m + 2; j++) {
			vis[i][j][0] = vis[i][j][1] = 0;
			a[i][j][0] = a[i][j][1] = 0;
		}
	}
}
void solve() {
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		std::string s = "";
		std::cin >> s;
		for(int j = 0; j < m; j++) {
			a[i][j + 1][0] = (s[j] == '.'? 0: 1);
		}
	}
	for(int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		for(int j = 0; j < m; j++) {
			a[i][j + 1][1] = (s[j] == '.'? 0: 1);
		}
	}
	q.push({{1, 1}, {0, 0}});
	vis[1][1][0] = true;
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int now = q.front().second.first;
		int used = q.front().second.second;
		int nex = now ^ 1; q.pop();
		if(!used && !a[x][y][nex] && !vis[x][y][nex]) {
			q.push({{x, y}, {nex, 1}});
			vis[x][y][nex] = true;
		}
		for(int i = 1; i <= 4; i++) {
			int sx = x + dx[i];
			int sy = y + dy[i];
			if(sx < 1 || sy < 1 || sx > n || sy > m) continue;
			if(a[sx][sy][nex]) continue;
			if(vis[sx][sy][nex]) continue;
			q.push({{sx, sy}, {nex, used}});
			vis[sx][sy][nex] = true;
		}
	}
	if(vis[n][m][1]) std::cout << "YES\n";
	else std::cout << "NO\n";
}
signed main() {
	int T;
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
	Writer: ÔÂö§Þ±‹¬ 
*/
