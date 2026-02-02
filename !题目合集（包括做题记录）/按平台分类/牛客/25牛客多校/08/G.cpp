#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 3e6 + 10, M = 1e9 + 7, INF = 1e14;
int n, fa[N], cnt[N], m, k, hav[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct Dot {
	int u, v, w;
} s[N];
bool cmp(Dot x, Dot y) {
	return x.w < y.w;
}
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
int calc(int x, int y) {
	return ((x * (x - 1)) / 2) - y;
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = read();
	while(T--) {
		n = read(), m = read(), k = read();
		for(int i = 1; i <= n; i++) {
			fa[i] = i;
			cnt[i] = 1;
		}
		vector<vector<int>> dsu, pa;
		dsu.resize(n + 10);
		pa.resize(n + 10); 
		for(int i = 1; i <= m; i++) {
			int u = read(), v = read();
			s[i].u = u;
			s[i].v = v;
			s[i].w = read();
			pa[u].push_back(v);
			pa[v].push_back(u);
			int fau = getfa(s[i].u);
			int fav = getfa(s[i].v);
			if(fau != fav) {
				cnt[fav] += cnt[fau];
				fa[fau] = fav;
			}
		}
		int sumfa = 0, ans = 1;
		for(int i = 1; i <= n; i++) {
			int fax = getfa(i);
			if(fax == i) {
				sumfa++;
				ans = (ans * cnt[i]) % M;
			}
		}
		if(sumfa >= 3) {
			cout << 0 << endl;
			continue;
		}
		if(sumfa == 2) {
			ans = (ans * k) % M;
			cout << ans << endl;
			continue;
		}
		sort(s + 1, s + m + 1, cmp);
		for(int i = 1; i <= n; i++) {
			fa[i] = i;
			cnt[i] = 1;
			hav[i] = 0;
			dsu[i] = {i};
		}
		int tot = (n * (n - 1)) / 2;
		ans = 0;
		int nowk = 1, use1 = 0;
		for(int i = 1; i <= m; i++) {
			if(nowk < s[i].w && nowk < k) {
				int val = min(s[i].w, k) - nowk;
				int res = tot - use1 - m;
				ans = (ans + val * res % M) % M;
				nowk = min(s[i].w, k);
			}
			int fau = getfa(s[i].u);
			int fav = getfa(s[i].v);
			if(fau == fav) continue;
			if(cnt[fau] > cnt[fav]) swap(fau, fav);
			int res = 0;
			for(const auto& u: dsu[fau]) {
				for(const auto& v: pa[u]) {
					int fax = getfa(v);
					if(fax == fav) res++;
				}
			}
			use1 -= calc(cnt[fau], hav[fau]);
			use1 -= calc(cnt[fav], hav[fav]);
			cnt[fav] += cnt[fau];
			hav[fav] += hav[fau] + res;
			fa[fau] = fav;
			use1 += calc(cnt[fav], hav[fav]);
			dsu[fav].insert(dsu[fav].end(), dsu[fau].begin(), dsu[fau].end());
			dsu[fau].clear();
		}
		cout << ans << endl;
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
