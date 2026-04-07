#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int n, m, st, vis[N];
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
	int l, r;
} s[N];
bool cmpr(S x, S y) {
	if(x.r == y.r) return x.l < y.l;
	return x.r < y.r;
}
bool cmpl(S x, S y) {
	if(x.l == y.l) return x.r > y.r;
	return x.l > y.l;
}
void solve() {
	n = read(), m = read(), st = read();
	for(int i = 1; i <= m; i++) {
		s[i].l = read();
		s[i].r = read();
		if(vis[s[i].l] == 1 || vis[s[i].l] == 0)
			vis[s[i].l] = 1;
		else vis[s[i].l] = 3;
		if(vis[s[i].r] == 2 || vis[s[i].r] == 0)
			vis[s[i].r] = 2;
		else vis[s[i].r] = 3;
	}
	std::sort(s + 1, s + m + 1, cmpl);
	int L = st, R = st;
	for(int i = 1; i <= m; i++) {
		if(s[i].l <= L && L <= s[i].r) {
			L = s[i].l;
		}
	}
	std::sort(s + 1, s + m + 1, cmpr);
	for(int i = 1; i <= m; i++) {
		if(s[i].l <= R && R <= s[i].r) {
			R = s[i].r;
		}
	}
	for(int i = L; i <= R; i++) {
		if(vis[i] == 3 && i != st) std::cout << i << ' ';
		if(vis[i] == 2 && i > st) std::cout << i << ' ';
		if(vis[i] == 1 && i < st) std::cout << i << ' ';
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
