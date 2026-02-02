#include<bits/stdc++.h>
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e3 + 10, M = 1e9 + 7;
int n, m, k, vis[N][N];
int dx[10] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
int dy[10] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
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
bool check(int x, int y) {
	if(x < 1 || y < 1 || x > n || y > m) return false;
	return true;
}
void solve() {
	n = read(), m = read(), k = read();
	for(int i = 1; i <= k; i++) {
		int x = read(), y = read();
		vis[x][y] = 3;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int tot = i % 2;
		for(int j = 1; j <= m; j++) {
			if(!vis[i][j]) vis[i][j] = tot % 2;
			tot++;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int k = 1; k <= 8; k++) {
				int sx = i + dx[k];
				int sy = j + dy[k];
				if(check(sx, sy) && vis[sx][sy] != vis[i][j]) {
					ans++;
				}
			}
		}
	}
	cout << ans / 2 << '\n';
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			vis[i][j] = false;
		}
	}
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}

/*

*/
