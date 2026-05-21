#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n;
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
struct S {
	int l, r, d, id;
};
struct cmp {
	bool operator()(const S&x, const S&y) {
		return x.r > y.r;
	}
};
std::priority_queue<S, std::vector<S>, cmp> q;
std::vector<std::pair<int, int>> v[N];
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		int l = read(), r = read();
		v[l].push_back({r, i});
	}
	int now = 0;
	std::vector<int> ans;
	while(true) {
		for(auto x: v[now]) {
			int l = now;
			int r = x.first;
			q.push({l, r, r - l + 1, x.second});
		}
		int f = false;
		while(!q.empty()) {
			auto p = q.top();
			int l = p.l, r = p.r, id = p.id;
			q.pop();
			if(l <= now && now <= r) {
				f = true;
				ans.push_back(id);
				now++;
				break;
			}
		}
		if(!f) break;
	}
	std::cout << now << '\n';
	for(auto x: ans) std::cout << x << ' ';
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
