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
	int a = read(), b = read();
	std::vector<int> ans;
	int f = 0;
	if(std::abs(a - b) <= 1) {
		if(a > b) f = 0;
		else f = 1;
		for(int i = 1; i <= a + b; i++) {
			std::cout << f;
			f ^= 1;
		}
		std::cout << '\n';
	}
	else {
		if(a > b) f = 0;
		else f = 1;
		int maxn = std::max(a, b);
		int minn = std::min(a, b);
		int x = 0;
		if(maxn % (minn + 1) == 0) x = maxn / (minn + 1);
		else x = maxn / (minn + 1) + 1;
		int bx = (minn + 1) * x - maxn;
		int ax = minn + 1 - bx;
		for(int i = 1; i <= minn; i++) {
			if(ax) {
				ax--;
				for(int j = 1; j <= x; j++) ans.push_back(f);
			}
			else {
				for(int j = 1; j <= x - 1; j++) 
					ans.push_back(f);
			}
			ans.push_back((f ^ 1));
		}
		for(int j = 1; j < x; j++) ans.push_back(f);
		if(ax) ans.push_back(f);
		for(auto x: ans) std::cout << x;
		std::cout << '\n';
	}
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
