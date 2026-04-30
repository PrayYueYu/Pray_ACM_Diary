#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int a[N], n, r;
std::vector<int> ans;
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
void flip(int x, int op) {
	if(x == 1 || x == n || a[x - 1] != a[x + 1]) {
		a[x] ^= 1;
		ans.push_back(x);
		return;
	}
	if(!op) {
		flip(x - 1, op);
		a[x] ^= 1;
		ans.push_back(x);
		return;
	}
	else {
		flip(x + 1, op);
		a[x] ^= 1;
		ans.push_back(x);
	}
}
void solve() {
	n = read(), r = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	if(n == 1) {
		std::cout << 0;
		return;
	}
	int s1 = (1 + n) >> 1, s2 = s1 + 1;
	if(a[s1] != a[s2]) {
		flip(s1, 0);
	}
	s1--, s2++;
	while(true) {
		if(s1 <= 0) break;
		if(a[s1] != a[s1 + 1]) flip(s1, 0);
		s1--;
	}
	while(true) {
		if(s2 > n) break;
		if(a[s2] != a[s2 - 1]) flip(s2, 1);
		s2++;
	}
	std::cout << ans.size() << '\n';
	for(auto x: ans) std::cout << x << ' ';
}
signed main() {
//	freopen("1.in", "r", stdin);
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
