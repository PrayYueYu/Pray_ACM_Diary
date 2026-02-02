#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
string s;
int n;
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
	cin >> s;
	n = s.size();
	s = " " + s;
	int ans = 0, l = 0, r = 0, cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'u') {
			if(!l) l = i;
			r = i;
			cnt++;
		}
		else {
			if(!cnt) continue;
			if(l == 1) cnt--, ans++;
			if(r == n) cnt--, ans++;
			ans += (cnt / 2);
			cnt = l = r = 0;
		}
	} 
	if(cnt) {
		if(l == 1) cnt--, ans++;
		if(r == n) cnt--, ans++;
		ans += (cnt / 2);
		cnt = l = r = 0;
	}
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
