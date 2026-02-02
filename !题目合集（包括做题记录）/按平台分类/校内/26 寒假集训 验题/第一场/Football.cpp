#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 1e9 + 7, INF = 1e18;
int n, a[N][3], ans;
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
	int n = read(), a = read(), b = read();
	if(n == 1) {
		if(a == b) {
			std::cout << 1 << '\n' << a << ':' << b << '\n';
		}
		else std::cout << 0 << '\n' << a << ':' << b << '\n';
		return;
	}
	int f1 = 1, f2 = 0, cnt = 0;
	std::vector<std::pair<int, int>> ans;
	for(int i = 1; i <= n - 1; i++) {
		if(!a && b) f1 = 0, f2 = 1;
		if(!b && a) f2 = 0, f1 = 1;
		if(!a && !b) f1 = f2 = 0;
		ans.push_back({f1, f2});
		a -= f1, b -= f2;
		f1 = 1 - f1, f2 = 1 - f2;
	}
	if(a == b && a) {
		ans[0].first++;
		a--;
		ans.push_back({a, b});
	}
	else ans.push_back({a, b});
	for(int i = 0; i < n; i++) {
		if(ans[i].first == ans[i].second) cnt++;
	}
	std::cout << cnt << '\n';
	for(auto x: ans) 
		std::cout << x.first << ':' << x.second << '\n';
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
