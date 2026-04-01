#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int a[N], n;
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
	n = read();
	int cnt = 0, maxn = -1;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(maxn < a[i]) {
			maxn = a[i];
			cnt = 1;
		}
		else if(maxn == a[i]) cnt++;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] == maxn && (cnt & 1)) std::cout << 1;
		else if(a[i] != maxn && !(cnt & 1)) std::cout << 1;
		else std::cout << 0;
	}
	std::cout << '\n';
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
