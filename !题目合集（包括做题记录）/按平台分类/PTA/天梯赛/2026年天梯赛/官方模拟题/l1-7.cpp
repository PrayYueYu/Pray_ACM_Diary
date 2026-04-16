#include<bits/stdc++.h>
#define int long long
const int N = 2e3 + 100;
int n, m, maxn[N];
struct S {
	int id, sc;
	std::string tim;
} ans[N];
bool cmp(S x, S y) {
	return x.tim < y.tim;
}
void solve() {
	std::cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		maxn[i] = -1;
		ans[i].id = i;
	}
	for(int i = 1; i <= n; i++) {
		std::string tim, s1, s2;
		std::cin >> s1 >> s2;
		tim = s1 + " " + s2;
		int id, sc;
		std::cin >> id >> sc;
		if(maxn[id] < sc) {
			maxn[id] = sc;
			ans[id].tim = tim;
			ans[id].sc = sc;
		}
	}
	std::sort(ans + 1, ans + m + 1, cmp);
	for(int i = 1; i <= n; i++) {
		if(ans[i].tim == "") continue;
		std::cout << ans[i].tim << ' ' << ans[i].id << ' ' << ans[i].sc << '\n';
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
