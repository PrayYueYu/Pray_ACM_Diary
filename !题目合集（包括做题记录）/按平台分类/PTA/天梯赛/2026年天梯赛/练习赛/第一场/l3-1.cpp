#include<bits/stdc++.h>
#define int long long
#define re register
const int N = 1e3 + 10, mod = 998244353, INF = 1e18;
int n, f[N][N], vis[N], fg[N];
int read() {
	int x;
	std::cin >> x;
	return x;
}
std::vector<int> v[N];
void solve() {
	int n = read(), m = read(), k = read();
	getchar();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			f[i][j] = INF;
		}
	}
	for(int i = 1; i <= m; i++) {
		std::string s = "";
		getline(std::cin, s);
		int x = 0, fl = 0, u = 0, la = 0, d = 0;
		int st = 0, ed = 0;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == ' ') {
				if(!st) st = x;
				if(!fl) {
					fl = true;
					if(la) {
						f[x][la] = f[la][x] = std::min(f[la][x], d);
					}
					la = x;
				}
				else {fl = false; d = x;}
				x = 0;
			}
			else {x = x * 10 + s[j] - '0';}
		}
		ed = x;
		fg[st] = fg[ed] = true;
		f[x][la] = f[la][x] = std::min(f[la][x], d);
	}
	for(re int kx = 1; kx <= n; kx++) {
		for(re int i = 1; i <= n; i++) {
			for(re int j = 1; j <= n; j++) {
				f[i][j] = std::min(f[i][j], f[i][kx] + f[kx][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(f[i][j] == INF || i == j) continue;
			if(fg[j]) {
				v[i].push_back(j);
				continue;
			}
			int flag = true;
			for(int kx = 1; kx <= n; kx++) {
				if(f[i][kx] == INF || kx == i) continue;
				if((f[i][kx] / k != f[i][j] / k)) continue;
				if(f[i][kx] > f[i][j]) flag = false; 
			}
			if(flag) v[i].push_back(j);
		}
	}
	int qx = read();
	for(int i = 1; i <= qx; i++) {
		for(int j = 1; j <= n; j++) vis[j] = false;
		int x = read();
		std::queue<int> q;
		q.push(x); vis[x] = true;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(auto y: v[u]) {
				if(vis[y]) continue;
				q.push(y);
				vis[y] = true;
			}
		}
		std::vector<int> ans;
		for(re int j = 1; j <= n; j++) {
			if(!vis[j]) continue;
			ans.push_back(j);
		}
		for(re int j = 0; j < ans.size(); j++) {
			std::cout << ans[j];
			if(j != ans.size() - 1) std::cout << ' ';
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
