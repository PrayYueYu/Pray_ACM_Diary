#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int sx, sy, sz, tx, ty, tz, n, m, a[N], b[N], c[N];
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
std::map<std::pair<int, int>, std::set<int>> mp;
std::map<std::pair<std::pair<int, int>, int>, int> vis;
void solve() {
	n = read(), m = read();
	sx = read(), sy = read(), sz = read();
	tx = read(), ty = read(), tz = read();
	mp.clear();
	vis.clear();
	for(int i = 1; i <= n; i++) {
		int x = read(), y = read(), z = read();
		mp[{x, y}].insert(-z); 
	}
	for(int i = 1; i <= m; i++) {
		a[i] = read(), b[i] = read(), c[i] = read();
	}
	std::queue<std::pair<std::pair<std::pair<int, int>, int> ,int>> q;
	q.push({{{sx, sy}, sz}, 0});
	vis[{{sx, sy}, sz}] = true;
	while(!q.empty()) {
		int x = q.front().first.first.first;
		int y = q.front().first.first.second;
		int z = q.front().first.second;
//		std::cout << x << ' ' << y << ' ' << z << '\n';
		int st = q.front().second;
		if(x == tx && y == ty && z == tz) {
			std::cout << st << '\n';
			return;
		}
		q.pop();
		for(int i = 1; i <= m; i++) {
			int dx = x + a[i];
			int dy = y + b[i];
			int dz = z + c[i];
			if(mp[{dx, dy}].size() == 0) continue;
			auto it = mp[{dx, dy}].lower_bound(-dz);
			if(it == mp[{dx, dy}].end()) continue;
			int p = -(*it);
			if(p == dz) continue;
			if(vis[{{dx, dy}, p + 1}]) continue;
			vis[{{dx, dy}, p + 1}] = true;
			q.push({{{dx, dy}, p + 1}, st + 1});
		}
	}
	std::cout << -1 << '\n';
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
2
6 4
3 3 3 5 5 5
3 3 2
5 5 4
5 5 7
4 5 5
2 3 2
4 1 1
-1 0 3
2 -2 -1
1 4 9
1 0 0
3 2
0 0 1 1 1 1
0 0 0
1 1 0
1 1 2
1 1 1
1 1 2

*/
