#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, p2[300];
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
int ask(int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	int x = read();
	return x;
}
void Find(int x) {
	cout << "! " << x << endl;
}
void solve() {
	n = read();
	if(n == 1) {
		Find(ask(1, 1));
		return;
	}
	int now = ask(1, n);
	now /= 2;
	int L = 1, R = n;
	while(true) {
		int l = L, r = R;
		while(l < r) {
			int mid = (l + r) >> 1;
			int x = ask(L, mid);
			if(x >= now) r = mid;
			else l = mid + 1;
		}
		if(l == L || l == R - 1) {
			Find(now);
			return;
		}
		if(l - L < R - (l + 1)) R = l;
		else L = l + 1;
		if(now == 1) break;
		now /= 2;
	}
}
signed main() {
	p2[0] = 1;
	for(int i = 1; i <= 60; i++) p2[i] = p2[i - 1] * 2;
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
