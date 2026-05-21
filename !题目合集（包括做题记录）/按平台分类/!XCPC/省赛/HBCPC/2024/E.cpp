#include<bits/stdc++.h>
#define int long long
#define y1 y1x
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, k, b, e, x1, x2, x3, x4, y1, y2, y3, y4;
double f[3100][3100];
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
int calc(int x, int y) {
	if(x % y == 0) return x / y;
	return x / y + 1;
}
double getd(double sx, double sy, double tx, double ty) {
	double ans = sqrt((sx - tx) * (sx - tx) + (sy - ty) * (sy - ty));
	return ans;
}
void solve() {
	n = read(), m = read(), k = read();
	b = read(), e = read();
	int maxn = std::max(calc(n, b), calc(m, e));
	x1 = read(), y1 = read();
	x2 = read(), y2 = read();
	x3 = read(), y3 = read();
	x4 = read(), y4 = read();
	double s1n = getd(x1, y1, x4, y4);
	double s2n = getd(x2, y2, x4, y4);
	double s3n = getd(x3, y3, x4, y4);
	double s12 = getd(x1, y1, x2, y2);
	double s13 = getd(x1, y1, x3, y3);
	double s23 = getd(x2, y2, x3, y3);
	for(int i = 0; i <= k; i++) {
		for(int j = 0; j <= maxn; j++) {
			f[i][j] = 10000000000000000;
		}
	}
	f[0][0] = 0;
	int cnt = 0;
	for(int i = 1; i <= k; i++) {
		int sx = read(), sy = read();
		double s1 = getd(sx, sy, x1, y1);
		double s2 = getd(sx, sy, x2, y2);
		double s3 = getd(sx, sy, x3, y3);
		double sn = getd(sx, sy, x4, y4);
		double minn = std::min({s1 + s1n, s2 + s2n, s3 + s3n});
		for(int j = 0; j <= maxn; j++) {
			f[i][j] = std::min(f[i][j], f[i - 1][j]);
			if(j < 1) continue;
			f[i][j] = std::min(f[i][j], f[i - 1][j - 1] + minn);
		}
		minn = std::min({s1 + s12 + s2n, s1 + s13 + s3n, s2 + s23 + s3n, s2 + s12 + s1n, s3 + s13 + s1n, s3 + s23 + s2n});
		for(int j = 0; j <= maxn; j++) {
			if(j < 2) continue;
			f[i][j] = std::min(f[i][j], f[i - 1][j - 2] + minn);
		}
		minn = std::min({s1 + s12 + s23 + s3n, s1 + s13 + s23 + s2n, s2 + s12 + s13 + s3n, s2 + s23 + s13 + s1n, s3 + s13 + s12 + s2n, s3 + s23 + s12 + s1n});
		for(int j = 0; j <= maxn; j++) {
			if(j < 3) continue;
			f[i][j] = std::min(f[i][j], f[i - 1][j - 3] + minn);
		}		
	}
	printf("%.10lf", f[k][maxn]);
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
