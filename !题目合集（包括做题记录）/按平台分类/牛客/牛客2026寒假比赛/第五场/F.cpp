#include<bits/stdc++.h>
//#define int long long
#define int __int128
const int N = 2e6 + 10, mod = 998244353, INF = 8e20;
int n, a, b;
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
void print(int x) {
	if(x < 0) {
		print(-x);
		return;
	}
	if(x <= 9) {
		putchar(x + '0');
		return;
	}
	print(x / 10);
	putchar(x % 10 + '0');
}
void solve() {
	n = read(), a = read(), b = read();
	if(n <= 1) {
		std::cout << "0\n";
		return;
	}
	int x, y;
	if(n % 56 == 0) {
		x = 0;
		y = n;
	}
	else if(n > 112) {
		x = n % 56 + 56;
		y = (n - x);
	}
	else {
		x = n;
		y = 0;
	}
	y /= 56;
	int maxn = std::max({8 * a, 7 * (a + b), 28 * b});
	y *= maxn;
	maxn = -INF;
	for(int i = 0; i <= 50; i++) {
		for(int j = 0; j <= 45; j++) {
			int now = i * 7 + j * 8;
			if(now > x) break;
			int k = (x - now) / 2;
			maxn = std::max(maxn, i * a + j * (a + b) + k * b);
		}
	}
	if(maxn == -INF) {
		std::cout << "0\n";
		return;
	}
	print(maxn + y);
	printf("\n");
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

*/
