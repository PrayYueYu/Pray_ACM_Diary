#include<bits/stdc++.h>
const int N = 2e5 + 10, mod = 998244353;
int tr[N * 8], a[N], n, m, trl[N * 8], trr[N * 8], tag[N * 8];
void init() {
	for(int i = 0; i <= n * 8 + 5; i++) {
		tr[i] = trl[i] = trr[i] = tag[i] = 0;
	}
}
int check(int x, int y) {
	if(x == y) return false;
	return true; 
}
void pushup(int p) {
    tr[p] = tr[p * 2] + tr[p * 2 + 1] + check(trr[p * 2], trl[p * 2 + 1]);
	trl[p] = trl[p * 2];
	trr[p] = trr[p * 2 + 1];
}
void build(int p, int l, int r) {
    if(l == r) {
        tr[p] = 0;
        trl[p] = a[l];
		trr[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
	pushup(p);
}
void Lazy(int p, int l, int r, int c) {
    if(c == 3) {
    	trl[p] ^= 1;
    	trr[p] ^= 1;
    	if(!tag[p]) tag[p] = 3;
    	else if(tag[p] == 1) tag[p] = 2;
    	else if(tag[p] == 2) tag[p] = 1;
    	else tag[p] = 0;
	}
	else {
		trl[p] = trr[p] = c - 1;
		tr[p] = 0;
		tag[p] = c;
	}
}
void pushdown(int p, int l, int r) {
	if(!tag[p]) return;
    int mid = (l + r) >> 1;
    Lazy(p * 2, l, mid, tag[p]);
    Lazy(p * 2 + 1, mid + 1, r, tag[p]);
    tag[p] = 0;
}
void update(int p, int l, int r, int lx, int rx, int c) {
    if(rx < l || r < lx) return;
    if(lx <= l && r <= rx) {
        Lazy(p, l, r, c);
        return;
    }
	pushdown(p, l, r);
    int mid = (l + r) >> 1;
    update(p * 2, l, mid, lx, rx, c);
    update(p * 2 + 1, mid + 1, r, lx, rx, c);
    pushup(p);
}
int query(int p, int l, int r, int lx, int rx)  {
    if(rx < l || r < lx) return -1;
    if(lx <= l && r <= rx) return tr[p];
	pushdown(p, l, r);
    int mid = (l + r) >> 1;
    int ans = 0, s1 = 0, s2 = 0;
    s1 = query(p * 2, l, mid, lx, rx);
    s2 = query(p * 2 + 1, mid + 1, r, lx, rx);
    if(s1 >= 0 && s2 >= 0) {
    	ans = s1 + s2 + check(trr[p * 2], trl[p * 2 + 1]);
	}
	else {
		s1 = std::max(0, s1);
		s2 = std::max(0, s2);
		ans = s1 + s2;
	}
    pushup(p);
    return ans;
}
void solve() {
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) std::cin >> a[i];
	build(1, 1, n);
	for(int i = 1; i <= m; i++) {
		int op, l, r, x;
		std::cin >> op >> l >> r;
		if(op == 1) {
			std::cin >> x;
			update(1, 1, n, l, r, x + 1);
		}
		else if(op == 2) update(1, 1, n, l, r, 3);
		else std::cout << query(1, 1, n, l, r) << '\n';
	}
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Ş±‹¬ | 
----------------------
*/
