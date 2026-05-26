#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, num[N];
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
	std::vector<int> s;
	int cnt = 0;
	for(int i = 0; i <= 16; i++) {
		std::vector<int> v;
		for(int j = 1; j <= n; j++) {
			if(j >> i & 1) v.push_back(j);
		}
		if(!v.size()) continue;
		std::cout << "? " << v.size() << ' ';
		for(auto x: v) std::cout << x << ' ';
		std::cout << '\n';
		std::cout.flush();
		int x = read();
		if(x) {
			cnt++;
			s.push_back(x);
		}
	}
	if(!cnt) {
		std::cout << "! 1\n";
		std::cout.flush();
		return;
	}
	if(cnt == 1) {
		std::cout << "! 2\n";
		std::cout.flush();
		return;
	}
	for(auto x: s) {
		for(int i = 1; i <= sqrt(x); i++) {
			if(x % i == 0) {
				if((x / i) > n / 2) continue;
				num[i + (x / i)]++;
			}
		}
	}
	int maxn = -1;
	for(int i = 1; i <= n; i++) {
		maxn = std::max(maxn, num[i]);
	}
	for(int i = 1; i <= n; i++) {
		if(maxn == num[i]) {
			std::cout << "! " << i;
			std::cout << '\n';
			std::cout.flush();
			return;
		}
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

*/
