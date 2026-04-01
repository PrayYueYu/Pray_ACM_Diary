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
std::map<std::string, int> mp;
void solve() {
	std::string s1, s2, now = "";
	std::cin >> s1 >> s2;
	int ans = 0;
	for(int i = 0; i < s1.size(); i++) {
		if(s1[i] <= 'Z' && s1[i] >= 'A') ans++;
	}
	std::cout << ans;
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
ß÷ ¡ª¡ª ß÷ ¡ª¡ª ß÷ ¡ª¡ª
MiaoMiaoMiao
*/
