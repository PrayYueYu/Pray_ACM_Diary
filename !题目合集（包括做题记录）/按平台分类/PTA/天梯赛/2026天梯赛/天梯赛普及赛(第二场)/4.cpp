#include<bits/stdc++.h>
#define int long long
const int N = 2e3 + 100;
int a[N];
void solve() {
	int n, ans = 0;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if(!(i & 1)) ans += a[i];
	}
	std::cout << ans;
}
signed main() {
	solve();
	return 0;
} 
