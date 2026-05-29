#include<bits/stdc++.h>
#define int long long
#define double long double
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
double pi = acosl(-1.0l);
int n;
double R;
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
struct Point {
	double x, y;
} s[N], st[N];
double calc_Len(Point a, Point b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}
double calc_S(Point a, Point b) {
	double ans = (a.x * b.y - a.y * b.x);
	ans = ans / 2.0;
	return ans;
}
double check(Point a1, Point a2, Point b1, Point b2) {
	double ux = a2.x - a1.x;
	double uy = a2.y - a1.y;
	double vx = b2.x - b1.x;
	double vy = b2.y - b1.y;
	return ux * vy - uy * vx;
}
bool cmp(Point a, Point b) {
	double now = check(s[1], a, s[1], b);
	if(now > 0) return true;
	else if(now < 0) return false;
	return calc_Len(s[1], a) < calc_Len(s[1], b);
}
double getS(double x1, double y1, double x2, double y2) {
//	std::cout << '(' << x1 << ',' << y1 << ") ";
//	std::cout << '(' << x2 << ',' << y2 << ")\n";
	double A = 0, B = 0, C = 0;
	if(x1 == x2) {
		B = 0;
		A = 1;
		C = -x1;
	}
	else if(y1 == y2) {
		A = 0;
		B = 1;
		C = -y1;
	}
	else {
		double k = (y2 - y1) / (x2 - x1);
		double b = y1 - k * x1;
		A = k, B = -1, C = b;
	}
	double d2 = C * C / (A * A + B * B);
	double xx = R * R - d2;
	double x = sqrt(xx), d = sqrt(d2);
	double ar = acosl(d / R);
	double S = x * d + (pi - ar) * R * R;
	return S;
}
void solve() {
	n = read(), R = read();
	int new_n = 0, num = 0;
	double Minx = 1e18, Miny = 1e18;
	n++;
	for(int i = 1; i <= n; i++) {
		double x, y;
		if(i != n) {
			x = read(), y = read();
		}
		else x = y = 0;
		s[++new_n].x = x;
		s[new_n].y = y;
		if(new_n >= 2) {
			if(s[new_n].y < s[1].y) {
				std::swap(s[new_n], s[1]);
			}
			else if(s[new_n].y == s[1].y) {
				if(s[new_n].x < s[1].x) {
					std::swap(s[new_n], s[1]);
				}
			}
		}
	}
	n = new_n;
	std::sort(s + 2, s + n + 1, cmp);
	
	s[0].x = s[1].x - 1;
	for(int i = 1; i <= n; i++) {
		if(s[i].x == s[i - 1].x && s[i].y == s[i - 1].y) 
			continue;
		while(num >= 2) {
			if(check(st[num - 1], st[num], st[num], s[i]) <= 0) {
				num--;
			} 
			else break;
		}
		st[++num] = s[i];
	}
	st[++num] = s[1];
	double ans = -1.0;
	for(int i = 1; i < num; i++) {
		double S = getS(st[i].x, st[i].y, st[i + 1].x, st[i + 1].y);
		ans = std::max(ans, pi * R * R - S);
	}
	printf("%.10Lf\n", ans);
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
