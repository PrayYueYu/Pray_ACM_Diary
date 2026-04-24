#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, f[N], p[200], a[200];
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
int del(int x, int t) {
	return x - p[t];
}
void init() {
	for(int i = 0; i < (1 << 20); i++) {
		f[i] = 0;
	}
}
int getc(int x) {
	int sum = 0;
	for(int i = 0; i < 20; i++) {
		if((x >> i & 1)) sum++;
	}
	return sum;
}
std::queue<int> q;
void solve() {
	n = read();
	for(int i = 0; i < n; i++) {
		a[i] = read();
//		xo = xo ^ a[i];
	}
	int ALL = (1 << n) - 1;
	for(int i = 1; i <= ALL; i++) {
		int sum = 0;
		for(int j = 0; j < n; j++) {
			if(!(i >> j & 1)) continue;
			sum = sum ^ a[j];
		}
		for(int j = 0; j < n; j++) {
			if(!(i >> j & 1)) continue;
			if(a[j] > (sum ^ a[j])) {
				if(!f[del(i, j)]) {
					f[i] = 1;
					break;
				}
			}
		}
	}
	if(f[ALL]) std::cout << "Left\n";
	else std::cout << "Right\n";
}
signed main() {
	p[0] = 1;
	for(int i = 1; i <= 20; i++) p[i] = p[i - 1] * 2;
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
