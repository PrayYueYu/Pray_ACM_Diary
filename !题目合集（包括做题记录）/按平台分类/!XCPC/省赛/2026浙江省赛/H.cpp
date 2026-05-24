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
void solve() {
	std::string s, now = "";
	std::cin >> s;
	if(s.size() < 12) {
		std::cout << "NO\n";
		return;
	}
	for(int i = 0 ; i < 9; i++) {
		now += s[i];
	} 
	if(now != "ucup-team") {
		std::cout << "NO\n";
		return;
	}
	int x = 0, f = false, fx = false;
	for(int i = 9; i < s.size(); i++) {
		x = x * 10 + s[i] - '0';
		if(s[i] < '0' || s[i] > '9') {
			std::cout << "NO\n";
			return;
		}
		if(s[i] >= '1' && s[i] <= '9') {
			fx = true;
		}
		if(s[i] == '0' && !fx) {
			std::cout << "NO\n";
			return;
		}
		if(x >= 100) {
			f = true;
		}
	}
	
	if(f) std::cout << "YES\n";
	else std::cout << "NO\n";
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
