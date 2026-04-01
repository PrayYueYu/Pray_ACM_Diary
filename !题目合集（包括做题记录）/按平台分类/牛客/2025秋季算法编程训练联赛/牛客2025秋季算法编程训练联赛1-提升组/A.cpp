#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 1e9 + 7;
int n, m, ans;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
signed main() {
	n = read(), m = read();
	if(m >= 2 && n >= 3) {
		int s = (m - 1) * (n - 2);
		s %= M;
		s = (s * 2 * n) % M;
		ans = (ans + s) % M;
	}
	if(n >= 2 && m >= 3) {
		int s = (n - 1) * (m - 2);
		s %= M;
		s = (s * 2 * m) % M;
		ans = (ans + s) % M;
	}
	if(m >= 3 && n >= 2) {
		int s = (m - 2) * (n - 1);
		s %= M;
		s = (s * (n - 2) * 2) % M;
		ans = (ans + s) % M;
	}
	if(n >= 3 && m >= 2) {
		int s = (n - 2) * (m - 1);
		s %= M;
		s = (s * (m - 2) * 2) % M;
		ans = (ans + s) % M;
	} 
	cout << ans;
	return 0;
}
