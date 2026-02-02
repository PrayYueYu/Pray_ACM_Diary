#include<bits/stdc++.h>
#define ll long long
#define int long long 
using namespace std;
const int N = 3e5 + 200, INF = 2e18;
int n, a[N], d[N], sum[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
double calc(int l, int r, int mid) {
	if(l <= 0 || r <= 0 || mid <= 0) return 0.0;
	if(mid - l + 1 <= 1 || r - mid + 1 <= 1) return 0.0;
	double now = sum[mid] - sum[l - 1];
	int num = mid - l + 1;
	double Max = 0;
	for(int i = mid + 1; i <= r; i++) {
		num++;
		now += a[i];
		Max = max(Max, now / (double)num);
	}
	num = r - mid + 1;
	now = sum[r] - sum[mid - 1];
	for(int i = mid - 1; i >= l; i--) {
		num++;
		now += a[i];
		Max = max(Max, now / (double)num);
	}
	return Max;
}
void solve() {
	n = read();
	a[0] = a[n + 1] = INF;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		d[i] = a[i] - a[i - 1];
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 0, r = -1, mid = 0;
	double ans = 0;
	for(int i = 1; i <= n; i++) {
		if(d[i] < 0) {
			if(r) {
				ans = max(ans, calc(l, r, mid));
				l = max(1ll, i - 1);
				r = 0;
			}
			mid = i;
		}
		if(d[i] > 0) {
			r = i;
		}
	}
	ans = max(ans, calc(l, r, mid));
	printf("%.12lf\n", ans);
}
signed main() {
	int T = read();
	while(T--) {
		solve();
	}
    return 0;
}
