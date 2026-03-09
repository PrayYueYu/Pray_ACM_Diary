#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 1e9 + 7, INF = 1e18;
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
std::multiset<std::pair<int, int>> s;
std::pair<int, int> get_min() {
	auto it = s.begin();
	auto x = (*it);
	return x;
}
void erase_min() {
	auto it = s.begin();
	s.erase(it);
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		int c = read(), w = read();
		s.insert({w, c});
	}
	int r = 0, ans = 0;
	while(true) {
//		std::cout << s.size() << '\n';
//		for(auto x: s) 
//			std::cout << x.first << "[" << x.second << "]\n";
//		system("pause");
		if(s.size() == 1 && get_min().second == 1) break;
		if(r) {
			auto x = get_min();
			erase_min();
			s.insert({r + x.first, 1});
			ans = (ans + r + x.first) % mod;
			if(x.second > 1) {
				s.insert({x.first, x.second - 1});
			}
			r = 0;
		}
		else {
			auto x = get_min();
			erase_min();
			if(x.second % 2 == 0) {
				ans = (ans + x.first % mod * x.second % mod) % mod;
				s.insert({2ll * x.first, x.second / 2});
			}
			else {
				r = x.first;
				ans = (ans + (x.first % mod * (x.second - 1) % mod)) % mod;
				if(x.second > 1)
					s.insert({2ll * x.first, (x.second - 1) / 2});
			}
		}
	}
	if(r) {
		ans = (ans + r + (*s.begin()).first) % mod;
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

*/
