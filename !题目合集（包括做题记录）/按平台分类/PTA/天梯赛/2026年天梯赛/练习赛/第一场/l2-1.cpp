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
	int n = read(), m = read(), q = read();
	std::stack<int> st;
	while(q--) {
		int now = 1, f = 1;
		for(int i = 1; i <= n; i++) {
			int x = read();
			if(x == now) now++;
			else st.push(x);
			if(st.size() > m) f = false;
			while(!st.empty()) {
				if(st.top() == now) {
					now++;
					st.pop();
				}
				else break;
			}
		}
		if(st.empty() && f) std::cout << "YES\n";
		else std::cout << "NO\n";
		while(!st.empty()) st.pop();
	}
}
signed main() {
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
