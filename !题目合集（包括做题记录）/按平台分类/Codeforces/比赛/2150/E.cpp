#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e6 + 100, M = 1e9 + 7, INF = 1e16; 
int tr[N], n, m, b[N], to[N], a[N], tag[N], v[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void init() {
	for(int i = 0; i <= 4 * (n + 1) + 100; i++) {
		tr[i] = tag[i] = 0;
	}
}
void Lazy(int p, int c) {
	tr[p] += c;
	tag[p] += c;
}
void pushdown(int p) {
	Lazy(p * 2, tag[p]);
	Lazy(p * 2 + 1, tag[p]);
	tag[p] = 0;
}
void update(int p, int l, int r, int lx, int rx, int c, int op) {
	if(r < lx || rx < l) return;
	if(lx <= l && r <= rx) {
		if(op == 2) Lazy(p, c);
		else tr[p] = max(tr[p], c);
		return;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	update(p * 2, l, mid, lx, rx, c, op);
	update(p * 2 + 1, mid + 1, r, lx, rx, c, op);
	tr[p] = max(tr[p * 2] ,tr[p * 2 + 1]);
}
int query(int p, int l, int r, int lx, int rx) {
	if(r < lx || rx < l) return -INF;
	pushdown(p);
	if(lx <= l && r <= rx) return tr[p];
	int ans = -INF, mid = (l + r) >> 1;
	ans = max(ans, query(p * 2, l, mid, lx, rx));
	ans = max(ans, query(p * 2 + 1, mid + 1, r, lx, rx));
	return ans;
}
void solve() {
	n = read() ;
	for(int i = 1; i <= n; i++) v[i] = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for(int i = 1; i <= n; i++) {
		b[i] = read();
		to[b[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		int Max = query(1, 0, n, 0, to[a[i]] - 1);
		update(1, 0, n, to[a[i]], to[a[i]], Max, 1);
		update(1, 0, n, 0, to[a[i]] - 1, v[a[i]], 2);
	}
	cout << query(1, 0, n, 0, n) << endl;
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
