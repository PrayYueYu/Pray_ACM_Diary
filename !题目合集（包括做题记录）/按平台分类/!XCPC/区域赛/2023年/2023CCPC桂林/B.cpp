#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e9 + 10;
int n, m, a[N], b[N], ans[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
priority_queue<int> q;
multiset<int> s;
void solve() {
	n = read(), m = read();
	if(n < m) {
		cout << "-1\n";
		return;
	}
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) b[i] = read();
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	int f = true, num = 0;
	for(int i = 1; i <= m; i++) {
		int x = i + n - m;
		if(a[x] > b[i]) f = false;
		num += b[i] - a[x];
	}
	if(!f || (n == m && num)) {
		cout << -1 << endl;
		return;
	}
	if(n == m) {
		cout << 0 << endl;
		return;
	}
	if(num > n - m) {
		cout << -1 << endl;
		return;
	}
	int cnt = 0, k = 0, p = 0;
	s.clear();
	for(int i = n - m + 1; i <= n; i++) {
		s.insert(a[i]);
	}
	while(!q.empty()) q.pop();
	for(int i = 1; i <= n - m; i++) {
		q.push(-a[i]);
	}
	int us = 0;
	while(!q.empty()) {
		if(us == n - m - num || us == n - m) break;
		int x = -q.top();
		q.pop();
		ans[++cnt] = x;
		x++;
		int now = x;
		if(x > (*s.begin())) {
			now = (*s.begin());
			s.erase(s.begin());
			s.insert(x);
			num--;
		}
		q.push(-now);
		q.pop();
		us++;
	}
	int t = 1;
	for(auto x: s) {
		if(x > b[t]) {
			f = false;
			break;
		}
		int now = x;
		while(true) {
			if(now == b[t]) break;
			ans[++cnt] = now++;
		}
		t++;
	}
	if(!f) {
		cout << -1 << endl;
		return;
	}
	cout << cnt << endl;
	for(int i = 1; i <= cnt; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;;
}
signed main() {
	int T = read();
	while(T--) {
		solve();
	}
	return 0;
}
/*

*/
