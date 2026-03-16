#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, d, a[N], b[N], now[N], ans;
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
std::priority_queue<std::pair<int, int>> q;
void solve() {
	n = read(), d = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) b[i] = read();
	std::sort(a + 1, a + n + 1);
	std::sort(b + 1, b + n + 1);
	for(int i = n; i >= 1; i--) {
		q.push({-(a[1] - b[i]), i});
		now[i] = 1;
	}
	while(!q.empty()) {
		int x = -q.top().first; 
		int id = q.top().second;
		q.pop();
		if(d >= x) {
			d -= x;
			now[id]++;
			ans++;
			if(now[id] <= n) {
				q.push({-(a[now[id]] - b[id]), id});
			}
		}
		else break;
	}
	std::cout << ans << ' ' << d;
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
