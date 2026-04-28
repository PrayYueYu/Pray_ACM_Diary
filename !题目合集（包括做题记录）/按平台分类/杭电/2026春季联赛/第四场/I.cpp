#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int p[40], f[N][22], maxn[N][22], a[N], b[N], n, q;
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
inline int getmax(int l, int r) {
	int t = log2(r - l + 1);
	return std::max(maxn[l][t], maxn[r - p[t] + 1][t]);
}
inline int getgcd(int l, int r) {
	int t = log2(r - l + 1);
	return std::__gcd(f[l][t], f[r - p[t] + 1][t]);
}
void solve() {
	n = read(), q = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
		f[i][0] = a[i];
	}
	for(int i = 1; i <= n; i++) {
		b[i] = read();
		maxn[i][0] = b[i];
//		sum[i] = sum[i - 1] + b[i];
	}
	for(int j = 1; j <= 20; j++) {
		for(int i = 1; i <= n; i++) {
			int ne = i + p[j - 1];
			if(ne > n) {
				ne = n + 1 - p[j - 1];
			}
			if(ne < 1) ne = 1;
			f[i][j] = std::__gcd(f[i][j - 1], f[ne][j - 1]);
			maxn[i][j] = std::max(maxn[i][j - 1], maxn[ne][j - 1]);
//			std::cout << i << ' ' << i + p[j] - 1 << ' ' << f[i][j] << '\n';
		}
	}
	for(int i = 1; i <= q; i++) {
		int l = read(), r = read();
		int sum = 0, ans = 0, nowL = l;
		while(true) {
			int L = nowL, R = r, gx = getgcd(nowL, r);
			while(L < R) {
				int mid = (L + R + 1) >> 1;
				if(getgcd(mid, r) == gx) L = mid;
				else R = mid - 1;
			}
			int MAX = getmax(nowL, L);
			if(sum < MAX) {
				int k = MAX - sum;
				if(k % gx == 0) {
					ans += k / gx;
					sum += k;
				}
				else {
					ans += k / gx + 1;
					sum += (k / gx + 1) * gx;
				}
			}
//			std::cout << ans << ' ' << nowL << ' ' << L << ' ';
//			std::cout << MAX << ' ' << sum << '\n';
			nowL = L + 1;
			if(nowL > r) break;
		}
		std::cout << ans << '\n';
	}
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	p[0] = 1;
	for(int i = 1; i <= 25; i++) p[i] = p[i - 1] * 2;
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
