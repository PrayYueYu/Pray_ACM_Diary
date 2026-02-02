#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e6 + 9;
int n, xa, xb, ya, yb, vis[20][20];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
bool check(int x, int y) {
	if(x < 1 || y < 1 || x > 9 || y > 10) return false;
	if(vis[x][y]) return false;
	return true;
}
void solve() {
	xa = read(), ya = read();
	xb = read(), yb = read();
	vis[xb][yb] = true;
	queue<pair<int, int>> q;
	if(check(xa - 1, ya)) {
		if(check(xa - 2, ya - 1)) q.push({xa - 2, ya - 1});
		if(check(xa - 2, ya + 1)) q.push({xa - 2, ya + 1});
	}
	if(check(xa + 1, ya)) {
		if(check(xa + 2, ya - 1)) q.push({xa + 2, ya - 1});
		if(check(xa + 2, ya + 1)) q.push({xa + 2, ya + 1}); 
	}
	if(check(xa, ya - 1)) {
		if(check(xa - 1, ya - 2)) q.push({xa - 1, ya - 2});
		if(check(xa + 1, ya - 2)) q.push({xa + 1, ya - 2});
	}
	if(check(xa, ya + 1)) {
		if(check(xa - 1, ya + 2)) q.push({xa - 1, ya + 2});
		if(check(xa + 1, ya + 2)) q.push({xa + 1, ya + 2});
	}
	int f = false;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x != xb && y != yb) f = true;
	}
	if(!f) cout << "YES\n";
	else cout << "NO\n";
	vis[xb][yb] = false;
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = read();
	while(T--) solve();
    return 0;
}
