#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], k, x, b[N], cnt;
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
void Print(int d) {
	for(int i = d + 1; i <= n; i++) {
		std::cout << a[i] << ' ';
		b[++cnt] = a[i];
	}
	for(int i = 1; i <= d; i++) {
		std::cout << a[i] << ' ';
		b[++cnt] = a[i];
	}
}
void solve() {
	std::cin >> n >> k >> x;
	k++;
	int id = 0;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if(a[i] == x) id = i;
	}
	int del = id - k;
	if(del < 0) del += n;
	Print(del);
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
	Writer: ÔÂö§Þ±‹¬ 
*/
