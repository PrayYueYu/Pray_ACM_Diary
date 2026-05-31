#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 5e5, mod = 998244353, INF = 1e18;
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
std::map<int, int> las, fir;
void init() {
	las.clear();
	fir.clear();
}
void print(int x) {
	if(x < 0) {
		putchar('-');
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
	n = read();
	int L = 0, R = 0;
	__int128 ans = 0;
	for(int i = 1; i <= n; i++) {
		int a = read(), to = i;
		if(L <= a && a <= R) {
			if(!fir[a] || fir[a] < las[a - 1]) {
				fir[a] = las[a - 1] + 1;
				to = las[a - 1] + 1;
			}
			else {
				to = fir[a];
			}
			R = a + 1;
		}
		else {
			L = R = a + 1;
			to = 1;
			fir[a] = i;
		}
		las[a] = i;
		ans += (n - i + 1) * (i - to + 1);
	}
	print(ans);
	std::cout << '\n';
}
signed main() {
	int T; T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
