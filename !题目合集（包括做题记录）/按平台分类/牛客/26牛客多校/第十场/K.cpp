#include<bits/stdc++.h>
#define int long long
const int N = 2e7 + 10, mod = 998244353, INF = 1e18;
int n, a[100][100], f[N], p[100];
bool vis[N];
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
void solve() {
	std::cin >> n; n *= 3;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}
	p[0] = 1;
	for(int i = 1; i < n; i++) p[i] = p[i - 1] * 2;
	int ALL = (1 << n) - 1;
	for(int i = 1; i <= ALL; i++) {
		f[i] = -INF;
	}
	f[0] = 0; vis[0] = 1;
	int cnt = 0;
	for(int i = 0; i < ALL; i++) {
		if(!vis[i]) continue;
		std::vector<int> v;
		for(int j = 0; j < n; j++) {
			if(i >> j & 1) continue;
			v.push_back(j);
		}
		int s1 = v[0];
		for(int j = 1; j < v.size() - 1; j++) {
			for(int k = j + 1; k < v.size(); k++) {
				int s2 = v[j], s3 = v[k];
				int ne = ((i | p[s1]) | p[s2]) | p[s3];
				f[ne] = std::max(f[ne], f[i] + a[s1][s2] + a[s1][s3] + a[s2][s3]);
				vis[ne] = true;
			}
		}
	}
	std::cout << f[ALL] << '\n';
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
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
