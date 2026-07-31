#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, m;
int vismin[N], vismax[N], pmin[N], pmax[N];
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
std::vector<std::pair<int, int>> v[N];
std::vector<std::vector<int>> ans, a;
void add(int l1, int r1, int l2, int r2) {
	ans[l1][r1]++;
	ans[l2 + 1][r2 + 1]++;
	ans[l1][r2 + 1]--;
	ans[l2 + 1][r1]--;	
}
void solve() {
	std::cin >> n >> m;
	a.resize(n + 2, std::vector<int>(m + 2));
	ans.resize(n + 2, std::vector<int>(m + 2));

	int maxn = -INF;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
			v[a[i][j]].push_back({i, j});
			maxn = std::max(maxn, a[i][j]);
		}
	}

	for(int i = 1; i <= maxn; i++) {
		if(v[i].size() <= 1) continue;
		std::vector<int> v1;
		if(n <= m) {
			for(auto t: v[i]) {
				int x = t.first;
				int y = t.second;
				if(vismin[x] != i) {
					vismin[x] = i;
					pmin[x] = y;
					v1.push_back(x);
				}
				else if(pmin[x] > y) pmin[x] = y;
				
				if(vismax[x] != i) {
					vismax[x] = i;
					pmax[x] = y;
				}
				else if(pmax[x] < y) pmax[x] = y;
			}
			for(int p1 = 0; p1 < v1.size(); p1++) {
				for(int p2 = p1 + 1; p2 < v1.size(); p2++) {
					int t1 = v1[p1], t2 = v1[p2];
					if(pmax[t2] <= pmin[t1]) continue;
					add(t1, pmin[t1], t2, pmax[t2]);
				}
			}
		}
		else {
			for(auto t: v[i]) {
				int x = t.first;
				int y = t.second;
				std::swap(x, y);
				if(vismin[x] != i) {
					vismin[x] = i;
					pmin[x] = y;
					v1.push_back(x);
				}
				else if(pmin[x] > y) pmin[x] = y;
				
				if(vismax[x] != i) {
					vismax[x] = i;
					pmax[x] = y;
				}
				else if(pmax[x] < y) pmax[x] = y;
			}
			for(int p1 = 0; p1 < v1.size(); p1++) {
				for(int p2 = p1 + 1; p2 < v1.size(); p2++) {
					int t1 = v1[p1], t2 = v1[p2];
					if(pmax[t2] <= pmin[t1]) continue;
					add(pmin[t1], t1, pmax[t2], t2);
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			ans[i][j] = ans[i][j] + ans[i - 1][j];
			ans[i][j] += ans[i][j - 1] - ans[i - 1][j - 1];
			std::cout << (ans[i][j]? 1: 0);
		}
		std::cout << '\n';
	}
}
signed main() {
	freopen("1.in", "r", stdin); 
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
