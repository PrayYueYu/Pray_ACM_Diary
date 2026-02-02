#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e18; 
int n, m, a[N], ans;
int fa[N], cnt[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
vector<int> p[N];
multiset<int> vx[N];
map<int, int> dsu[N];
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void init() {
	int Max = 0;
	for(int i = 1; i <= 200000; i++) {
		for(int j = 1; ; j++) {
			int t1 = i * j, t2 = i * (j + 1);
			if(t2 > 200000) break;
			if(__gcd(t1, t2) == (t1 ^ t2)) {
				p[t1].push_back(t2);
				p[t2].push_back(t1);
			}
		}
	}
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		fa[i] = i;
		cnt[i] = 1;
		dsu[i][a[i]]++;
		vx[i].insert(a[i]); 
	}
	for(int i = 1; i <= m; i++) {
		int t = read();
		int x = read(), y = read();
		if(t == 1) {
			a[x] = y;
			fa[x] = x;
			cnt[x] = 1;
			dsu[x][y]++;
			vx[x].insert(a[x]);
		}
		if(t == 2) {
			int fax = getfa(x);
			int fay = getfa(y);
			if(fax == fay) {
				cout << ans << endl;
				continue;
			}
			if(cnt[fax] > cnt[fay]) swap(fax, fay);
			for(auto u: vx[fax]) {
				for(auto v: p[u]) {
					ans += dsu[fay][v];
				}
			}
			cnt[fay] += cnt[fax];
			fa[fax] = fay;
			for(auto u: dsu[fax]) {
				dsu[fay][u.first] += u.second;
			}
			for(auto u: vx[fax]) {
				vx[fay].insert(u);
			}
		}
		if(t == 3) {
			int fax = getfa(x);
			for(auto u: p[a[x]]) ans -= dsu[fax][u];
			dsu[fax][a[x]]--;
			auto it = vx[fax].find(a[x]);
			vx[fax].erase(it);
			a[x] = y;
			dsu[fax][a[x]]++;
			vx[fax].insert(a[x]);
			for(auto u: p[a[x]]) ans += dsu[fax][u];
		}
		cout << ans << endl;
	}
}
signed main() {
	//freopen("1.in", "r", stdin);
	init();
	int T = 1;
	while(T--) {
		solve();
	} 
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
