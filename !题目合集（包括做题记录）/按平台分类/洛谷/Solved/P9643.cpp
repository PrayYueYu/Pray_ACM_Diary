#include<bits/stdc++.h>
#define int long long
using namespace std;
double va, vb, xa, xb, xc, ya, yb, yc;
int read() {
	int x;
	cin >> x;
	return x;
}
double dis(double x_1, double y_1, double x_2, double y_2) {
	return fabs(x_1 - x_2) + fabs(y_1 - y_2);
}
void solve() {
	va = read(), vb = read();
	xa = read(), ya = read();
	xb = read(), yb = read();
	xc = read(), yc = read();
	double d1 = dis(xa, ya, xc, yc);
	double d2 = dis(xb, yb, xc, yc);
	double t1 = d1 / va, t2 = d2 / vb;
	double x = max(min(xa, xb), min(max(xa, xb), xc));
	double y = max(min(ya, yb), min(max(ya, yb), yc));
//	cout << dis(xa, ya, x, y) << ' ';
//	cout << dis(xb, yb, x, y) << endl;
	double t3 = 0;
	if(dis(xa, ya, x, y) * vb < dis(xb, yb, x, y) * va) {
		t3 = t2;
		//return;
	}
	else {
		double dt = dis(xa, ya, xb, yb) / (va + vb);
		double d3 = d1 - va * dt;
		t3 = dt + d3 / vb;
	}
	printf("%.10lf\n", min(t3, t1));
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
