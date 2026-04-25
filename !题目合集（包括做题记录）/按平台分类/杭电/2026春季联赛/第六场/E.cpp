#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int n, k, a[N];
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
void solve() {
	n = read(), k = read();
	for(int i = 1; i <= n + k; i++) {
		a[i] = 0;
	}
	std::stack<std::pair<int, int>> st;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	st.push({a[1], 1ll});
	int now = 2;
	while(true) {
		if(now > n) break;
		if(st.empty()) {
			st.push({a[now], 1});
			now++;
			continue;
		}
		int x = st.top().first;
		int y = st.top().second;
		
		if(a[now] == x) {
			if(y + 1 >= k) {
				while(!st.empty()) {
					if(st.top().first != x) break;
					st.pop();
				}
				now++;
			}
			else {
				st.push({x, y + 1});
				now++;
			}
		}
		else {
			st.push({a[now], 1});
			now++;
		}
	}
	std::vector<int> ans;
	while(!st.empty()) {
		ans.push_back(st.top().first);
		st.pop();
	}
	std::reverse(ans.begin(), ans.end());
	std::cout << ans.size() << '\n';
	for(auto x: ans) std::cout << x << ' ';
	std::cout << '\n';
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

*/
