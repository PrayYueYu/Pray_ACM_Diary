#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 20;
int n, ans[N];
char c[100];
void solve() {
	std::cin >> n;
	int sum = 0;
	for(int i = 2; i <= 1000; i++) ans[i] = 0;
	for(int i = 2; i <= 1000; i++) {
		int cnt = 0;
		while(true) {
			if(n % i == 0) {
				n /= i;
				cnt++;
			}
			else break;
		}
		if(cnt) {
			ans[i] = cnt;
			sum += (i - 1) * cnt;
		}
		if(sum > 1000) break;
	}
	if(n != 1 || sum > 1000) {
		std::cout << "!\n";
		return;
	}
	int t = 0;
	for(int i = 2; i <= 1000; i++) {
		if(!ans[i]) continue;
		for(int j = 1; j <= ans[i]; j++) {
			t++;
			for(int k = 1; k < i; k++) {
				std::cout << c[t];
			}
		}
	}
	std::cout << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	for(int i = 1; i <= 26; i++) {
		c[i] = 'a' + i - 1;
	}
	for(int i = 27; i <= 52; i++) {
		c[i] = 'A' + i - 27;
	}
	for(int i = 53; i <= 62; i++) {
		c[i] = '0' + i - 53;
	}
	int T; std::cin >> T;
	while(T--) solve();
	return 0;
}
/*

*/
