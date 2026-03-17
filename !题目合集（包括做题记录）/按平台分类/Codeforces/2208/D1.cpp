#include<bits/stdc++.h>
#define int long long
const int N = 1e3 + 10, mod = 998244353, INF = 1e18;
int n, f[N][N], fa[N], fx[N][N];
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
	for(int i = 0; i <= n + 1; i++) {
		for(int j = 0; j <= n + 1; j++) {
			f[i][j] = 0;
			fx[i][j] = 0;
		}
	}
}
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void merge(int x, int y) {
	int fax = getfa(x), fay = getfa(y);
	if(fax == fay) return;
	fa[fax] = fay;
}
bool check(std::vector<std::pair<int, int>> d) {
	for(auto x: d) {
		fx[x.first][x.second] = true;
	}
	for(int i = 1; i <= n; i++) fx[i][i] = true;
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				fx[i][j] = fx[i][j] | (fx[i][k] & fx[k][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(fx[i][j] != f[i][j]) return false;
		}
	}
	return true;
}
void solve() {
	n = read();
	int flag = true;
	for(int i = 1; i <=n; i++) {
		fa[i] = i;
		std::string s;
		std::cin >> s;
		for(int j = 0; j < n; j++) {
			if(s[j] == '0') {
				if(j + 1 == i) {
					flag = false;
				}
			}
			f[i][j + 1] = s[j] - '0';
		}
	}
	if(!flag) {
		std::cout << "No\n";
		return;
	}
	std::vector<std::pair<int, int>> ans;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			if(f[i][j]) {
				flag = true; 
				for(int k = 1; k <= n; k++) {
					if(i == k) continue;
					if(k == j) continue;
					if(f[i][k] && f[k][j]) {
						flag = false;
						break;
					}
				}
				if(flag) {
					ans.push_back({i, j});
					merge(i, j);
				}
			}
		}
	}
	flag = true;
	if(ans.size() != n - 1) flag = false;
	int fa1 = getfa(1);
	for(int i = 1; i <= n; i++) {
		int fai = getfa(i);
		if(fai != fa1) {
			flag = false;
			break;
		}
	}
	if(!check(ans)) flag = false;
	if(!flag) {
		std::cout << "No\n";
		return;
	}
	std::cout << "Yes\n";
	for(auto x: ans) {
		std::cout << x.first << ' ' << x.second << '\n';
	}
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
1
4
1000
0110
1010
1111
*/
