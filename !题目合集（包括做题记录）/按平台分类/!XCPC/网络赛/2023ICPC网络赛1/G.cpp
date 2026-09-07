#include<bits/stdc++.h>
#define ll long long
#define re register
const int N = 1e6 + 10;
const ll mod = 998244353;
int n, m, cnt[N], fa[N], minn[N], de[N], f[N];
int ne[2 * N], to[2 * N], fi[2 * N], num;
int ux[N], vx[N];
ll inv[N];
std::vector<int> tr[N];

inline int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
inline ll merge(int u, int v) {
	int fau = getfa(u);
	int fav = getfa(v);
	if(cnt[fav] < cnt[fau]) std::swap(fau, fav);
	fa[fau] = fav;
	int s1 = cnt[fau], s2 = cnt[fav];
	cnt[fav] += cnt[fau];
	if(de[minn[fav]] > de[minn[fau]]) {
		minn[fav] = minn[fau];
	}
	for(auto x: tr[fau]) {
		tr[fav].push_back(x);
	}
	return inv[s1] * inv[s2] % mod;
}
inline void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
inline void dfs(int u, int F) {
	de[u] = de[F] + 1;
	f[u] = F;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == F) continue;
		dfs(v, u);
	}
}
inline bool sfind(int x, int y) {
	int fax = x;
	int fay = getfa(y);
	if(fax == fay) return true;
	return false;
}
void solve() {
	ll ans = 1;
	std::cin >> n;
	
	inv[1] = 1;
	for(re ll i = 2; i <= n; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
	
	for(re int i = 1; i <= n; i++) {
		fa[i] = i;
		cnt[i] = 1;
		tr[i].push_back(i);
		minn[i] = i;
	}
	for(re int i = 1; i < n; i++) {
		std::cin >> ux[i] >> vx[i];
	}
	int flag = true;
	for(re int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		add(u, v); add(v, u);
	}
	dfs(1, 0);
	for(re int i = 1; i < n; i++) {
		int fau = getfa(ux[i]);
		int fav = getfa(vx[i]);
		if(!sfind(fav, f[minn[fau]]) && !sfind(fau, f[minn[fav]])) {
			flag = false;
			break;
		}
		ans = ans * merge(ux[i], vx[i]) % mod;
	}
	if(!flag) {
		std::cout << 0;
		return;
	}
	std::cout << ans;
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
