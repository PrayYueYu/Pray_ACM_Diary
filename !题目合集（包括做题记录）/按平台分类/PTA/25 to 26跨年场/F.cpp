#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;

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
	int n = read(), ans = -1;
	for(int i = 1; i <= n; i++) {
		int m = read();
		vector<int> p;
		for(int j = 1; j <= m; j++) {
			p.push_back(read());
		}
		sort(p.begin(), p.end());
		int t = read(), sum = 0;
		for(auto x: p) {
			if(t) sum += x, t--;
			else break;
		}
		ans = max(ans, sum);
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
