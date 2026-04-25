#include<bits/stdc++.h>
#define int long long
const int N = 1e3 + 10, mod = 998244353, INF = 1e18;
int n, m, sx, sy, tx, ty, ct, c[10], vis[7][7][N][N];
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
void solve() {
	n = read(), m = read();
	std::vector<int> v;
	v.push_back(0);
	for(int i = 1; i <= 6; i++) {
		c[i] = read();
		v.push_back(i);
	}
	int sx = read(), sy = read(), tx = read(), ty = read();
	int ct = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int s1 = 1; s1 <= 6; s1++) {
				for(int s2 = 1; s2 <= 6; s2++) {
					vis[s1][s2][i][j] = INF;
				}
			}
		}
	}
	std::queue<std::pair<std::vector<int>, std::pair<int, int>>> q;
	q.push({v, {sx, sy}});
	vis[v[6]][v[2]][sx][sy] = 0;
	//下面，前面，坐标
	while(!q.empty()) {
		auto vx = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		int op1 = vx[6], op2 = vx[2];
		std::vector<int> v1, v2, v3, v4;
		v1 = v2 = v3 = v4 = vx;
		v1[1] = vx[2], v1[2] = vx[6], v1[6] = vx[5], v1[5] = vx[1];
		v2[1] = vx[5], v2[2] = vx[1], v2[5] = vx[6], v2[6] = vx[2];
		v3[1] = vx[3], v3[3] = vx[6], v3[4] = vx[1], v3[6] = vx[4];
		v4[1] = vx[4], v4[3] = vx[1], v4[4] = vx[6], v4[6] = vx[3];
		if(x - 1 >= 1 && vis[v1[6]][v1[2]][x - 1][y] > vis[op1][op2][x][y] + 1) {
			q.push({v1, {x - 1, y}});
			vis[v1[6]][v1[2]][x - 1][y] = vis[op1][op2][x][y] + 1;
		}
		if(x + 1 <= n && vis[v2[6]][v2[2]][x + 1][y] > vis[op1][op2][x][y] + 1) {
			q.push({v2, {x + 1, y}});
			vis[v2[6]][v2[2]][x + 1][y] = vis[op1][op2][x][y] + 1;
		}
		if(y - 1 >= 1 && vis[v3[6]][v3[2]][x][y - 1] > vis[op1][op2][x][y] + 1) {
			q.push({v3, {x, y - 1}});
			vis[v3[6]][v3[2]][x][y - 1] = vis[op1][op2][x][y] + 1;
		}
		if(y + 1 <= m && vis[v4[6]][v4[2]][x][y + 1] > vis[op1][op2][x][y] + 1) {
			q.push({v4, {x, y + 1}});
			vis[v4[6]][v4[2]][x][y + 1] = vis[op1][op2][x][y] + 1;
		}
	}
	int ans = INF;
	for(int i = 1; i <= 6; i++) {
		if(c[i] == ct) {
			for(int j = 1; j <= 6; j++) {
				if(i == j) continue;
				ans = std::min(ans, vis[i][j][tx][ty]);
			}
		}
	}
	if(ans != INF) std::cout << ans << '\n';
	else std::cout << -1 << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
