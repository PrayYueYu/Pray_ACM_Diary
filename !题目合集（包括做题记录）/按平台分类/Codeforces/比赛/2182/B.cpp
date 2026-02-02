#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;

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
	int a = read(), b = read();
	int ans = 0, cnt = 0, now = 1, f = 0;
	int aa = a, bb = b;
	while(true) {
		if(f == 0) {
			if(a - now < 0) break;
			a -= now;
			f = 1;
			cnt++;
			now *= 2;
		}
		else {
			if(b - now < 0) break;
			b -= now;
			f = 0;
			cnt++;
			now *= 2;
		}
	}
	ans = max(ans, cnt);
	now = 1, f = 1, cnt = 0;
	a = aa, b = bb;
	while(true) {
		if(f == 0) {
			if(a - now < 0) break;
			a -= now;
			f = 1;
			cnt++;
			now *= 2;
		}
		else {
			if(b - now < 0) break;
			b -= now;
			f = 0;
			cnt++;
			now *= 2;
		}		
	}
	ans = max(ans, cnt);
	cout << ans << '\n';
}
signed main() {
	int T = read();
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
