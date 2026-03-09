#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, p, a[N];
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
void solve() {
	std::multiset<int> s;
	n = read(), p = read();
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		sum += a[i]; sum %= p;
		s.insert(sum);
	}
	int maxn = -INF, l = 0, r = 0, re = 0;
	for(int i = 1; i <= n; i++) {
		auto it = s.lower_bound(re);
		auto itm = s.end(); itm--;
		int now = 0;
		if(it == s.begin()) {
			now = (*itm); 
			now -= re;
		}
		else {
			it--;
			now = std::max((*itm) - re, (*it) - re + p);
		}
		if(maxn < now) {
			maxn = now;
			l = i;
		}
		re = (re + a[i]) % p;
		it = s.find(re);
		s.erase(it);
		//每次向后挪动的时候，\sum{1~i}这个就失效了，需要删除 
	}
	sum = 0;
	for(int i = l; i <= n; i++) {
		sum += a[i];
		sum %= p;
		if(sum == maxn) {
			r = i;
			break;
		}
	}
	std::cout << l - 1 << ' ' << r - 1 << ' ' << maxn;
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

*/
