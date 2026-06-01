#include<bits/stdc++.h>
const int N = 2e6 + 10, mod = 998244353, INF = 1e9;
int vis[N], visx[N], l[N], n;
std::vector<int> a[3010];
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
void init() {
	for(int i = 1; i <= n; i++) {
		visx[i] = false;
		for(int j = 1; j <= l[i]; j++) {
			vis[a[i][j]] = false;
		}
	}
}
bool check(int x, int y) {
	int s1 = l[x], s2 = l[y];
	while(true) {
		while(true) {
			if(!s1) break;
			if(vis[a[x][s1]]) s1--;
			else break;
		}
		while(true) {
			if(!s2) break;
			if(vis[a[y][s2]]) s2--;
			else break;
		}
		if(!s1 || !s2) break;
		if(a[x][s1] > a[y][s2]) return true;
		if(a[x][s1] < a[y][s2]) return false;
		s1--, s2--;
	}
	return s2 <= s1;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		l[i] = read();
		a[i].clear(); a[i].push_back(-1);
		std::vector<int> v, vx;
		for(int j = 1; j <= l[i]; j++) {
			int x = read();
			v.push_back(x);
		}
		for(int j = v.size() - 1; j >= 0; j--) {
			int x = v[j];
			if(!vis[x]) {
				vx.push_back(x);
				vis[x] = true;
			}
		}
		for(int j = v.size() - 1; j >= 0; j--) {
			int x = v[j];
			vis[x] = false;
		}
		std::reverse(vx.begin(), vx.end());
		for(auto x: vx) a[i].push_back(x); 
		l[i] = a[i].size() - 1;
 	}
	for(int i = 1; i <= n; i++) {
		int id = 0;
		for(int j = 1; j <= n; j++) {
			if(visx[j]) continue;
			if(!id) {
				id = j;
				continue;
			}
			if(check(id, j)) id = j;
		}
		visx[id] = true;
		for(int j = l[id]; j >= 1; j--) {
			if(vis[a[id][j]]) continue;
			std::cout << a[id][j] << ' ';
			vis[a[id][j]] = true;
		}
	}
	std::cout << '\n';
}
signed main() {
	int T; std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
