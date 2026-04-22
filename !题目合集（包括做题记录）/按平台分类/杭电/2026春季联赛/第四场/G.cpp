#include<bits/stdc++.h>
const int N = 1e5 + 10;
int n, a, vis[N];
std::string s;
int pd(int x, std::string c) {
	int res = 0;
	if(c[0] - 48 == x / 1000) res++;
    if(c[1] - 48 == x / 100 % 10) res++;
    if(c[2] - 48 == x / 10 % 10) res++;
    if(c[3] - 48 == x % 10) res++;
	return res;
}
void print(int x) {
	std::cout << x / 1000 << x / 100 % 10 << x / 10 % 10 << x % 10 << std::endl;
}
void solve() {
	std::cin >> n;
	for(int i = 0; i <= 9999; i++) vis[i] = true;
	for(int i = 1; i <= n; i++) {
		std::cin >> s >> a;
		for(int j = 0; j <= 9999; j++) {
			if(!vis[j]) continue;
			if(pd(j, s) != a) {
				vis[j] = false;
			}
		}
	}
	for(int i = 0; i <= 9999; i++) {
		if(vis[i]) {
			print(i);
		}
	}
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T; std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
