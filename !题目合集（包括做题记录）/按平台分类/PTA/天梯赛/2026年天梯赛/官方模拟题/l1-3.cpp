#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 100;

void solve() {
	int x; std::cin >> x;
	std::cout << x << '\n';
	if(x < 0) std::cout << "dan ren";
	else if(x > 0) std::cout << "nong ren";
	else std::cout << "xian ren";
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
