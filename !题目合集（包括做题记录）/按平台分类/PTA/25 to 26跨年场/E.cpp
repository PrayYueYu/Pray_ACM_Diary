#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
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
	int n = read();
	for(int i = 1; i <= n; i++) {
		string a, b;
		string s1 = "", s2 = "";
		std::cin >> a >> b;
		int l1 = a.size(), l2 = b.size();
		int ans1 = 0, ans2 = -1, f1 = 0, f2 = 0;
		for(int j = 0; j < l1; j++) {
			if(a[j] != '0' && a[j] != '.') f1 = 1;
			if(f1) s1 += a[j];
		}
		for(int j = 0; j < l2; j++) {
			if(b[j] != '0' && b[j] != '.') f2 = 1;
			if(f2) s2 += b[j];
		}
		if(s1.size() > s2.size()) ans1 = 0;
		else if(s1.size() < s2.size()) ans1 = 1;
		else {
			if(s1 > s2) ans1 = 0;
			else ans1 = 1;
		}
		for(int j = 0; j < min(l1, l2); j++) {
			if(a[j] > b[j]) {
				ans2 = 0;
				break;
			}
			if(a[j] < b[j]) {
				ans2 = 1;
				break;
			}
		}
		if(ans2 == -1) {
			if(l1 == l2) ans2 = 0;
			else if(l1 > l2) ans2 = 0;
			else ans2 = 1;
		}
		if(ans1) std::cout << b;
		else std::cout << a;
		std::cout << ' ';
		if(ans2) std::cout << b;
		else std::cout << a;
		std::cout << '\n';
	}
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
