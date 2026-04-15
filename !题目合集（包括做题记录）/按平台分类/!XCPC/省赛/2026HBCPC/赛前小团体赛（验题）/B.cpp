#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 20, mod = 998244353;
int f[N][3], las[N];
void solve() {
	std::string s;
	std::cin >> s;
	int len = s.size();
	f[0][0] = 1, f[0][1] = 1;
	for(int i = 1; i <= len; i++) f[i][0] = f[i][1] = 0;
	for(int i = 0; i <= 222; i++) las[i] = -1;
	las[s[0]] = 0;
	for(int i = 1; i < len; i++) {
		f[i][0] = f[i - 1][0] + f[i - 1][1];
		f[i][1] = f[i - 1][0] + f[i - 1][1];
		f[i][0] %= mod;
		f[i][1] %= mod;
		if(las[s[i]] != -1) {
			f[i][1] -= f[las[s[i]]][0];
			f[i][1] = (f[i][1] + mod) % mod;
		}
		las[s[i]] = i;
	}
	std::cout << (f[len - 1][0] + f[len - 1][1]) % mod << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	int T; std::cin >> T;
	while(T--) solve();
	return 0;
}
/*
6
LoL
Ahhhh
ERRATA
0000FF
R3GuLaM1N
ILoveYou
*/
