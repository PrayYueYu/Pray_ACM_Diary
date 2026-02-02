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
	int n = read(), ans = 0;
	stack<int> st, ansst;
	for(int i = 1; i <= n; i++) {
		int x = read();
		if(!st.size()) {
			st.push(x);
//			std::cout << ans << ' ' << st.size() << '\n';
			if(ans < st.size()) {
				ans = st.size();
//				std::cout << ans << ' ' << st.size() << '\n';
				ansst = st;
			}
			continue;
		}
		while(true) {
			if(st.size() == 0) break;
			if(x > st.top()) st.pop();
			else break;
		}
		st.push(x);
		if(ans < st.size()) {
			ans = st.size();
			ansst = st;
		}
	}
	std::cout << ans << '\n';
	while(ansst.size()) {
		int x = ansst.top();
		std::cout << x << ' ';
		ansst.pop();
	}
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
