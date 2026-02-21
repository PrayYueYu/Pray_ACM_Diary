#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N];
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
int getMin(int flag) {
	std::vector<int> v;
	for(int i = 1; i <= n; i++) {
		if(a[i] != flag) v.push_back(a[i]);
		flag = 1 - flag;
	}
	std::queue<int> q[3];
	int cnt = 0;
	for(auto x: v) {
//		std::cout << x << ' ';
		if(x) {
			if(q[0].empty()) {
				cnt++;
				q[1].push(cnt);
			}
			else {
				int y = q[0].front(); q[0].pop();
				q[1].push(y);
			}
		}
		else {
			if(q[1].empty()) {
				cnt++;
				q[0].push(cnt);
			}
			else {
				int y = q[1].front(); q[1].pop();
				q[0].push(y);
			}
		}
	}
//	std::cout << '\n';
	return cnt;;
}
void solve() {
	n = read();
	std::string s;
	std::cin >> s;
	s = " " + s;
	for(int i = 1; i <= n; i++) {
		a[i] = s[i] - '0';
	}
	std::cout << std::min(getMin(0), getMin(1)) << '\n';
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
