#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 100;
int f, pos[N], a[N], b[N], l[N], r[N], n;
void init() {
	for(int i = 0; i <= n + 1; i++) {
		pos[i] = l[i] = r[i] = 0;
	}
}
int get_tree(int l1, int r1, int l2, int r2) {
	if(l1 > r1 || l2 > r2) return -1;
	int root = a[r1], x = pos[root];
	int y = (x - l2) + l1 - 1;
	l[root] = get_tree(l1, y, l2, x - 1);
	r[root] = get_tree(y + 1, r1 - 1, x + 1, r2);
	return root;
}
void dfs(int x, int h) {
	if(x % h != 0) {
		f = false;
		return;
	}
	if(l[x] != -1) dfs(l[x], h + 1);
	if(r[x] != -1) dfs(r[x], h + 1);
}
void solve() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		std::cin >> b[i];
		pos[b[i]] = i;
	}
	get_tree(1, n, 1, n);
	f = true;
	dfs(a[n], 1);
	if(f) std::cout << 1 << '\n';
	else std::cout << 0 << '\n';
}
signed main() {
	int T; std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
