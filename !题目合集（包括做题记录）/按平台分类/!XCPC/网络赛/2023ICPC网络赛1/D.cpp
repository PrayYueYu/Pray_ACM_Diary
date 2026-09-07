#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int fa[N], cnt[N], n, m, r[N];
int getfa(int x) {
	if(fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
void merge(int u, int v) {
	int fau = getfa(u);
	int fav = getfa(v);
	if(fau == fav) {
		r[fau]++;
		return;
	}
	if(cnt[fav] < cnt[fau]) std::swap(fau, fav);
	fa[fau] = fav;
	cnt[fav] += cnt[fau];
	r[fav] += r[fau] + 1;
}
void solve() {
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
		cnt[i] = 1;
		r[i] = 0;
	}
	for(int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		merge(u, v);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int fai = getfa(i);
		if(fai != i) continue;
		int ned = cnt[i] * (cnt[i] - 1) / 2;
		if(ned != r[i]) {
			ans += ned - r[i];
		}
	}
	if(ans) {
		std::cout << ans;
		return;
	}
	int minn1 = INF, minn2 = INF;
	for(int i = 1; i <= n; i++) {
		int fai = getfa(i);
		if(fai != i) continue;
		if(minn1 > cnt[i]) {
			if(minn2 > minn1) {
				minn2 = minn1;
			}
			minn1 = cnt[i];
		}
		else if(minn2 > cnt[i]) {
			minn2 = cnt[i];
		}
//		std::cout << cnt[i] << ' ' << minn1 << ' ' << minn2 << '\n';
	}
	std::cout << minn1 * minn2;
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1; 
//	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Ş±‹¬ | 
----------------------
*/
