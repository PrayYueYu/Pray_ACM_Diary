#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e7 + 10, mod = 1e9 + 7;
int n, inv2;
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
void solve() {
	n = read();
	int s = ksm(3, n) - 1;
	s = (s + mod) % mod;
	s = (s * inv2) % mod;
	cout << s << '\n';
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	inv2 = ksm(2, mod - 2);
	int T = read();
	while(T--) solve();
    return 0;
}
