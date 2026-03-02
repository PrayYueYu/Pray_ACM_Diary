#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;

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
	std::string t1 = "", t2 = "", s1 = "", s2 = "";
	std::cin >> t1 >> t2;
	for(int i = 1; i < t1.size(); i++) {
		if(t1[i] % 2 == t1[i - 1] % 2) 
			s1 += (char)std::max(t1[i - 1], t1[i]);
	}
	for(int i = 1; i < t2.size(); i++) {
		if(t2[i] % 2 == t2[i - 1] % 2) 
			s2 += (char)std::max(t2[i - 1], t2[i]);
	}
	if(s1 == s2) std::cout << s1;
	else std::cout << s1 << '\n' << s2;
}
signed main() {
	int T = 1;
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
