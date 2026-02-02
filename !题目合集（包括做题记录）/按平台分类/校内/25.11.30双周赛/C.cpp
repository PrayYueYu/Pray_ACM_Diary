#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 1e9 + 7;
int n, a[N], vis[N];
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
priority_queue<pair<int, int>> q;
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		q.push({-a[i], i});
		vis[i] = false;
	}
	int x = q.top().second;
	vis[x] = true;
	cout << x << ' ' << -q.top().first << '\n';
	q.pop();
	int l = x, r = x;
	while(!q.empty()) {
		int x = q.top().second;
		q.pop();
		if(vis[x]) continue;
		
		if(x < l) {
			for(int i = l - 1; i >= x; i--) {
				cout << "L " << a[i] - a[r] << '\n';
				vis[i] = true;
			}
			l = x;
		}
		else {
			for(int i = r + 1; i <= x; i++) {
				cout << "R " << a[i] - a[l] << '\n';
				vis[i] = true;
			}
			r = x;
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = read();
	while(T--) solve();
	return 0;
}

/*

*/
