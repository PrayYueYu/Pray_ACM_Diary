#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 5e5 + 100, M = 998244353, INF = 1e16;
int n, f[200][200][3], q;
int read() {
	int x;
	cin >> x;
	return x;
}
struct S {
	int x, y, t, Min;
};
queue<S> qu;
bool check(int x, int y) {
	if(y - x > q && x) return false;
	return true;
}
signed main() {
	int x = read(), y = read();
	int p = read(); q = read();
	for(int i = 0; i <= x; i++) {
		for(int j = 0; j <= y; j++) {
			f[i][j][0] = f[i][j][1] = INF;
		}
	}
	f[x][y][0] = 0;
	S now = {x, y, 0, 0};
	qu.push(now);
	while(!qu.empty()) {
		now = qu.front();
		qu.pop();
		for(int i = 0; i <= p; i++) {
			for(int j = 0; j <= p - i; j++) {
				int nx = x - now.x + i;
				int ny = y - now.y + j;
				int nxx = now.x - i;
				int nyy = now.y - j;
				int nt = (now.t ^ 1);
				if(nx < 0 || ny < 0 || nxx < 0 || nyy < 0) continue;
				if(nx > x || ny > y || nxx > x || nyy > y) continue;
				if(check(nxx, nyy) && check(x - now.x, y - now.y)) {
					if(f[nx][ny][nt] > now.Min + 1) {
						f[nx][ny][nt] = now.Min + 1;
						qu.push({nx, ny, nt, now.Min + 1});
					}
				}
			}
		}
	}
	int ans = INF;
	for(int i = 0; i <= y; i++) {
		ans = min(ans, f[x][i][1]);
	}
	if(ans == INF) cout << -1 ;
	else cout << ans;
	return 0;
}
/*

*/
