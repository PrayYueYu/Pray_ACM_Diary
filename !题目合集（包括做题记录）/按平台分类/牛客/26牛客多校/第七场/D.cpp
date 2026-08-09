#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, ans[N], a[3][N], to[3][N], vis[N];
std::map<int, int> mp;
void Print() {
	std::cout << "YES\n";
	int now1 = 1, now2 = 1;
	for(int i = 1; i <= n - 1; i++) vis[ans[i]] = -1;
	for(int i = 1; i <= n; i++) {
		if(!ans[i]) continue;
		while(true) {
			if(now1 > n) break;
			if(vis[a[1][now1]] == -1) break;
			if(!vis[a[1][now1]]) {
				std::cout << a[1][now1] << ' ';
				vis[a[1][now1]] = true;
			}
			now1++;
		}
		while(true) {
			if(now2 > n) break;
			if(vis[a[2][now2]] == -1) break;
			if(!vis[a[2][now2]]) {
				std::cout << a[2][now2] << ' ';
				vis[a[2][now2]] = true;
			}
			now2++;
		}
		if(i != n) std::cout << ans[i] << ' ';
		vis[ans[i]] = 1;
	}
	exit(0);
}
bool dfs(int s1, int t1, int s2, int p1, int p2, int S) {
	if(s1 == 1) return true;
	if(s1 == n) return false;
	int fx = false, minn = INF, id = 0;
	for(int i = s1 + 1; i < t1; i++) {
		if(to[p2][a[p1][i]] < s2 - 1 || to[p2][a[p1][i]] == 1) {
			if(minn > to[p2][a[p1][i]]) {
				minn = to[p2][a[p1][i]];
				id = i;
			}
		}
	}
	if(!id) return false;
	int f = dfs(to[p2][a[p1][id]], s2, s1, p2, p1, S + 1);
	if(f) {
		ans[n - S] = a[p1][id];
		fx = true;
	}
	return fx;
}

void solve() {
	int x;
	std::cin >> n >> x;
	
	if(n == 1) {
		std::cout << "YES\n";
		return;
	}
	int id1 = 0, id2 = 0;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[1][i];
		to[1][a[1][i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		std::cin >> a[2][i];
		to[2][a[2][i]] = i;
	}
	id1 = to[1][x];
	id2 = to[2][x];
	if(id1 == id2 && id1 == n) {
		std::cout << "NO\n";
		return;
	}
	for(int i = id1 + 1; i <= n; i++) {
		mp[a[1][i]] = true;
	}
	for(int i = id2 + 1; i <= n; i++) {
		if(mp[a[2][i]]) {
			std::cout << "NO\n";
			return;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		vis[i] = false;
		ans[i] = 0;
	}
	ans[n] = x, vis[x] = -1;
	if(dfs(id1, n + 1, id2, 1, 2, 1)) {
		Print();
		return;
	}
	
	for(int i = 1; i <= n; i++) {
		vis[i] = false;
		ans[i] = 0;
	}
	ans[n] = x, vis[x] = -1;
	if(dfs(id2, n + 1, id1, 2, 1, 1)) {
		Print();
		return;
	}
	
	std::cout << "NO\n";
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
10 3
5 6 2 3 10 9 8 7 1 4
7 4 2 10 9 6 1 8 5 3
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
