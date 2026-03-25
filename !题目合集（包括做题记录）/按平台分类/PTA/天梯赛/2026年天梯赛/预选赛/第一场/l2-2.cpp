#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int ans[N], n;
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
std::map<int, int> vis;
void solve() {
	n = read();
	std::priority_queue<int> q1, q2;
	for(int i = 1; i <= n; i++) {
		int x = read();
		if(x >= 0) q1.push(x);
		else q2.push(-x);
	}
	int cnt = 0;
	while(!q1.empty()) {
		int x = q1.top(); q1.pop();
		if(vis[x]) {
			vis[x]--;
			continue;
		}
		ans[++cnt] = x / 5;
		vis[(x / 5) * 2]++;
		vis[x / 5]++;
	}
	while(!q2.empty()) {
		int x = -q2.top(); q2.pop();
		if(vis[x]) {
			vis[x]--;
			continue;
		}
		ans[++cnt] = x / 5;
		vis[(x / 5) * 2]++;
		vis[x / 5]++;
	}
	std::sort(ans + 1, ans + cnt + 1);
	for(int i = cnt; i >= 1; i--) {
		std::cout << ans[i];
		if(i != 1) std::cout << ' ';
	}
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
