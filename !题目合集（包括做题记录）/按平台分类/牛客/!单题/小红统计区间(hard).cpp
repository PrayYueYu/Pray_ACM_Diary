#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int a[N], sum[N], tr[N], n, k;
int read() {
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
int lowbit(int x) {
	return x & (-x);
}
void add(int x, int c) {
	while(x <= n) {
		tr[x] += c;
		x += lowbit(x);
	}
}
int query(int x) {
	int ans = 0;
	while(x) {
		ans += tr[x];
		x -= lowbit(x);
	}
	return ans;
}
void solve() {
	n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	std::vector<int> v;
	std::map<int, int> mp;
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		v.push_back(sum[i]);
	}
	sort(v.begin(), v.end());
	int cnt = 0, ans = 0;
	for(auto x: v) {
		if(!mp[x]) mp[x] = ++cnt;
	}
	for(int i = 1; i <= n; i++) {
		sum[i] = mp[sum[i]];
		add(sum[i], 1);
	}
	for(int i = 1; i <= n; i++) {
		auto it = lower_bound(v.begin(), v.end(), k);
		if(it == v.end()) {
			k += a[i];
			add(sum[i], -1);
			continue;
		}
		int x = (*it);
		x = mp[x];
		ans += (n - i + 1) - query(x - 1);
		k += a[i];
		add(sum[i], -1);
	}
	std::cout << ans << '\n';
	
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
