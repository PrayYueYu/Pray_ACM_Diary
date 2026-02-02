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
string check(int l, int r) {
	string ans = "";
	for(int i = l; i <= r; i++) ans += s[i];
	return ans;
}
void solve() {
	n = read();
	cin >> s;
	s = " " + s;
	int f1 = false, f2 = true;
	for(int i = 1; i <= n; i++) {
		if(i >= 4) {
			if(check(i - 3, i) == "2026") f1 = true;
			else if(check(i - 3, i) == "2025") f2 = false;
		}
	}
	if(!f1 && !f2) {
		cout << 1 << endl;
		return;
	}
	cout << 0 << endl;
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
