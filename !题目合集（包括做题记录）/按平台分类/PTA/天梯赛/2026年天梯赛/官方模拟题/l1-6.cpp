#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 100;
int cnt[100];
void solve() {
	for(int i = 1; i <= 9; i++) {
		int x; std::cin >> x;
		cnt[i] += x;
		if(i != 9) {
			if(i & 1) {
				cnt[i + 1] += cnt[i] / 2;
				cnt[i] %= 2;
			}
			else {
				cnt[i + 1] += cnt[i] / 3;
				cnt[i] %= 3;
			}
		}
	}
	for(int i = 1; i <= 9; i++) {
		std::cout << cnt[i];
		if(i != 9) std::cout << ' ';
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
