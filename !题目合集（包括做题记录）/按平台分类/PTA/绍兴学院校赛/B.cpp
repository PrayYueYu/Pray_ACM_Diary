#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int n, sum[30], ans[30];
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
	std::string s;
	std::cin >> s;
	int n = s.size(), cnt = 0;
	s = " " + s;
	for(int i = 1; i <= n; i++) {
		if(sum[s[i] - 'A'] >= 1) cnt += ans[s[i] - 'A'];
		for(int j = 0; j < 26; j++) {
			ans[j] += sum[j];
		}
		sum[s[i] - 'A']++;
	}
	std::cout << cnt;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
