#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 100;
int n, vis[N], a[N];
void dfs(int x) {
	if(x * 2 <= n) dfs(x * 2);
	if(x * 2 + 1 <= n) dfs(x * 2 + 1);
	std::cout << a[x];
	if(x != 1) std::cout << ' ';
}
void solve() {
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		vis[i] = false;
	}
	for(int i = 1; i <= n; i++) {
		int l = i * 2, r = i * 2 + 1;
		if(l <= n) {
			if(a[l] < a[i]) vis[l] = 1;
			if(a[l] > a[i]) vis[l] = 2;
		}
		if(r <= n) {
			if(a[r] < a[i]) vis[r] = 1;
			if(a[r] > a[i]) vis[r] = 2;
		}
	}
	int f = false;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) continue;
		if(!f) f = vis[i];
		else {
			if(f != vis[i]) {
				std::cout << "Not Heap\n";
				dfs(1); std::cout << '\n';
				return;
			}
		}
	}
	if(f == 1) std::cout << "Max Heap\n";
	else std::cout << "Min Heap\n";
	dfs(1); std::cout << '\n';
}
signed main() {
	int T; std::cin >> T;
	std::cin >> n;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
