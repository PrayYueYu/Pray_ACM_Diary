#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int to[N], n, q, tr[N], cnt, ans[N];
std::map<int, int> mp;
void init() {
	mp.clear();
	for(int i = 0; i <= cnt; i++) tr[i] = 0;
	cnt = 0;
}
struct S {
	int l, r, id;
} s[N], t[N];
bool cmp(S x, S y) {
	return x.l > y.l;
}
int lowbit(int x) {
	return x & (-x);
}
void insert(int x, int y) {
	while(x <= cnt) {
		tr[x] = std::max(tr[x], y);
		x += lowbit(x);
	}
}
int query(int x) {
	int ans = 0;
	while(x) {
		ans = std::max(ans, tr[x]);
		x -= lowbit(x);
	}
	return ans;
}
void solve() {
	std::cin >> n >> q;
	std::vector<int> v;
	for(int i = 1; i <= n; i++) {
		std::cin >> s[i].l >> s[i].r;
		v.push_back(s[i].r);
	}
	for(int i = 1; i <= q; i++) {
		std::cin >> t[i].l >> t[i].r;
		t[i].id = i;
		v.push_back(t[i].r);
	}
	
	std::sort(v.begin(), v.end());
	for(auto x: v) {
		if(!mp[x]) {
			mp[x] = ++cnt;
			to[cnt] = x;
		}
	}
	for(int i = 1; i <= n; i++) s[i].r = mp[s[i].r];
	for(int i = 1; i <= q; i++) t[i].r = mp[t[i].r]; 
	std::sort(s + 1, s + n + 1, cmp);
	std::sort(t + 1, t + q + 1, cmp);
	int now = 1;
	for(int i = 1; i <= q; i++) {
		while(true) {
			if(now == n + 1) break;
			if(s[now].l >= t[i].l) {
				insert(s[now].r, to[s[now].r] - s[now].l + 1);
				now++;
			}
			else break;
		}
		ans[t[i].id] = query(t[i].r);
	}

	for(int i = 1; i <= q; i++) {
		std::cout << ans[i] << '\n';
	}
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
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
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
