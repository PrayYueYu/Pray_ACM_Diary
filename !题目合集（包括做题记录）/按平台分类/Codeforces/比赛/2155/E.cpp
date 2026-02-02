#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], b[N], m, k;
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
	n = read(), m = read(), k = read();
	for(int i = 1; i <= k; i++) {
		a[i] = read(), b[i] = read();
	}
	if(n == 1) {
		int f = 0;
		for(int i = 1; i <= k; i++) {
			if(b[i] == 2) f ^= 1;
		}
		if(f) cout << "Mimo\n";
		else cout << "Yuyu\n";
		return;
	}
	int cnt = 0, f = 0;
	sort(b + 1, b + k + 1);
	for(int i = k; i >= 1; i--) {
		if(b[i] == 1) continue;
		cnt ^= 1;
		if(b[i] != b[i - 1]) {
			f ^= cnt;
			if(f) {
				cout << "Mimo\n";
				return;
			}
			cnt = 0;
		}
	}
	cout << "Yuyu\n";
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
*/
