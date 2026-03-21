#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int to[2000], n, r[N], sum[4][N], tox[2000];
std::stack<int> st[2000];
std::string s;
int read() {
	int x;
	std::cin >> x;
	return x;
}
void solve() {
	to['('] = 1;
	to['['] = 2;
	to['{'] = 3;
	tox[')'] = 1;
	tox[']'] = 2;
	tox['}'] = 3;
	std::cin >> n;
	std::cin >> s;
	for(int i = 0; i < 2 * n; i++) {
		int x = to[s[i]];
		if(x) {
			st[x].push(i);
		}
		else {
			int y = tox[s[i]];
			r[st[y].top()] = i;
			st[y].pop();
		}
		if(i) {
			sum[1][i] = sum[1][i - 1] + (x == 1? 1: 0);
			sum[2][i] = sum[2][i - 1] + (x == 2? 1: 0);
			sum[3][i] = sum[3][i - 1] + (x == 3? 1: 0);
		}
	}
	int maxn = -INF, L = 0, R = 0;
	for(int i = 0; i < 2 * n; i++) {
		int x = to[s[i]];
		if(!x) continue;
		int cnt1 = sum[x][r[i] - 1] - sum[x][i];
		int cnt2 = 0;
		for(int j = 1; j <= 3; j++) {
			if(j == x) continue;
			cnt2 += sum[j][r[i] - 1] - sum[j][i];
		}
		if(cnt1 - cnt2 > maxn) {
			maxn = cnt1 - cnt2;
			L = i, R = r[i];
		}
	}
	std::cout << maxn << ' ' << L + 1 << ' ' << R + 1;
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

