#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, r, g, b, ans[N];
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
struct Lam {
	int w;
	char c;
} s[10];
bool cmp(Lam x, Lam y) {
	return x.w > y.w;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= 3; i++) s[i].w = read();
	s[1].c = 'R'; s[2].c = 'G', s[3].c = 'B';
	int gy = s[2].w, by = s[3].w, ry = s[1].w;
	std::sort(s + 1, s + 3 + 1, cmp);
	g = gy = s[1].w;
	r = ry = s[3].w;
	b = by = s[2].w;
	int f = true;
	for(int i = 1; i <= m; i++) {
		int L = read(), R = read();
		if(R - L + 1 > g + b) {
			f = false;
		}
		else {
			if(R - L + 1 > b && f == 1) {
				for(int j = L; j <= R; j++) {
					if(by) ans[j] = 2, by--;
					else if(gy) ans[j] = 1, gy--;
				}
				f = 2;
			}
			if(R - L + 1 > r && R - L + 1 <= b && f == 1) {
				for(int j = L; j <= R; j++) {
					if(ry) ans[j] = 3, ry--;
					else if(by) ans[j] = 2, by--;
				}
				f = 2;
			}
		}
	} 
	if(!f) {
		std::cout << -1 << '\n';
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(ans[i]) continue;
		if(gy) ans[i] = 1, gy--;
		else if(by) ans[i] = 2, by--;
		else ans[i] = 3, ry--;
	}
	for(int i = 1; i <= n; i++) {
		std::cout << s[ans[i]].c;
	}
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
