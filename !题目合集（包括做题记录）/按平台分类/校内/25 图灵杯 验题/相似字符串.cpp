#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7, INF = 1e18;
string s1, s2;
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
	cin >> s1 >> s2;
	int l1 = s1.size(), l2 = s2.size();
	if(l1 != l2) {
		cout << "NO\n";
		return;
	}
	for(int i = 0; i < l1; i++) {
		if(s1[i] != s2[i]) {
			if(s1[i] == 'l' && s2[i] == 'I') continue;
			if(s1[i] == 'I' && s2[i] == 'l') continue;
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
-------------------------------
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
-------------------------------
*/
