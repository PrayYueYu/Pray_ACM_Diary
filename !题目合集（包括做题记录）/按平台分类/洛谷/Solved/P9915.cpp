#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e6 + 9, mod = 998244353;
int n, q;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ans;
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	n = read(), q = read();
	for(int i = 1; i <= q; i++) {
		int x = read(), y = read(), ans = 0;
		if(y > 64) ans = n;
		else {
			ans = y;
			x >>= y;
			int t = x & 1;
			while(true) {
				x >>= 1;
				if((x & 1) == t && ans < n - 1) ans++;
				else break;
			}
			ans++;
		}
		ans = ksm(2, ans) - 1;
		cout << ans << '\n';
	}
    return 0;
}
