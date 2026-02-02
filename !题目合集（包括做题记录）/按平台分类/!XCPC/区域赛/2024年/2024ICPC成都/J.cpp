#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 6e5 + 100, M = 998244353, INF = 2e18;
int n, ans[N], vis[N], m, q;
int visx[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void init() {
	for(int i = 1; i <= n; i++) {
		visx[i] = false;
	}
	for(int i = 1; i <= m; i++) {
		vis[i] = ans[i] = 0;
	}
}
struct Print {
	int sc, id;
} s[N];
bool cmp(Print x, Print y) {
	if(x.sc == y.sc) return x.id < y.id;
	return x.sc > y.sc;
}
void solve() {
	n = read(), m = read(), q = read();
	int now = -1, sc = m;
	vector<int> v;
	for(int i = 1; i <= q; i++) {
		int op = read();
		int x, id = 0;
		if(op == 1) {
			x = read();
			if(visx[x]) continue;
			visx[x] = true;
			if(v.size()) {
				for(auto u: v) {
					vis[u] = false;
				} 
				v.clear();
			}
			now = x;
			sc = m;
		}
		else if(op == 2) {
			id = read();
			x = read();
			if(x != now) continue;
			if(vis[id]) continue;
			v.push_back(id);
			vis[id] = true;
			ans[id] += sc--;
		}
		else {
			id = read();
			x = read();
			if(x != now) continue;
			if(vis[id]) continue;
			v.push_back(id);
			vis[id] = true;
		}
	}
	int sum = 0;
	for(int i = 1; i <= m; i++) {
		s[i].id = i;
		s[i].sc = ans[i];
	}
	sort(s + 1, s + m + 1, cmp);
	for(int i = 1; i <= m; i++) {
		cout << s[i].id << ' ' << s[i].sc << '\n';
	}
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
