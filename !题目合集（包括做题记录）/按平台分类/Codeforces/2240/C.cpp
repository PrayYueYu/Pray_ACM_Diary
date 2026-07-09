#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, r, c;
int a[N];
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
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    if(n == 1) {
        std::cout << 0 << '\n';
        return;
    }
    int ans = 0, Xor = 0;
    for(int i = 1; i <= n; i++) {
        Xor ^= a[i];
    }
    if(Xor == 0) {
        std::cout << 1 << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        if((Xor ^ a[i]) <= a[i]) ans++;
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
	Writer: 月雩·薇嫭
*/
