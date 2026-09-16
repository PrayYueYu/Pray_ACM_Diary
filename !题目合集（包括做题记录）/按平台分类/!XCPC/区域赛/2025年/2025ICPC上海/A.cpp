#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, ne[N], to[N], fi[N], num;
int d[N], fa[N], maxd, vis[N], cnt;
void init() {
	for(int i = 0; i <= num + 1; i++) {
		ne[i] = to[i] = 0;
	} num = 0;
	for(int i = 0; i <= n + 1; i++) {
		fi[i] = 0;
		vis[i] = 0;
	}
	maxd = 0;
}
struct S {
	int u, d;
} s[N];
bool cmp(S x, S y) {
	return x.d < y.d;
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void dfs(int u, int F) {
	d[u] = d[F] + 1;
	maxd = std::max(maxd, d[u]);
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == F) continue;
		dfs(v, u);
	}
}
int query(int u, int k) {
	std::cout << "? " << u << ' ' << k << '\n';
	std::cout.flush();
	int x;
	std::cin >> x;
	return x;
}
void dfsx(int u, int fa) {
	d[u] = d[fa] + 1;
	if(vis[u]) {
		s[++cnt].d = d[u];
		s[cnt].u = u;
	}
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfsx(v, u);
	}
}
void solve() {
	std::cin >> n;
	for(int i = 2; i <= n; i++) {
		std::cin >> fa[i];
		add(fa[i], i);
		add(i, fa[i]);
	}
	d[0] = -1;
	dfs(1, 0);
	int l = 0, r = maxd;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(query(1, mid)) r = mid;
		else l = mid + 1;
	}//找在第几层
	
	std::vector<int> ans;
	for(int i = 1; i <= n; i++) {
		if(d[i] == l) {
			vis[i] = true;
			ans.push_back(i);
		}
	}
	
	while(true) {
		
		if(ans.size() == 1) {
			break;
		}
		
		int root = ans[0];
		cnt = 0;
		dfsx(root, 0);
		
		for(auto x: ans) vis[x] = false;
		ans.clear();
		//清空
		
		std::sort(s + 1, s + cnt + 1, cmp);
		int qd = s[cnt / 2].d;
		if(qd == s[cnt].d) {
			for(int i = cnt; i >= 1; i--) {
				if(s[i].d != s[cnt].d) {
					qd = s[i].d;
					break;
				}
			}
		}
		if(query(root, qd)) {
			for(int i = 1; i <= cnt; i++) {
				if(s[i].d <= qd) {
					vis[s[i].u] = true;
					ans.push_back(s[i].u);
				}
			}
		}
		else {
			for(int i = 1; i <= cnt; i++) {
				if(s[i].d > qd) {
					vis[s[i].u] = true;
					ans.push_back(s[i].u);
				}
			}
		}
	}
	std::cout << "! " << ans[0] << '\n';
	std::cout.flush();
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
----------------------
	Writer: 月雩薇嫭 | 
----------------------
*/
