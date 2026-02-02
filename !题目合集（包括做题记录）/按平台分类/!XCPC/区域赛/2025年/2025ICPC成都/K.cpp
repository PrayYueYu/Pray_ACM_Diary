#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10, INF = 1e18;
int n, L, k, s3[N], f[N], maxn[N], sumf[N];
int s1[N], s2[N], sums1[N], sums2[N];
int preMax[N], sufMax[N], d[N], s[N];
int minn[N];
int read() {
	int x;
	cin >> x;
	return x;
}
void build(int p, int l, int r) {
	if(l == r) {
		maxn[p] = sumf[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	maxn[p] = max(maxn[p * 2], maxn[p * 2 + 1]);
}
int query(int p, int l, int r, int x, int y) {
	if(l < 1) l = 1;
	if(x <= l && r <= y) return maxn[p];
	if(r < x || y < l) return -INF;
	int mid = (l + r) >> 1;
	int ans = query(p * 2, l, mid, x, y);
	ans = max(ans, query(p * 2 + 1, mid + 1, r, x, y));
	return ans;
}
void buildx(int p, int l, int r) {
	if(l == r) {
		minn[p] = sumf[l];
		return;
	}
	int mid = (l + r) >> 1;
	buildx(p * 2, l, mid);
	buildx(p * 2 + 1, mid + 1, r);
	minn[p] = min(minn[p * 2], minn[p * 2 + 1]);
}
int queryx(int p, int l, int r, int x, int y) {
	if(x > y) return INF;
	if(l < 1) l = 1;
	if(x <= l && r <= y) return minn[p];
	if(r < x || y < l) return INF;
	int mid = (l + r) >> 1;
	int ans = queryx(p * 2, l, mid, x, y);
	ans = min(ans, queryx(p * 2 + 1, mid + 1, r, x, y));
	return ans;
}
void solve() {
	n = read(), L = read(), k = read();
	for(int i = 0; i <= 7 * n; i++) {
		preMax[i] = sufMax[i] = -INF;
		sums1[i] = sums2[i] = 0;
		s1[i] = s2[i] = 0;
		d[i] = s3[i] = 0;
		f[i] = sumf[i];
		maxn[i] = -INF;
		minn[i] = INF;
	}
	for(int i = 1; i <= n; i++) {
		s[i] = read() + 1;
		d[s[i]]++;
		d[s[i] + L]--;
	}
	int sum = 0, p = 0;
	for(int i = 1; i <= 4 * n; i++) {
		sum = sum + d[i];
		if(sum == k) s1[i]--, s2[i]--, p++;
		if(sum == k + 1) s1[i]++;
		if(sum == k - 1) s2[i]++;
	}
	for(int i = 1; i <= 4 * n; i++) {
		sums2[i] = sums2[i - 1] + s2[i];
		sums1[i] = sums1[i - 1] + s1[i];
		if(i - L >= 0) {
			s3[i] = sums2[i] - sums2[i - L];
		}
	}
	for(int i = L; i <= 4 * n; i++) {
		preMax[i] = max(preMax[i - 1], s3[i]);
	}
	sufMax[4 * n + 1] = -INF;
	for(int i = 4 * n; i >= L; i--) {
		sufMax[i] = max(sufMax[i + 1], s3[i]);
	}
	int ans = -INF;
	for(int i = 1; i <= n; i++) {
		int now = sums1[s[i] + L - 1] - sums1[s[i] - 1];
		if(s[i] - 1 >= L) {
			ans = max(ans, now + preMax[s[i] - 1]);
		}
		ans = max(ans, now + sufMax[s[i] + 2 * L - 1]);
	}
	
	for(int i = 1; i <= 3 * n + 1; i++) {
		f[i] = s1[i] + s2[i + L];
		sumf[i] = sumf[i - 1] + f[i];
	}
	build(1, 1, 3 * n + 1);
	for(int i = 1; i <= n; i++) {
		int Max = query(1, 1, 3 * n + 1, s[i] - 1, s[i] + L - 1);
		Max -= sumf[s[i] - 1];
		ans = max(ans, Max);
	}
	
	for(int i = L; i <= 3 * n + 1; i++) {
		f[i] = s1[i] + s2[i - L];
		sumf[i] = sumf[i - 1] + f[i];
	}
	buildx(1, L, 3 * n + 1);
	for(int i = 1; i <= n; i++) {
		int Min = queryx(1, L, 3 * n + 1, max(s[i] - 1, L), s[i] + L - 1);
		Min = sumf[s[i] + L - 1] - Min;
		ans = max(ans, Min);
	}
	cout << ans + p << '\n';
}
signed main() {
    int T = read();
    while(T--) {
    	solve();
//    	init();
	}
    return 0;
}
/*

*/
