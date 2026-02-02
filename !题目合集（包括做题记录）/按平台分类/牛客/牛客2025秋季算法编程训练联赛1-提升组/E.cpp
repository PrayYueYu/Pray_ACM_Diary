#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N = 2e5 + 100;
double pi = acos(-1.0), xs, ys;
int n, k;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
bool check(double x, double y) {
	if(x > 0 && y < 0) return true;
	if(x < 0 && y > 0) return true;
	return false;
}
struct P {
	double x, y, t;
} a[N], b[N];
bool cmp(P s1, P s2) {
	return s1.t < s2.t;
}
double calc(int op, int l, int r) {
	double ans = 0.0;
	if(op == 1) {
		double s1 = fabs(xs) / fabs(xs - a[l].x);
		double s2 = fabs(xs) / fabs(xs - a[r].x);
		s1 = s1 * fabs(ys - a[l].y);
		s2 = s2 * fabs(ys - a[r].y);
		if(a[l].y >= ys && a[r].y >= ys) ans = fabs(s1 - s2);
		else if(a[l].y <= ys && a[r].y <= ys) ans = fabs(s1 - s2);
		else ans = s1 + s2;
	}
	else {
		double s1 = fabs(ys) / fabs(ys - b[l].y);
		double s2 = fabs(ys) / fabs(ys - b[r].y);
		s1 = s1 * fabs(xs - b[l].x);
		s2 = s2 * fabs(xs - b[r].x);
		if(b[l].x >= xs && b[r].x >= xs) ans = fabs(s1 - s2);
		else if(b[l].x <= xs && b[r].x <= xs) ans = fabs(s1 - s2);
		else ans = s1 + s2;
	}
	return ans;
}
signed main() {
	cin >> xs >> ys;
	n = read(), k = read();
	k = n - k;
	int cnta = 0, cntb = 0;
	for(int i = 1; i <= n; i++) {
		double x, y;
		cin >> x >> y;
		if(check(x, xs)) {
			a[++cnta].x = x;
			a[cnta].y = y;
			a[cnta].t = atan2(x - xs, y - ys);
		}
		if(check(y, ys)) {
			b[++cntb].x = x;
			b[cntb].y = y;
			b[cntb].t = atan2(y - ys, x - xs);
		}
	}
	sort(a + 1, a + cnta + 1, cmp);
	sort(b + 1, b + cntb + 1, cmp);
	double ans = -1;
	for(int i = 1; i <= cnta; i++) {
		int ne = i + k - 1;
		if(ne > cnta) break;
		if(ans == -1) ans = calc(1, i, ne);
		else ans = min(ans, calc(1, i, ne));
	}
	for(int i = 1; i <= cntb; i++) {
		int ne = i + k - 1;
		if(ne > cntb) break;
		if(ans == -1) ans = calc(2, i, ne);
		else ans = min(ans, calc(2, i, ne));
	}
	if(ans == -1) {
		cout << -1;
		return 0;
	}
	printf("%.10Lf", ans);
	return 0;
}
