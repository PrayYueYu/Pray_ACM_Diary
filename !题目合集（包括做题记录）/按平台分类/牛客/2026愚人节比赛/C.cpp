#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, f[N][5];
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
	std::string s;
	std::cin >> s;
	for(int i = 0; i < s.size(); i++) {
		for(int j = 1; j <= 4; j++) {
			f[i][j] = 0;
		}
	}
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	for(int i = 0; i < s.size(); i++) {
		if(i)
			for(int j = 1; j <= 4; j++) {
				f[i][j] = f[i - 1][j];
			}
		if(s[i] == 'g') f[i][1]++;
		else if(s[i] == 'o' && i) f[i][2] += f[i - 1][1];
		else if(s[i] == 'l' && i) f[i][3] += f[i - 1][2];
		else if(s[i] == 'd' && i) f[i][4] += f[i - 1][3];
		for(int j = 1; j <= 4; j++) {
			f[i][j] %= mod;
		}
		if(s[i] == 'g') cnt1++;
		if(s[i] == 'i') cnt2++;
		if(s[i] == 'r') cnt3++;
		if(s[i] == 'l') cnt4++;
	}
	int ans = f[s.size() - 1][4] * cnt1 % mod;
	ans = ans * cnt2 % mod;
	ans = ans * cnt3 % mod;
	ans = ans * cnt4 % mod;
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
