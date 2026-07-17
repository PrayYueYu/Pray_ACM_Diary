#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;

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
bool check(char c) {
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	return false;
}
void solve() {
	std::string s;
	std::cin >> s;
	if(s.size() != 8) {
		std::cout << "Well-Being\n";
		return;
	}
	for(int i = 0; i < 8; i += 2) {
		if(check(s[i])) {
			std::cout << "Well-Being\n";
			return;
		}
	}
	for(int i = 1; i < 8; i += 2) {
		if(!check(s[i])) {
			std::cout << "Well-Being\n";
			return;
		}
	}
	std::cout << "Suspected Virus\n";
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
	Writer: ÔÂö§Þ±‹¬ 
*/
