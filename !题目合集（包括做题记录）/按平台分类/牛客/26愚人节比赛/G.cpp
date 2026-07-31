#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int to[20];
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
	int n = read(), f = false;
	to[0] = 4;
	to[1] = 8;
	to[2] = 2;
	to[3] = 6;//
	to[4] = 0;
	to[5] = 4;
	to[6] = 8;
	to[7] = 2;//
	to[8] = 6;//
	to[9] = 0;//
	int ans = 0;
	while(true) {
		int x = n % 10;
		ans = ans * 10 + to[x];
		n /= 10;
		if(!n) break;
	}
	std::cout << ans;
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

*/
