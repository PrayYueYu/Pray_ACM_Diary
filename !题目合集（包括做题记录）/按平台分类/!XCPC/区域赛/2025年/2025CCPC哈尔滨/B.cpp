#include<bits/stdc++.h>
#define double long double
using namespace std;
const int N = 2e6 + 5; 
double xb, yb, vx, vy;
int read() {
	int x;
	cin >> x;
	return x;
}
void solve() {
	xb = read(), yb = read();
	vx = read(), vy = read();
	double y_1 = read(), y_2 = read();
	double v1 = read(), v2 = read();
	double ansy = 0, t = (y_2 - y_1) / (v1 + v2);
	ansy = y_1 + t * v1;
	double x1 = read(), x2 = read();
	v1 = read(), v2 = read();
	if(vx == 0) {
		printf("%.10Lf %.10Lf\n", xb, ansy);
		return;
	}
	if(v1 == 0 && v2 == 0) {
		
		double nowx = xb;
		int l = 0, r = 2e7, xx = 0;
		if(vx > 0) xx = 1;
		vx = fabs(vx);
		double tx = x2 - x1;
		tx /= vx;
		
		
		double t1 = 0;
		if(xx) t1 = (x2 - xb) / vx, xb = x2;
		else t1 = (xb - x1) / vx, xb = x1;
		if(t1 > t) {
			if(xx) nowx = nowx + vx * t;
			else nowx = nowx - vx * t;
			printf("%.10Lf %.10Lf\n", nowx, ansy);
			return;
		}
		t -= t1;
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			if(mid * tx > t) r = mid - 1;
			else l = mid;
		}
		t = t - l * tx;
		if(xx) {
			if(l & 1) {
				nowx = x1;
			}
			else nowx = x2;
		}
		else {
			if(l & 1) nowx = x2;
			else nowx = x1;
		}
		double eps = 1e-6;
		if(fabs(nowx - x2) <= eps) nowx -= vx * t;
		else nowx += vx * t;
		
		printf("%.10Lf %.10Lf\n", nowx, ansy);
		return;
	}
	
	double nowx = xb;
	int fx = 1;
	if(vx < 0) fx = 0, vx = -vx;
	while(true) {
		if(fx) {
			if(vx < v2) {
				nowx = nowx + vx * t;
				break;
			}
			double dt = (x2 - nowx) / (vx - v2);
			if(dt >= t) {
				nowx = nowx + vx * t;
				break;
			}
			x2 = x2 + v2 * dt;
			x1 = x1 - v1 * dt;
			nowx = x2;
			t -= dt;
			fx = 0;
		}
		else {
			if(vx < v1) {
				nowx = nowx - vx * t;
				break;
			}
			double dt = (nowx - x1) / (vx - v1);
			if(dt >= t) {
				nowx = nowx - vx * t;
				break;
			}
			x1 = x1 - v1 * dt;
			x2 = x2 + v2 * dt;
			nowx = x1;
			t -= dt;
			fx = 1;
		}
	}
	printf("%.10Lf %.10Lf\n", nowx, ansy);
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
/*
1
929581 723913 -5 -15
609169 741886 6 1
891364 978827 0 0
*/
