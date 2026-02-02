#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int a[N];
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
map<int, int> mp;
void solve() {
	int n = read(), k = read(), l = read(), r = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	int R = 0, L = 0, ans = 0, num = 0;
	mp.clear();
	for(int i = 1; i <= n; i++) {
		if(i > 1) {
			mp[a[i - 1]]--;
			if(!mp[a[i - 1]]) num--;
		}
		while(true) {
			if(L - i + 1 >= l) break;
			if(L == n) break;
			L++;
			if(!mp[a[L]]) num++;
			mp[a[L]]++;
		}//把L移动到需要的区间 
		while(true) {
			if(L - i + 1 == r) break;
			if(L == n) break;
			if(num >= k) break;
			L++;
			if(!mp[a[L]]) num++;
			mp[a[L]]++;
		}//移动到num=k处 
		R = max(R, L);
		while(true) {
			if(R - i + 1 == r) break;
			if(num != k) break;
			if(R == n) break;
			if(!mp[a[R + 1]]) break;
			R++;
		}
		int lx = i + l - 1, rx = i + r - 1;
		rx = min(rx, n);
		if(lx > n) continue;
		int ly = max(lx, L), ry = min(rx, R);
		if(ly <= ry && num == k) ans += ry - ly + 1;
	}
	cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
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
