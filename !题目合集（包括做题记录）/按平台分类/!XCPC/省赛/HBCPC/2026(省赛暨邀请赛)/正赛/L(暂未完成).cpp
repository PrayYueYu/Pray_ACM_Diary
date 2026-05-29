#include<bits/stdc++.h>
#define int long long
#define double long double
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
double pi = acosl(-1.0L);
int n, k;
double ans;
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
struct Dot {
	int x, y;
	double tan, r;
} s[N];
double getr(double x, double y) {
	return sqrt(x * x + y * y);
}
bool cmp(Dot x, Dot y) {
	if(x.tan == y.tan) {
		double r1 = getr(x.x, x.y);
		double r2 = getr(y.x, y.y);
		return r1 < r2;
	}
	return x.tan < y.tan;
}
double calc(double x) {
	int now = 0, cnt = 0, f = false;
	double ar = 100000.0l;
	double ans = 100000000000.0L;
	for(int i = 1; i <= 2 * n; i++) {
		if(s[i].r > x) continue;
		if(now < i) now = i - 1, cnt = 0;
		while(true) {
			if(cnt >= k || now == 2 * n) break;
			now++;
			if(s[now].r > x) continue;
			cnt++;
		}
		if(cnt == k) {
//			std::cout << now << ' ';
//			std::cout << s[i].tan << ' ' << s[now].tan << '\n';
			ar = std::min(ar, s[now].tan - s[i].tan);
			f = true;
		}
		cnt--;
	}
	if(f) ans = std::min(ans, x * x * ar / 2.0);
	return ans;
}
void solve() {
	n = read(), k = read();
	ans = 10000000000.0L;
	for(int i = 1; i <= n; i++) {
		s[i].x = read(), s[i].y = read();
		s[i].tan = atan2((double)s[i].y, (double)s[i].x);
		s[i].r = getr(s[i].x, s[i].y);
	}
	std::sort(s + 1, s + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		s[i + n].x = s[i].x;
		s[i + n].y = s[i].y;
		s[i + n].tan = s[i].tan + 2 * pi;
		s[i + n].r = s[i].r;
	}
	double l = 0, r = 5000000.0l;
	double eps = 1e-12;
	while(r - l > eps) {
		double lmid = l + (r - l) / 3.0l;
		double rmid = r - (r - l) / 3.0l;
		if(calc(lmid) > calc(rmid)) l = lmid;
		else r = rmid;
	}
	printf("%.12Lf\n", std::min(calc(l), calc(r)));
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
1
5 3
2000 0
0 2000
1 1
-2 -2
100 100

*/
