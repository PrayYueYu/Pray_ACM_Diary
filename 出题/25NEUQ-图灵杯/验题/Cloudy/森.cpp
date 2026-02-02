#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 3e6 + 100, INF = 2e18, mod = 998244353;
const int Nx = 5e5 + 100;
int L[Nx], R[Nx], ansL[Nx], ansR[Nx];
int las[N], a[Nx], b[Nx], n, num[N];
inline int read() {
	int x;
	scanf("%d", &x);
	return x;
}
struct Qu {
	int l, r, t;
} s[N];
bool cmp1(Qu x, Qu y) {
	return x.l < y.l;
}
bool cmp2(Qu x, Qu y) {
	return x.r > y.r;
}
map<int, int> mp;
inline void update1(int p, int l, int r, int t, int to) {
	if(r < t || t < l) return;
	if(l == r) {
		las[p] = to;
		return;
	}
	int mid = (l + r) >> 1;
	update1(p * 2, l, mid, t, to);
	update1(p * 2 + 1, mid + 1, r, t, to);
	las[p] = max(las[p * 2], las[p * 2 + 1]);
}
inline int query1(int p, int l, int r, int x, int y) {
	if(y < x) return 0;
	if(r < x || y < l) return 0;
	if(x <= l && r <= y) return las[p];
	int mid = (l + r) >> 1;
	int ans = query1(p * 2, l, mid, x, y);
	ans = max(ans, query1(p * 2 + 1, mid + 1, r, x, y));
	return ans;
}

inline void build2(int p, int l, int r) {
	if(l == r) {
		las[p] = n + 1;
		return;
	}
	int mid = (l + r) >> 1;
	build2(p * 2, l, mid);
	build2(p * 2 + 1, mid + 1, r);
	las[p] = n + 1;
}
inline void update2(int p, int l, int r, int t, int to) {
	if(r < t || t < l) return;
	if(l == r) {
		las[p] = to;
		return;
	}
	int mid = (l + r) >> 1;
	update2(p * 2, l, mid, t, to);
	update2(p * 2 + 1, mid + 1, r, t, to);
	las[p] = min(las[p * 2], las[p * 2 + 1]);
}
inline int query2(int p, int l, int r, int x, int y) {
	if(y < x) return n + 1;
	if(r < x || y < l) return n + 1;
	if(x <= l && r <= y) return las[p];
	int mid = (l + r) >> 1;
	int ans = query2(p * 2, l, mid, x, y);
	ans = min(ans, query2(p * 2 + 1, mid + 1, r, x, y));
	return ans;
}

inline void build4(int p, int l, int r) {
	if(l == r) {
		num[p] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build4(p * 2, l, mid);
	build4(p * 2 + 1, mid + 1, r);
	num[p] = 0; 
}
inline void update(int p, int l, int r, int t, int to) {
	if(r < t || t < l) return;
	if(l == r) {
		num[p]++;
		return;
	}
	int mid = (l + r) >> 1;
	update(p * 2, l, mid, t, to);
	update(p * 2 + 1, mid + 1, r, t, to);
	num[p] = num[p * 2] + num[p * 2 + 1];
}
inline int query(int p, int l, int r, int x, int y) {
	if(y < x) return 0;
	if(r < x || y < l) return 0;
	if(x <= l && r <= y) return num[p];
	int mid = (l + r) >> 1;
	int ans = query(p * 2, l, mid, x, y);
	ans += query(p * 2 + 1, mid + 1, r, x, y);
	ans %= mod;
	return ans;
}
signed main() {
	n = read();
	for(register int i = 1; i <= n; i++) {
		a[i] = read();
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int cnt = 0;
	for(register int i = 1; i <= n; i++) {
		if(!mp[b[i]]) mp[b[i]] = ++cnt;
	}
	for(register int i = 1; i <= n; i++) {
		a[i] = mp[a[i]];
	}
	for(register int i = 1; i <= n; i++) {
		L[i] = query1(1, 1, cnt, 1, a[i] - 1) + 1;
		update1(1, 1, cnt, a[i], i);
	}
	build2(1, 1, cnt);
	for(register int i = n; i >= 1; i--) {
		R[i] = query2(1, 1, cnt, 1, a[i] - 1) - 1;
		update2(1, 1, cnt, a[i], i);
	}
	for(register int i = 1; i <= n; i++) {
		s[i] = {L[i] - 1, R[i] + 1, i};
	}
	sort(s + 1, s + n + 1, cmp1);
	int now = 1;
	for(register int i = 1; i <= n; i++) {
		update(1, 1, cnt, a[i], 1);
		if(now > n) break;
		if(s[now].l > i) continue;
		while(true) {
			if(s[now].l > i || now > n) break;
			if(s[now].l < i) {
				now++;
				continue;
			}
			ansL[s[now].t] = query(1, 1, cnt, 1, a[s[now].t] - 1);
			now++;
		}
	}
	build4(1, 1, cnt);
	sort(s + 1, s + n + 1, cmp2);
	now = 1;
	for(register int i = n; i >= 1; i--) {
		update(1, 1, cnt, a[i], 1);
		if(now > n) break;
		if(s[now].r < i) continue;
		while(true) {
			if(s[now].r < i || now > n) break;
			if(s[now].r > i) {
				now++;
				continue;
			}
			ansR[s[now].t] = query(1, 1, cnt, 1, a[s[now].t] - 1);
			now++;
		}
	}
	ll ans = 0;
	for(register int i = 1; i <= n; i++) las[i] = 0;
	for(register int i = 1; i <= n; i++) {
		ll now1 = 0, s1 = 0, s2 = 0;
		if(!las[a[i]] || las[a[i]] < L[i]) {
			s1 = (i - L[i] + 1);
			s2 = (R[i] - i + 1);
			las[a[i]] = i;
		}
		else {
			s1 = (i - las[a[i]]);
			s2 = (R[i] - i + 1);
			las[a[i]] = i;
		}
		now1 = (s1 * s2) % mod;
		s1 = ansL[i], s2 = ansR[i];
		ll now2 = (s1 * s2) % mod;
		ans = (ans + (now1 * now2) % mod) % mod;
	}
	cout << ans;
	return 0;
}
/*
-------------------------------
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
-------------------------------
*/

