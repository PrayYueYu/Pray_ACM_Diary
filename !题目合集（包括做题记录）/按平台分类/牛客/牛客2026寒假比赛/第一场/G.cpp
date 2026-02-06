#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;

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
int calc(int x, int t) {
	for(int i = 1; i < t; i++) x /= 10;
	return x % 10;
}
int re(int x) {
	int ans = 0;
	while(true) {
		if(!x) break;
		ans = ans * 10 + x % 10;
		x /= 10;
	}
	return ans;
}
std::map<int, int> mp;
void solve() {
	int l = read(), r = read();
	if(l == r) {
		std::cout << re(l) << '\n';
		return;
	}
	if(mp[r]) r--;
	if(r == l) {
		std::cout << re(l) << '\n';
		return;
	}
	int rx = r, minn = 1;
	while(true) {
		if(!rx) break;
		rx /= 10;
		minn *= 10;
	}
	minn /= 10;
	if(l < minn) l = minn;
	int now = l, ad = 1, t = 1;
	while(true) {
		if(ad >= 10000000000000000) break;
		if(calc(now, t) == 9) {
			t++;
			ad *= 10;
			continue;
		}
		if(now + ad > r) {
			t++;
			ad *= 10;
			continue;
		}
		now += ad;
	}
	std::cout << re(now) << '\n';
}
signed main() {
	int t = 1;
	for(int i = 1; i <= 15; i++) {
		t *= 10;
		mp[t] = true;
	}
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
