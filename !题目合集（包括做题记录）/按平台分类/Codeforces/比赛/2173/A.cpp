#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7, INF = 1e18;
int n, k;
string s;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}

void solve() {
	n = read(), k = read();
	cin >> s;
	s = " " + s;
	int ans = 0, f = 0;
	for(int i = 1; i <= n; i++) {
		if(!f) {
			if(s[i] == '0') ans++;
			else f = k;
		}
		else {
			if(s[i] == '0') f--;
			else f = k;
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
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
