#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7, INF = 2e18;
int n, h;
int read() {
	int x;
	cin >> x;
	return x;
}
int query1(int l, int r, int x, int y) {
	if(y < l || r < x) return -INF;
	if(l <= x) return x;
	return l;
}
int query2(int l, int r, int x, int y) {
	if(y < l || r < x) return -INF;
	if(y <= r) return y;
	return r;
}
void solve() {
	n = read(); h = 0; 
	int nowl = h, nowr = h, last = 0, f = 1;
	for(int i = 1; i <= n; i++) {
		int t = read();
		int l = read(), r = read();
		int d = t - last, lx = nowl;
		nowl = query1(l, r, lx - d, nowr + d);
		nowr = query2(l, r, lx - d, nowr + d);
//		cout << nowl << ' ' << nowr << '\n';
		if(nowl == -INF || nowr == -INF) {
			f = -1;
		}
		last = t;
//		cout << f << '\n';
	}
	if(f == -1) cout << "NO\n";
	else cout << "YES\n";
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

*/
