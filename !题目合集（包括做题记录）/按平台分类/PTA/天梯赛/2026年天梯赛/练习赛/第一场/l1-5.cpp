#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;

int read() {
//	int x = 0, f = 1;
//	char ch = getchar();
//	while(ch < '0' || ch > '9') {
//		if(ch == '-') f = -1;
//		ch = getchar();
//	}
//	while(ch >= '0' && ch <= '9') {
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//	return x * f;
	int x;
	std::cin >> x;
	return x;
}
void solve() {
	std::string s;
	getline(std::cin, s);
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '6') cnt++;
		else {
			if(cnt > 9) {
				std::cout << "27";
			}
			else if(cnt > 3) std::cout << '9';
			else {
				for(int j = 1; j <= cnt; j++) std::cout << '6';
			}
			cnt = 0;
			std::cout << s[i];
		}
	}
	if(cnt > 9) {
		std::cout << "27";
	}
	else if(cnt > 3) std::cout << '9';
	else {
		for(int j = 1; j <= cnt; j++) std::cout << '6';
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
