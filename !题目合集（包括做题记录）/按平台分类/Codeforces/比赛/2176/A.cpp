#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7;
int n, a[N];
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
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	int now = n, ans = 0;
	while(true) {
		int maxn = -1, id = 0;
		for(int i = 1; i <= now; i++) {
			if(a[i] >= maxn) {
				maxn = a[i];
				id = i;
			}
		}
		ans += now - id;
		now = id - 1;
		if(!now) break;
	}
	cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
*/
