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
	int a = read(), b = read(), y1 = read(), y2 = read();
	if(y1 < a && y2 < a) {
		std::cout << y1 << "-N " << y2 << "-N\n";
		std::cout << "zhang da zai lai ba";
	}
	else if(y1 >= a && y2 >= a) {
		std::cout << y1 << "-Y " << y2 << "-Y\n";
		std::cout << "huan ying ru guan";
	}
	else if(y1 < a && y2 < b) {
		std::cout << y1 << "-N " << y2 << "-Y\n";
		std::cout << "2: huan ying ru guan";
	}
	else if((y1 < a && y2 >= b) || (y2 < a && y1 >= b)) {
		if(y2 > y1) {
			std::cout << y1 << "-Y " << y2 << "-Y\n";
			std::cout << "qing 2 zhao gu hao 1";
		}
		else {
			std::cout << y1 << "-Y " << y2 << "-Y\n";
			std::cout << "qing 1 zhao gu hao 2";
		}
	}
	else {
		std::cout << y1 << "-Y " << y2 << "-N\n";
		std::cout << "1: huan ying ru guan";
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
