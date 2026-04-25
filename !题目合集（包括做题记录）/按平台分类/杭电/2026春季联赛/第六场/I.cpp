#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, p[100], a[N], m;
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
void init() {
	for(int i = 0; i <= 31; i++) {
		p[i] = 0;
	}
}
void insert(int x) {
	int mask = 0;
	for(int i = 31; i >= 0; i--) {
		int f = (x >> i) & 1;
		if(!f) continue;
		if(!p[i]) {
			p[i] = x;
			return;
		}
		x = x ^ p[i];
	}
}
int getmin(int x) {
	for(int i = 31; i >= 0; i--) {
		if((x >> i & 1) && p[i]) x = x ^ p[i];
	}
	return x;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read();
		a[i] = read();
		a[i] = (a[i] ^ x ^ y);
		insert(a[i]);
	} 
	std::cout << getmin(1 ^ n) << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
