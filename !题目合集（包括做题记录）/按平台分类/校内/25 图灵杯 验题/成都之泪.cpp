#include<bits/stdc++.h>
//#define getchar getchar_unlocked
using namespace std;
const int N = 2e6 + 10, M = 1e9 + 7, INF = 1e7;
int n, k, maxn[N][3], minn[N][3], fr[N], fl[N], maxr[N], maxl[N], sum[N][3], l[N], r[N], d[N], a[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
struct Tree {
	int minn;
	int lmin;
	int rmin;
	int sum;
} tr[N]; 
void init() {
	for(int i = 0; i <= 8 * n + 200; i++) {
		maxn[i][1] = minn[i][1] = 0;
		maxn[i][2] = minn[i][2] = 0;
		tr[i].lmin = tr[i].rmin = tr[i].minn = tr[i].sum = 0;
	}
	for(int i = 0; i <= 2 * n + 10; i++) {
		sum[i][1] = sum[i][2] = 0;
		fr[i] = fl[i] = 0;
		maxr[i] = maxl[i] = 0;
		d[i] = 0;
	}
}
Tree pushup(Tree p1, Tree p2) {
	Tree now;
	now.sum = p1.sum + p2.sum;
	now.lmin = min(p1.lmin, p1.sum + p2.lmin);
	now.rmin = min(p2.rmin, p2.sum + p1.rmin);
	now.minn = min({p1.minn, p2.minn, p1.rmin + p2.lmin});
	return now;
}
void build(int p, int l, int r) {
	if(l == r) {
		tr[p].minn = tr[p].lmin = tr[p].rmin = tr[p].sum = a[l];
		return;
	} 
	int mid = (l + r) >> 1;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	tr[p] = pushup(tr[p * 2], tr[p * 2 + 1]);
}
Tree query(int p, int l, int r, int x, int y) {
	if(y < l || r < x) {
		Tree now; now.minn = now.lmin = now.rmin = now.sum = INF;
		return now;
	}
	if(x <= l && r <= y) return tr[p];
	int mid = (l + r) >> 1;
	Tree ans = pushup(query(p * 2, l, mid, x, y), query(p * 2 + 1, mid + 1, r, x, y));
	return ans;
}
void build1(int p, int l, int r, int t) {
	if(l == r) {
		maxn[p][t] = sum[l][t];
		return;
	}
	int mid = (l + r) >> 1;
	build1(p * 2, l, mid, t);
	build1(p * 2 + 1, mid + 1, r, t);
	maxn[p][t] = max(maxn[p * 2][t], maxn[p * 2 + 1][t]);
}
void build2(int p, int l, int r, int t) {
	if(l == r) {
		minn[p][t] = sum[l][t];
		return;
	}
	int mid = (l + r) >> 1;
	build2(p * 2, l, mid, t);
	build2(p * 2 + 1, mid + 1, r, t);
	minn[p][t] = min(minn[p * 2][t], minn[p * 2 + 1][t]);
}
int query1(int p, int l, int r, int x, int y, int t) {
	if(x > y) return -INF;
	if(r < x || y < l) return -INF;
	if(x <= l && r <= y) return maxn[p][t];
	int mid = (l + r) >> 1;
	int ans = query1(p * 2, l, mid, x, y, t);
	ans = max(ans, query1(p * 2 + 1, mid + 1, r, x, y, t));
	return ans;
}
int query2(int p, int l, int r, int x, int y, int t) {
	if(x > y) return INF;
	if(r < x || y < l) return INF;
	if(x <= l && r <= y) return minn[p][t];
	int mid = (l + r) >> 1;
	int ans = query2(p * 2, l, mid, x, y, t);
	ans = min(ans, query2(p * 2 + 1, mid + 1, r, x, y, t));
	return ans;
}
void solve() {
	n = read(), k = read();
	init();
	for(int i = 1; i <= n; i++) {
		l[i] = read(), r[i] = read();
		d[l[i]]++;
		d[r[i] + 1]--;
	}

	if(k == n + 1) {
		for(int i = 1; i <= n; i++) cout << "0\n";
		return;
	}
	int now = 0;
	for(int i = 1; i <= 2 * n; i++) {
		d[i] += d[i - 1];
		sum[i][1] = sum[i - 1][1];
		if(d[i] == k) sum[i][1]--, now++, a[i] = -1;
		else if(d[i] == k + 1) sum[i][1]++, a[i] = 1;
		else a[i] = 0;
	}
	for(int i = 1; i <= 2 * n; i++) {
		sum[i][2] = sum[i - 1][2];
		if(d[i] == k) sum[i][2]--;
		else if(d[i] == k - 1) sum[i][2]++;
	}
	build1(1, 0, 2 * n, 1);
	build2(1, 0, 2 * n, 1);
	
	build1(1, 0, 2 * n, 2);
	build2(1, 0, 2 * n, 2);
	
	build(1, 1, 2 * n);
	for(int i = 1; i <= 2 * n; i++) {
		fr[i] = query1(1, 0, 2 * n, i, 2 * n, 2) - sum[i - 1][2];
		fl[i] = sum[i][2] - query2(1, 0, 2 * n, 0, i - 1, 2);
	}
	for(int i = 1; i <= 2 * n; i++) {
		maxl[i] = max(maxl[i - 1], fl[i]);
	}
	maxr[2 * n + 1] = 0;
	for(int i = 2 * n; i >= 1; i--) {
		maxr[i] = max(maxr[i + 1], fr[i]);
	}
	for(int i = 1; i <= n; i++) {
		int ans = -INF;
		ans = now;//刚好重叠 
		ans = max(ans, now + sum[r[i]][1] - sum[l[i] - 1][1]);//不选择 
		ans = max(now + sum[r[i]][1] - sum[l[i] - 1][1] + maxr[r[i] + 1], ans);//不包含-选右边 
		ans = max(now + sum[r[i]][1] - sum[l[i] - 1][1] + maxl[l[i] - 1], ans);//不包含-选右边 
		ans = max(now + query1(1, 0, 2 * n, l[i] - 1, r[i] - 1, 1) - sum[l[i] - 1][1] + fr[r[i] + 1], ans);//不完全包含-右边 
		ans = max(now + sum[r[i]][1] - query2(1, 0, 2 * n, l[i], r[i], 1) + fl[l[i] - 1], ans);//不完全包含-左边 
		ans = max(now + query1(1, 0, 2 * n, r[i], 2 * n, 2) - sum[r[i]][2] + sum[l[i] - 1][2] - query2(1, 0, 2 * n, 0, l[i] - 1, 2), ans);//完全包含-old属于new 
		ans = max(ans, now + sum[r[i]][1] - sum[l[i] - 1][1] - query(1, 1, 2 * n, l[i], r[i]).minn);//完全包含-new属于old（线段树区间求min） 
		cout << ans << '\n';
	}
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
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
