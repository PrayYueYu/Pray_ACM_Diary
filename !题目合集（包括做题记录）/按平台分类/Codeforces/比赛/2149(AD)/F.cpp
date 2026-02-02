#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int h, d;
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
int calc(int x) {
	return ((x + 1) * x) / 2ll;
}
int f(int x) {
	int l = d / (x + 1);
	int a = d - (x + 1) * l;//(d mod (x+1))
	int b = (x + 1) - a;
	return max(calc(l + 1) * a + calc(l) * b - h + 1, x);
}
void solve() {
	h = read(), d = read();
	int l = 0, r = d;
	while(r - l > 2) {
		int lmid = l + (r - l) / 3;
		int rmid = r - (r - l) / 3;
		if(f(lmid) < f(rmid)) r = rmid;
		else l = lmid;
	}
	int ans = INF;
	for(int i = l; i <= r; i++) ans = min(ans, f(i));
	
	cout << ans + d << '\n';
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
