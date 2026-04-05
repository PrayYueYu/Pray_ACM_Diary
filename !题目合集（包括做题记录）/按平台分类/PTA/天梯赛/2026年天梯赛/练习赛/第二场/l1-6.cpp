#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
std::string s[N];
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
	char c; std::cin >> c;
	int n = read(), f = true;
	for(int i = 1; i <= n; i++) {
		getline(std::cin, s[i]);
		for(int j = 0; j < s[i].size(); j++) {
			if(s[i][j] != s[i][s[i].size() - 1 - j]) {
				f = false;
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < s[i].size(); j++) {
			if(s[n - i + 1].size() - 1 < j) {
				f = false;
				break;
			}
			if(s[i][j] != s[n - i + 1][j]) {
				f = false;
				break;
			}
		}
	}
	if(f) {
		std::cout << "bu yong dao le\n";
	}
	for(int i = n; i >= 1; i--) {
		for(int j = s[i].size() - 1; j >= 0; j--) {
			if(s[i][j] != ' ') std::cout << c;
			else std::cout << ' ';
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
