#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e6 + 100, INF = 2e18, mod = 1e9 + 7;
int cnt, n, x, p1[N], p2[N], a[N], b[N], tr[N];
int tag[N], to[N];
inline int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
inline void Lazy(int p, int t) {
	tag[p] = (tag[p] * t) % mod;
	tr[p] = (tr[p] * t) % mod;
}
inline void pushdown(int p, int l, int r) {
	if(tag[p] == 1) return;
	Lazy(p * 2, tag[p]);
	Lazy(p * 2 + 1, tag[p]);
	tag[p] = 1;
}
inline void pushup(int p) {
	tr[p] = (tr[p * 2] + tr[p * 2 + 1]) % mod;
}
inline void update(int p, int l, int r, int x, int y, int op, int t) {
	if(r < x || y < l) return;
	pushdown(p, l, r);
	if(x <= l && r <= y) {
		if(op == 1) tr[p] = t;
		else {
			if(t == 1) Lazy(p, p1[1]);
			else Lazy(p, p2[1]);
		}
		return;
	}
	
	int mid = (l + r) >> 1;
	update(p * 2, l, mid, x, y, op, t);
	update(p * 2 + 1, mid + 1, r, x, y, op, t);
	pushup(p);
}
inline int query(int p, int l, int r, int x, int y) {
	if(r < x || y < l) return 0;
	pushdown(p, l, r);
	if(x <= l && r <= y) return tr[p];
	int mid = (l + r) >> 1;
	int ans = query(p * 2, l, mid, x, y);
	ans += query(p * 2 + 1, mid + 1, r, x, y);
	ans %= mod;
	pushup(p);
	return ans;
}
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ans;
}
map<int, int> mp;
void solve() {
	n = read(), x = read();
	int inv = ksm(100, mod - 2);
	p1[0] = p2[0] = 1;
	for(register int i = 1; i <= 1; i++) {
		p1[i] = inv;
		p1[i] = (p1[i] * x) % mod;
		
		p2[i] = inv;
		p2[i] = (p2[i] * (100 - x)) % mod;
	}
	for(register int i = 0; i <= 4 * n + 100; i++) {
		tag[i] = 1;
	}
	for(register int i = 1; i <= n; i++) {
		a[i] = read();
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for(register int i = 1; i <= n; i++) {
		if(!mp[b[i]]) {
			mp[b[i]] = ++cnt;
			to[cnt] = b[i];
		}
	}
	for(register int i = 1; i <= n; i++) a[i] = mp[a[i]];
	int ans = 0;
	int xx = 2, yy = 1;
	if(a[1] != a[2]) {
		if(a[1] < a[2]) xx = 1, yy = 2;
		update(1, 1, cnt, a[xx], a[xx], 1, p1[1]);
		update(1, 1, cnt, a[yy], a[yy], 1, p2[1]);
	}
	else {
		update(1, 1, cnt, a[xx], a[xx], 1, 1);
	}
	for(register int i = 3; i <= n; i++) {
		int s1 = query(1, 1, cnt, 1, a[i] - 1);
		int s2 = query(1, 1, cnt, a[i] + 1, cnt);
		int s3 = ((1ll - s1 - s2) % mod + mod) % mod;
		s1 = (s1 * p2[1] + s2 * p1[1] + s3) % mod;
		
		update(1, 1, cnt, a[i], a[i], 1, s1);
		
		update(1, 1, cnt, 1, a[i] - 1, 2, 1);
		update(1, 1, cnt, a[i] + 1, cnt, 2, 2);
	}
	for(register int i = 1; i <= cnt; i++) {
		int now = query(1, 1, cnt, i, i);
		ans = (ans + now * to[i]) % mod;
	}
	cout << ans;
}
signed main() {
	
	int T = 1;
	while(T--) solve();
	return 0;
}
