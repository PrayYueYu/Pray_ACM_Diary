#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e18; 
int fa[N], Max[N], n, m, w[N], vis[100];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
int calc(int x) {
	for(int i = 32; i >= 0; i--) {
		if((x >> i) & 1) return i;
	}
	return -1;
}
bool check(int x, int y) {
	int fax = getfa(x), fay = getfa(y);
	if(fax == fay) return true;
	return false;
}
void merge(int x, int y) {
	int fax = getfa(x), fay = getfa(y);
	if(fax == fay) return;
	fa[fay] = fax;
}
void solve() {
	n = read(); m = read();
	for(int i = 1; i <= n; i++) fa[i] = i;
	vector<pair<pair<int, int>, int>> p;
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read(); 
		p.push_back({{u, v}, w});
	}
	int sum = 0;
	for(int i = 33; i >= 0; i--) {
		for(int j = 1; j <= n; j++) fa[j] = j;
		for(int j = 0; j < m; j++) {
			int w = p[j].second;
			if((w >> i & 1)) continue;//i位为1不能要
			int f = 1;
			for(int k = 33; k >= 0; k--) {
				if(k > i && (w >> k & 1)) {
					if(!vis[k]) {
						f = 0;
						break;
					}
				}
			}
			if(!f) continue;
			int u = p[j].first.first;
			int v = p[j].first.second;
			merge(u, v);
		}
		if(check(1, n)) vis[i] = false;
		else vis[i] = true;
	}
	int ans = 0;
	for(int i = 0; i <= 33; i++) {
		if(!vis[i]) continue;
		ans = ans + (1 << i);
	}
	cout << ans << endl;
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = 1;
	while(T--) {
		solve();
	//	init();
	}
	return 0;
}
//月雩·薇嫭 
/*

*/
