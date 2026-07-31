#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, f[N], r[N], de[N], fa[N], newfa[N], fax[N];
std::queue<int> qu;
struct cmp {
  bool operator()(const int& x, const int& y) {
      return de[x] < de[y];
  }  
};
std::priority_queue<int, std::vector<int>, cmp> q[N];
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void merge(int x, int y) {
	int fax = getfa(x), fay = getfa(y);
	if(fax == fay) return;
	if(q[fax].size() > q[fay].size()) std::swap(fax, fay);
	while(!q[fax].empty()) {
		int u = q[fax].top();
		q[fax].pop();
		q[fay].push(u);
	}
	fa[fax] = fay;
}
void solve() {
	std::cin >> n >> m;
	for(int i = 2; i <= n; i++) {
		std::cin >> fax[i];
		r[fax[i]]++;
		de[i] = de[fax[i]] + 1;
	}
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		if(v == 1) continue;
		q[u].push(v);
	}
	for(int i = 2; i <= n; i++) {
		q[i].push(1);
	}
	for(int i = 1; i <= n; i++) {
		if(!r[i]) qu.push(i);
		fa[i] = i;
	}
	while(!qu.empty()) {
		int u = qu.front(); qu.pop();
		if(u == 1) break;
		r[fax[u]]--;
		if(!r[fax[u]]) qu.push(fax[u]);
		int fau = getfa(u);
		int ne = q[fau].top(); q[fau].pop();
		while(!q[fau].empty()) {
			if(q[fau].top() != ne) break;
			else q[fau].pop();
		}
		merge(ne, fau);
		newfa[u] = ne;
	}
	int ans = 0;
	for(int i = 2; i <= n; i++) {
		de[i] = de[newfa[i]] + 1;
		ans += de[i];
	}
	std::cout << ans << '\n';
}
signed main() {
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
