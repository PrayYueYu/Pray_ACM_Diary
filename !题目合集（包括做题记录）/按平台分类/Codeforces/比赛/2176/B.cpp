#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7;
int n, m;
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
	string s;
	cin >> s;
	s = " " + s + s;
	n *= 2;
	int cnt = 0, ans = -1;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '0') cnt++;
		else {
			ans = max(ans, cnt);
			cnt = 0;
		}
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
