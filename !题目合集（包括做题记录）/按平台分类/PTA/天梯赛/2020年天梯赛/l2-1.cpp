#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
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
std::stack<int> s1;
std::stack<char> s2;
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		int x = read();
		s1.push(x);
	}
	for(int i = 1; i < n; i++) {
		char c; std::cin >> c;
		s2.push(c);
	}
	while(true) {
		if(s1.size() == 1) break;
		int n1 = s1.top(); s1.pop();
		int n2 = s1.top(); s1.pop();
		char c = s2.top(); s2.pop();
		std::swap(n1, n2);
		if(c == '+') s1.push(n1 + n2);
		else if(c == '-') s1.push(n1 - n2);
		else if(c == '*') s1.push(n1 * n2);
		else {
			if(!n2) {
				std::cout << "ERROR: " << n1 << "/0";
				return;
			}
			s1.push(n1 / n2);
		}
	}
	std::cout << s1.top();
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
