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
	std::string s, t = "isallyouneed", ans = "";
	std::cin >> s;
	int f = true;
	for(int i = s.size() - 12; i < s.size(); i++) {
		if(s[i] != t[i - (s.size() - 12)]) {
			f = false;
		}
	}
	for(int i = 0; i < s.size() - 12; i++) ans += s[i];
	if(f) std::cout << "Yes\n" << ans;
	else std::cout << "No";
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
