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
	std::string s;
	std::cin >> s;
	std::stack<char> st;
	std::vector<char> v;
	for(auto c: s) {
		if(!st.size()) {
			st.push(c);
			continue;
		}
		if(c == st.top()) {
			continue;
		}
		else st.push(c);
	}
	while(st.size()) {
		v.push_back(st.top());
		st.pop();
	}
	reverse(v.begin(), v.end());
	for(auto c: v) std::cout << c;
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
