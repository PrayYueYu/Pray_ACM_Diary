#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int n, m;
int sum[N], sumx[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
struct F {
	int a, l, r;
} s[N];
bool cmp (F x, F y) {
	return x.a > y.a;
}
bool check(int mid, int t, int d) {
	int now = sum[mid];
	if(mid >= t) now -= (s[t].r - s[t].l);
	if(now <= s[t].l + d) return true;
	return false;
}
void solve() {
	n = read(), m = read();
	int Max = -1, all = 0, d = m, ans = -1;
	for(int i = 1; i <= n; i++) {
		s[i].a = read();
		s[i].l = read(), s[i].r = read();
		all += s[i].l * s[i].a;
		d -= s[i].l;
	}
	sort(s + 1, s + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + s[i].r - s[i].l;
		sumx[i] = sumx[i - 1] + (s[i].r - s[i].l) * s[i].a;
	}
	//cout << all << endl;
	for(int i = 1; i <= n; i++) {
		//cout << all << " " << s[i].a << " " << d << endl;
		ans = max(ans, d * s[i].a + all);
		int now = all - s[i].l * s[i].a;
		int l = 0, r = n;
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			if(check(mid, i, d)) l = mid;
			else r = mid - 1;
		}
		int sc = sum[l];
		if(l >= i) sc -= (s[i].r - s[i].l);
		if(sc <= s[i].l + d) {
			now += sumx[l];
			int dd = d + s[i].l - sc;
			if(l >= i) now -= (s[i].r - s[i].l) * s[i].a;
			now += dd * s[l + 1].a;
		}
		ans = max(ans, now);
	}
	cout << ans;
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
