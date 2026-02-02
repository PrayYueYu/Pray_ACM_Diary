#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e6 + 9;
int n, a[N], q, b[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
map<int, int> mp;
int ksm(int x, int y, int mod) {
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
	while(true) {
		n = read(), q = read();
		for(int i = 1; i <= n; i++) {
//			a[i] = read();
			a[i] = i;
		}
		for(int i = 1; i <= q; i++) {
//			int x = read(), y = read();
			int x = 1, y = 1;
			a[n] = 0;
			for(int j = 1; j <= n; j++) b[j] = a[j];
			int ans = 0;
			while(true) {
				int now = 0, num = 0;
				for(int j = 1; j <= n; j++) {
					now ^= a[j];
					a[j] = now;
					if(a[j] == b[j]) num++;
				}
				ans++;
				if(num == n) break;
			}
			cout << ans << '\n';
		}
	}
    return 0;
}
