#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
std::string s;
int n, ans[400][400];
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
	n = read();
	std::cin >> s;
	int l = 1, r = n;
	int a = 1, b = n;
	int i = 0;
	for(int c = 1; c <= n / 2; c++) {
//		if(l == r) {
//			
//		}
		for(int j = l; j <= r; j++) {
			if(j == l) {
				for(int k = l; k <= r; k++) {
					if(!ans[j][k]) ans[j][k] = s[i];
				}
				int mid = (1 + n) / 2;
				ans[j + 1][mid] = s[i];
			}
			else if(j <= (l + r) / 2) {
				ans[j][a] = ans[j][b] = s[i];
			}
			else {
				a++; b--;
				ans[j][a] = ans[j][b] = s[i];
			}
		}
		l++, r--;
		a = l, b = r;
		i++;
		if(i == s.size()) i = 0;
	}
	ans[1][1] = ans[1][n] = ans[1][(1 + n) / 2] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(ans[i][j]) std::cout << (char)ans[i][j];
			else std::cout << '-';
		}
		std::cout << '\n';
	}
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

*/
