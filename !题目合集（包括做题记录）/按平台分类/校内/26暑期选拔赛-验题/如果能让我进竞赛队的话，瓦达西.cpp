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
	int maxodd = k, ans = 0, maxev = k;
	if(!(maxodd & 1)) maxodd--;
	if(maxev & 1) maxev--;
	if(n & 1) n -= maxodd, ans++;
	if(n > k) {
		if(n % maxev == 0) ans += n / maxev;
		else ans += n / maxev + 1;
	}
	else if(n) ans++;
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

*/
