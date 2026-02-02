#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 1000;
int n, k;
double pi = acos(-1.0);
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
struct D {
	int x, y;
	double t;
} s[N];
bool cmp(D a, D b) {
	return a.t < b.t;
}
void solve() {
	n = read(); k = read(); k++;
	for(int i = 1; i <= n; i++) {
		s[i].x = read(), s[i].y = read();
		s[i].t = atan2((double)s[i].y, (double)s[i].x);
		if(s[i].t < 0) s[i].t += 2 * pi;
	}
	if(k > n) {
		printf("%.8lf\n", 2 * pi);
		return;
	}
	sort(s + 1, s + n + 1, cmp);
	double ans = -1;
	for(int i = 1; i <= n; i++) {
		int ne = i + k - 1;
		double dx = 0;
		if(ne > n) {
			dx = s[ne - n].t - s[i].t + 2 * pi;
		}
		else dx = s[ne].t - s[i].t;
		ans = max(ans, dx);
	}
	if(ans <= 0.00) {
		ans = 2 * pi;
	}
	printf("%.10lf\n", ans);
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
} 
