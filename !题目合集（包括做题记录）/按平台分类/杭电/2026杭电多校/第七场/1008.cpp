#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, w;
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

void solve() {
	std::cin >> n >> w;
	std::cin >> s;
	int f1 = -1, f2 = -1;
	std::cout << "Yes\n";
	for(int i = 0; i <= n - 2; i++) {
		if(s[i] == '|' || s[i] == '^') {
			if(f1 == -1) f1 = i;
			else {
				f2 = i;
				break;
			}
		}
	}
	if(f1 == -1) {
		for(int i = 0; i < n; i++) std::cout << w << ' ';
		std::cout << '\n';
		return;
	}
	if(f2 == -1) {
		for(int i = 0; i <= f1; i++) std::cout << w << ' ';
		for(int i = f1 + 1; i < n; i++) std::cout << "0 ";
		std::cout << '\n';
		return;
	}
	for(int i = 0; i <= f1; i++) std::cout << "0 ";
	for(int i = f1 + 1; i <= f2; i++) std::cout << w << ' ';
	for(int i = f2 + 1; i <= n - 1; i++) std::cout << "0 ";
	std::cout << '\n';
}
signed main() {
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
