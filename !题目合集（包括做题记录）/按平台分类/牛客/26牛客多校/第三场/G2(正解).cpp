#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, m, L[N], R[N];
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
		for(int j = 0; j < v1.size(); j++) {
			int t = v1[j];
			if(j) L[j] = std::min(L[j - 1], pmin[t]);
			else L[j] = pmin[t];
		}
		for(int j = v1.size() - 1; j >= 0; j--) {
			int t = v1[j];
			if(j != v1.size() - 1)
				R[j] = std::max(R[j + 1], pmax[t]);
			else R[j] = pmax[t];
		}
		for(int j = 0; j < v1.size() - 1; j++) {
			if(L[j] < R[j + 1]) {
				add(v1[j], L[j], v1[j + 1], R[j + 1]);
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
