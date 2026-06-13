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
int a, b;
void solve() {
	std::cin >> a >> b;
	if(a != b) {
		std::cout << "1\n1\n";
		return;
	}
	std::set<int> s;
	for(int i = 1; i <= sqrt(a); i++) {
		if(a % i == 0) {
			s.insert(i);
			s.insert(a / i);
		}
	}
	std::cout << s.size() << '\n';
	for(auto x: s) std::cout << x << ' ';
}
signed main() {
	srand(time(0));
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
