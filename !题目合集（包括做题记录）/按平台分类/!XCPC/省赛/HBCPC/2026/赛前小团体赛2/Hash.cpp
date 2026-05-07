#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int g[200], hash[N], p[N], len, invp[N], f[N];
std::string s;
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
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ans;
}
int get_hash(int l, int r) {
	if(l > r || r > 2 * len || l < 1) return -1;
	int ans = hash[r] - hash[l - 1];
	ans = (ans % mod + mod) % mod;
	ans = (ans * invp[2 * len - r]) % mod;
//	int ans = 0, n = r - l + 1;
//	for(int i = l; i <= r; i++) {
//		ans = ans + g[s[i]] * p[n - (i - l + 1)];
//		ans %= mod;
//	}
	return ans;
}
void solve() {
	std::cin >> s;
	len = s.size();
	s = s + s; s = " " + s;
	for(int i = 1; i <= 2 * len; i++) {
		hash[i] = hash[i - 1] + g[s[i]] * p[2 * len - i];
		hash[i] %= mod;
	}
	int ans = -1;
	for(int i = 1; i <= 2 * len; i++) {
		ans = std::max(ans, get_hash(i, i + len - 1));
	}
	for(int st = 1; st <= 16; st++) {
		if(st > len) break;
		for(int i = 0; i <= 2 * len; i++) f[i] = 0;
		for(int i = st; i <= st + len - 1; i++) {
			for(int j = i - 16; j <= i - 1; j++) {
				if(j < st - 1) continue;
				f[i] = std::max(f[i], f[j] + get_hash(j + 1, i));
			}
		}
		ans = std::max(ans, f[st + len - 1]);
	}
	std::cout << ans;
}
signed main() {
	p[0] = 1;
	for(int i = 1; i <= 400000; i++) {
		p[i] = p[i - 1] * 31;
		p[i] %= mod;
	}
	for(int i = 1; i <= 400000; i++) {
		invp[i] = ksm(p[i], mod - 2);
	}
	g['a'] = 1;
	g['e'] = 2;
	g['h'] = 3;
	g['n'] = 4;
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
