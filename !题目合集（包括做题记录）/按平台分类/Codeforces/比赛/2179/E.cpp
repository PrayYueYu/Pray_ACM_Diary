#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N][3], x, y, p[N];
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
	n = read(), x = read(), y = read();
	int xx = x, yy = y;
	string s = "";
	cin >> s;
	s = " " + s;
	for(int i = 1; i <= n; i++) p[i] = read();
	int f1 = 0, f0 = 0, sum = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '0') f0 = true;
		else f1 = true;
		int s1 = s[i] - '0', s2 = 0;
		if(!s1) s2 = 1;
		if(p[i] & 1){
			a[i][s1] = (p[i] + 1) / 2;
			a[i][s2] = p[i] / 2;
		}
		else {
			a[i][s1] = p[i] / 2 + 1;
			a[i][s2] = p[i] / 2 - 1;
		}
		x -= a[i][0];
		y -= a[i][1];
		sum += p[i];
	}
	if(x < 0 && y < 0) {
		cout << "NO\n";
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(x < 0 && s[i] == '1') {
			int t = min({-x, y, a[i][0]});
			x += t;
			a[i][1] += t;
			a[i][0] -= t;
			y -= t;
		}
		else if(y < 0 && s[i] == '0') {
			int t = min({-y, x, a[i][1]});
			y += t;
			a[i][0] += t;
			a[i][1] -= t;
			x -= t;
		}
	}
	if(x < 0 || y < 0 || sum > xx + yy) {
		cout << "NO\n";
		return;
	}
	if(!f0) {
		if(yy - xx < n) {
			cout << "NO\n";
		}
		else cout << "YES\n";
		return;
	}
	if(!f1) {
		if(xx - yy < n) {
			cout << "NO\n";
		}
		else cout << "YES\n";
		return;
	}
	cout << "YES\n";
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
