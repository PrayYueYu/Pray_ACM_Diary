#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
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
std::map<int, int> mp;
void solve() {
	std::cin >> n;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		if(!mp[a]) {
			cnt++;
			mp[a] = true;
		}
	}
	if(cnt <= 3) std::cout << "YES\n";
	else std::cout << "NO\n";
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
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
