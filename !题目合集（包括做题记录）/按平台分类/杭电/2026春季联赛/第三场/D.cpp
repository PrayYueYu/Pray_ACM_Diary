#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;

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
	int cnt, id;
} s[N];
bool cmp(S x, S y) {
	return x.cnt > y.cnt;
}
void solve() {
	int n = read(), k = read();
	for(int i = 1; i <= n; i++) {
		s[i].id = i;
		for(int j = 1; ; j++) {
			int now = i * j;
			if(now == i) continue;
			if(now > n) break;
			s[now].cnt++;
			s[i].cnt++;
		}
	}
	std::sort(s + 1, s + n + 1, cmp);
	std::cout << s[k].cnt << '\n';
	for(int i = 1; i <= n; i++) {
		s[i].cnt = 0;
	}
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
