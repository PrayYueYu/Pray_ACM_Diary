#include<bits/stdc++.h>
#define re register
#define in inline
const int N = 4e5 + 10, mod = 998244353, INF = 1e9;
int fa[N], pa[N], n, m, bL[N], bR[N], id[N], Len, cnt[N], val[N];
in int read() {
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
void init() {
	Len = sqrt(n);
	int L = 0, R = 0, t = 0;
	for(re int i = 1; i <= n; i++) {
		if(i > R) {
			L = i;
			R = std::min(n, L + Len);
			t++;
			bL[t] = L;
			bR[t] = R;
		}
		id[i] = t;
	}
}
in void update_p(int x) {
	if(cnt[id[x]] <= Len) {
		if(id[x] == id[fa[x]]) pa[x] = pa[fa[x]];
		else pa[x] = fa[x];
	}
}
in void update_lr(int l, int r, int x) {
	for(re int i = l; i <= bR[id[l]]; i++) {
		if(i <= r)
			fa[i] = std::max(1, fa[i] - x);
		update_p(i);
	}
}
in void update_Len(int t, int x) {
	if(cnt[t] > Len) {
		val[t] = std::min(val[t] + x, n);
		return;
	}
	for(re int i = bL[t]; i <= bR[t]; i++) {
		fa[i] = std::max(fa[i] - x, 1);
		update_p(i);
	}
}
in void update(int l, int r, int x) {
	if(id[l] == id[r]) {
		update_lr(l, r, x);
		return;
	}
	update_lr(l, bR[id[l]], x);
	update_lr(bL[id[r]], r, x);
	for(re int i = id[l] + 1; i <= id[r] - 1; i++) {
		update_Len(i, x);
		if(cnt[i] <= Len) cnt[i]++;
	}
}
in int getfa(int x) {
	if(cnt[id[x]] <= Len) return fa[x];
	return std::max(1, fa[x] - val[id[x]]);
}
in int getpa(int x) {
	if(cnt[id[x]] <= Len) return pa[x];
	return std::max(1, fa[x] - val[id[x]]);
}
in int lca(int u, int v) {
	while(true) {
		if(u == v) break;
		int pau = getpa(u), pav = getpa(v);
		if(pau != pav) {
			if(pau > pav) u = pau;
			else v = pav;
		}
		else {
			if(u > v) u = getfa(u);
			else v = getfa(v);
		}
	}
	return u;
}
void solve() {
	n = read(), m = read();
	init();
	for(int i = 2; i <= n; i++) {
		fa[i] = read();
		update_p(i);
	}
	int lasans = 0;
	for(re int i = 1; i <= m; i++) {
		int op = read();
		if(op == 1) {
			int l = read(), r = read(), x = read();
			l ^= lasans, r ^= lasans, x ^= lasans;
			update(l, r, x);
		}
		else {
			int u = read(), v = read();
			u ^= lasans, v ^= lasans;
			lasans = lca(u, v);
			printf("%lld\n", lasans);
			lasans = 0; 
		}
	}
}
signed main() {
	int T = 1; 
	while(T--) solve();
	return 0;
}
/*

*/
