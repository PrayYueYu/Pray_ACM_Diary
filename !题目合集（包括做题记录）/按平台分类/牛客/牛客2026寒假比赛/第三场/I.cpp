#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], b[N];
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
std::bitset<N> bs[40], now;
int from[40], p[40];
void init() {
	for(int i = 0; i <= 35; i++) {
		p[i] = from[i] = 0;
		bs[i].reset();
	}
	now.reset();
}
void insert(int x, int id) {
	int mask = 0;
	for(int i = 32; i >= 0; i--) {
		int f = (x >> i) & 1;
		if(!f) continue;
		if(!p[i]) {
			p[i] = x;
			from[i] = mask;
			bs[i].set(id);
			return;
		}
		x = x ^ p[i];
		mask |= (1ll << i);
	}
}
void GetSource() {
	for(int i = 31; i >= 0; i--) {
		for(int j = i + 1; j <= 32; j++) {
			if((from[i] >> j) & 1) {
				bs[i] ^= bs[j];
			}
		}
	}
}
void solve() {
	n = read();
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		sum = sum ^ a[i];
	}
	for(int i = 1; i <= n; i++) {
		b[i] = read();
		int x = a[i] ^ b[i];
		insert(x, i);
	}
	if(!sum) {
		for(int i = 1; i <= n; i++) std::cout << a[i] << ' ';
		std::cout << '\n';
		return;
	}
	GetSource();
	for(int i = 32; i >= 0; i--) {
		if((sum >> i) & 1) {
			if(!p[i]) {
				std::cout << -1 << '\n';
				return;
			}
			sum ^= p[i];
			now ^= bs[i];
		}
	}
	for(int i = 1; i <= n; i++) {
		if(now.test(i)) std::cout << b[i] << ' ';
		else std::cout << a[i] << ' ';
	}
	std::cout << '\n';
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
