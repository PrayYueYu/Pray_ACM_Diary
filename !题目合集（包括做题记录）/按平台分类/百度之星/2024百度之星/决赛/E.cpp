#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 5e6 + 10, M = 1e9 + 7, INF = 2e18;
int n, k, d, a[N], trmax[N], trmin[N], nex[1000050][22];
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
bool check1(int mid) {
	int num = 1;
	int maxn = a[1], minn = a[1];
	for(int i = 2; i <= n; i++) {
		int nmaxn = max(maxn, a[i]);
		int nminn = min(minn, a[i]);
		if(nmaxn - nminn > mid) {
			num++;
			maxn = minn = a[i];
			continue;
		}
		maxn = nmaxn;
		minn = nminn;
	}
	if(num > k) return false;
	return true;
}

void build1(int p, int l, int r) {
	if(l == r) {
		trmax[p] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build1(p * 2, l, mid);
	build1(p * 2 + 1, mid + 1, r);
	trmax[p] = max(trmax[p * 2], trmax[p * 2 + 1]);
}
void build2(int p, int l, int r) {
	if(l == r) {
		trmin[p] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build2(p * 2, l, mid);
	build2(p * 2 + 1, mid + 1, r);
	trmin[p] = min(trmin[p * 2], trmin[p * 2 + 1]);
}
int query1(int p, int l, int r, int x, int y) {
	if(r < x || y < l) return -INF;
	if(x <= l && r <= y) return trmax[p];
	int mid = (l + r) >> 1;
	int ans = query1(p * 2, l, mid, x, y);
	ans = max(ans, query1(p * 2 + 1, mid + 1, r, x, y));
	return ans;
}
int query2(int p, int l, int r, int x, int y) {
	if(r < x || y < l) return INF;
	if(x <= l && r <= y) return trmin[p];
	int mid = (l + r) >> 1;
	int ans = query2(p * 2, l, mid, x, y);
	ans = min(ans, query2(p * 2 + 1, mid + 1, r, x, y));
	return ans;
}
void solve() {
	n = read(), k = read(), d = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	int l = 0, r = 2e12;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check1(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
	
	int maxn = a[1], minn = a[1], cnt = 1;
	for(int i = 2; i <= n; i++) {
		int nmaxn = max(maxn, a[i]);
		int nminn = min(minn, a[i]);
		if(nmaxn - nminn > d) {
			cnt++;
			maxn = minn = a[i];
			continue;
		}
		maxn = nmaxn;
		minn = nminn;
	}
	cout << cnt << '\n';
	
	int ans = 1;
	build1(1, 1, n);
	build2(1, 1, n);
	int nowx = 1;
	for(int i = 1; i <= n; i++) {
		nowx = max(i, nowx);
		while(true) {
			int maxn = query1(1, 1, n, i, min(n, nowx));
			int minn = query2(1, 1, n, i, min(n, nowx));
			if(maxn - minn <= d) nowx++;
			else break;
			if(nowx > n) break;
		}
		if(nowx > n) nowx = n + 1;
		nowx--;
		nex[i][0] = nowx + 1;
//		cout << i << ' ' << nowx << '\n';
	}
	for(int i = 0; i <= 21; i++) nex[n + 1][i] = n + 1;
	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= 21; j++) {
			nex[i][j] = nex[nex[i][j - 1]][j - 1];
		}
	}
	for(int i = 1; i <= n; i++) {
		int now = i;
		for(int j = 21; j >= 0; j--) {
			if(k >> j & 1) now = nex[now][j];
		}
		now--;
		ans = max(ans, now - i + 1);
	}
	cout << ans;
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
