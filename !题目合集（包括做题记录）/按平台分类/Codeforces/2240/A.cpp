#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, k;
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
	std::cin >> n >> k;
	int ans = 0, sum = 0;
	for(int i = 0; i <= 22; i++) {
		int t = (1 << i);
		if(sum + t * k > n) {
			ans += (n - sum) / t;
			break;
		}
		else {
			sum += t * k;
			ans += k; 
		}
	} 
	std::cout << ans << '\n';
}
signed main() {
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
	Writer: ÔÂö§Ş±‹¬ 
*/
