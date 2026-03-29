#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m;
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
	int a, b;
} s[N];
bool cmp(S x, S y) {
	if(x.b == y.b) return x.a > y.a;
	return x.b > y.b;
}
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ans;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        print(-x);
        return;
    }
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		s[i].a = read(), s[i].b = read();
	}
	std::sort(s + 1, s + n + 1, cmp);
	int nd = 0, ans = 0, las = s[1].b;
	int Max = 2000000000000000;
	for(int i = 1; i <= n; i++) {
		if(nd) {
			if(las - s[i].b >= 50) break;
			int f = true;
			for(int j = 1; j <= las - s[i].b; j++) {
				nd *= 2ll;
				if(nd > Max) {
					f = false;
					break;
				}
			}
			if(!f) break;
			las = s[i].b;
			if(s[i].a > nd) {
				s[i].a -= nd;
				nd = 0;
			}
			else {
				nd -= s[i].a;
				continue;
			}
		}
		int s1 = s[i].a % m, s2 = m - s1;
		if(!s1) {
			int x = s[i].a / m;
			int y = x * ksm(2, s[i].b); y %= mod;
			ans = (ans + y) % mod;
			nd = 0;
			continue;
		}
		int x = (s[i].a - s1) / m;
		int y = (x + 1) * ksm(2, s[i].b); y %= mod;
		ans = (ans + y) % mod;
		nd = s2;
		las = s[i].b;
	}
	std::cout << ans << '\n';
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
2
5 1
3 0
2 3
3 1
1 3
2 1
*/
