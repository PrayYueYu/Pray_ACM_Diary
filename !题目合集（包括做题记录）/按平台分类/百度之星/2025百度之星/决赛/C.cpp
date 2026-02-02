#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 100, INF = 2e18, mod = 1e9 + 7;
int a[N], b[N], n, f[200100][210], c[210];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
int calc(int x) {
	int ans = 1ll;
	for(int i = 1; i <= x; i++) ans = (ans * i) % mod;
	return ans;
}
void solve() {
	n = read();
	if(n == 1) {
		cout << 0 << '\n';
		return;
	}

	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) b[i] = read();
	int ans = 0;
//	cout << s << '\n';
	for(int i = 1; i <= 20000; i++) {
		for(int j = 1; j <= n; j++) {
			f[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 20000; j >= 0; j--) {
			for(int k = i; k >= 2; k--) {
				if(j - b[i] >= 0) {
					if(f[j - b[i]][k - 1] != 0) {
						f[j][k] += f[j - b[i]][k - 1];
						f[j][k] %= mod;
					}
				}
			}
		}
		f[b[i]][1]++;
	}
	c[0] = 1;
	for(int i = 1; i <= n; i++) c[i] = calc(i);
	for(int i = 1; i <= n; i++) {
		if(a[i] > 20000) continue;
		for(int j = 2; j < n; j++) {
			int now = f[a[i]][j];
			if(!now) continue;
			int F = -1, s = a[i];
			for(int k = j - 1; k >= 1; k--) {
				if(s - b[i] >= 0) {
					s -= b[i];
					now = (now + F * f[s][k]) % mod;
					now = (now + mod) % mod;
					F = -F;
					if(s == b[i] && k == 1) {
						now = (now + F) % mod;
					}
				}
			}
			now = (now * c[j]) % mod;
			now = (now * c[n - j - 1]) % mod;
			ans = (ans + now) % mod;
		}
	}
	int s2 = 1ll;
	for(int i = 1; i <= n - 2; i++) {
		s2 = s2 * i;
		s2 %= mod;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			if(a[i] == b[j]) {
				ans = (ans + s2) % mod;
			}
		}
	}
	ans %= mod;
	cout << ans;
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
6
1 2 5 5 4 3
2 2 3 4 1 1

7
1 2 3 7 5 6 7
7 6 5 4 3 2 1

3
1 2 3
2 1 1
*/
