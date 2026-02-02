#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n;
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
	std::string s;
	std::cin >> s;
	s = " " + s;
	int cnt = 0;
	std::vector<int> ans;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') cnt++;
	}
	int f = false;
	for(int i = n - cnt + 1; i <= n; i++) {
		if(s[i] == '0') f = true;
	}
	if(!f) {
		std::cout << "Bob\n";
		return;
	}
	std::cout << "Alice\n";
	for(int i = 1; i <= n - cnt; i++) {
		if(s[i] == '1') ans.push_back(i);
	}
	for(int i = n - cnt + 1; i <= n; i++) {
		if(s[i] == '0') ans.push_back(i);
	}
	std::cout << ans.size() << '\n';
	for(auto x: ans) std::cout << x << ' ';
	std::cout << '\n';
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
