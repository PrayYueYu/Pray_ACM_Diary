#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, k, f[2000][2000], vis[2000];
int num, ans[2000], fa[N];
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
bool calc(int x, int y) {
	if(5 * x <= y) return true;
	return false;
}
std::vector<int> now[2000];
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void solve() {
	k = read(), n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read(), d = read();
		f[u][v] += d;
	}
	for(int i = 1; i <= n; i++) {
		int cnt = 0, re = 0;
		for(int j = 1; j <= n; j++) {
			if(!f[i][j]) continue;
			if(f[i][j] <= 5) {
				cnt++;
				if(f[j][i]) re++;
			}
		}
		if(cnt > k && calc(re, cnt)) ans[++num] = i;
	}
	int val = 0;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= num; i++) {
		for(int j = i + 1; j <= num; j++) {
			if(f[ans[i]][ans[j]] && f[ans[j]][ans[i]]) {
				int fai = getfa(ans[i]);
				int faj = getfa(ans[j]);
				if(fai < faj) fa[faj] = fai;
				else fa[fai] = faj;
			}
		}
	}
	if(!num) std::cout << "None";
	for(int i = 1; i <= num; i++) {
		int fai = getfa(ans[i]);
		now[fai].push_back(ans[i]);
	}
	for(int i = 1; i <= n; i++) {
		if(now[i].size() == 0) continue;
		int sz = now[i].size();
		std::sort(now[i].begin(), now[i].end());
		for(int j = 0; j < now[i].size(); j++) {
			std::cout << now[i][j];
			if(j != now[i].size() - 1) std::cout << ' ';
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

*/
