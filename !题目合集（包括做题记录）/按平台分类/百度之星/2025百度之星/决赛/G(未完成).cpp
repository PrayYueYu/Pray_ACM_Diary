#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 100, INF = 2e18, mod = 1e9 + 7;
int n, x[N], y[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
map<int, set<int>> s1, s2, vis1;
queue<pair<int, int>> q;
void Flag(int x, int y) {
	vis1[x].insert(y);
//	vis2[y].insert(x);
}
bool check(int x, int y) {
	auto it = vis1[x].find(y);
	if(it == vis1[x].end()) return false;
	return true;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		x[i] = read(), y[i] = read();
		//vis[x[i]][y[i]] = true;
		s1[x[i]].insert(y[i]);
		s2[y[i]].insert(x[i]);
		
	}
	vis1[0].insert(0);
//	vis2[0].insert(0);
	int ans = 1;
	q.push({0, 0});
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
//		cout << x << ' ' << y << '\n';
		q.pop();
		auto it = s1[x].lower_bound(y);
		if(!check(x, y + 1)) {
			if(it != s1[x].end()) {
				int yx = (*it) - 1;
				if(!check(x, yx)) {
					Flag(x, yx);
					q.push({x, yx});
					ans++;
				}
			}
		}
		if(!check(x, y - 1)) {
			if(it != s1[x].begin()) {
				it--;
				int yx = (*it) + 1;
				if(!check(x, yx)) {
					Flag(x, yx);
					q.push({x, yx});
					ans++;
				}
			}
		}
		it = s2[y].lower_bound(x);
		if(!check(x + 1, y)) {
			if(it != s2[y].end()) {
				int xx = (*it) - 1;
				if(!check(xx, y)) {
					Flag(xx, y);
					q.push({xx, y});
					ans++;
				}
			}
		}
		if(!check(x - 1, y)) {
			if(it != s2[y].begin()) {
				it--;
				int xx = (*it) + 1;
				if(!check(xx, y)) {
					Flag(xx, y);
					q.push({xx, y});
					ans++;
				}
			}
		}
	}
	cout << (ans + 1) / 2;
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
