#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], p[N];
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
bool insert(int x) {
	for(int i = 40; i >= 0; i--) {
		int t = (x >> i) & 1;
		if(!t) continue;
		if(!p[i]) {
			p[i] = x;
			return true;
		}
		x ^= p[i];
	}
	return false;
}
void solve() {
	std::cin >> n;
	int ans = 0, sum = 0;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	std::sort(a + 1, a + n + 1);
	for(int i = n; i >= 1; i--) {
		if(insert(a[i])) {
			ans += a[i];
		}
	}
	std::cout << sum - ans << '\n';
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
	Writer: ����ޱ�� 
*/
