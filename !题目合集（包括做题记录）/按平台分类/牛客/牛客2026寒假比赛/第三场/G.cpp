#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int a[N], b[N], n, m;
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
	n = read(), m = read();
	int suma = 0, sumb = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		suma += a[i];
	}
	for(int i = 1; i <= m; i++) {
		b[i] = read();
		sumb += b[i];
	}
	if(suma == sumb) {
		std::cout << 1 << '\n';
		return;
	}
	std::sort(a + 1, a + n + 1);
	std::sort(b + 1, b + m + 1);
	int ans = 0;
	if(suma > sumb) {
		for(int i = n; i >= 1; i--) {
			suma -= a[i];
			ans++;
			if(suma <= sumb) break;
		}
	}
	else {
		for(int i = m; i >= 1; i--) {
			sumb -= b[i];
			ans++;
			if(sumb <= suma) break;
		}
	}
	std::cout << ans << '\n';
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
