#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, k, p, m;
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
	int a, p;
} s[N], t[N];
void solve() {
	n = read(), k = read(), p = read(), m = read();
	for(int i = 1; i <= n; i++) {
		s[i].a = read();
		s[i].p = 0;
	}
	s[p].p = 1;
	int now = 0, ans = 0;
	while(true) {
		int minn = INF, id = 0, flag = false;
		for(int i = 1; i <= k; i++) {
			if(minn > s[i].a) {
				minn = s[i].a;
				id = i;
			}
			if(s[i].p) flag = i;
		}
		if(flag) {
			id = flag;
			minn = s[id].a;
		}
		if(now + s[id].a > m) break;
		now += s[id].a;
		if(flag) ans++;
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(i != id) t[++cnt] = s[i];
		}
		t[++cnt] = s[id];
		for(int i = 1; i <= n; i++) s[i] = t[i];
	}
	std::cout << ans << '\n';
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
