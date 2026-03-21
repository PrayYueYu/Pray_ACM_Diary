#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int dx[10] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int dy[10] = {0, 1, -1, 1, -1, 0, 1, -1, 0};
int n, m, t, a[20][20], b[20][20];
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
bool check(int x, int y) {
	if(x < 1 || y < 1 || x > n || y > m) return false;
	return true;
}
void solve() {
	std::cin >> n >> m >> t;
	for(int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		for(int j = 1; j <= m; j++) {
			a[i][j] = s[j - 1] - '0';
		}
	}
//	t--;
	while(t--) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				int cnt1 = 0;
				for(int k = 1; k <= 8; k++) {
					int sx = i + dx[k];
					int sy = j + dy[k];
					if(!check(sx, sy)) continue;
					if(a[sx][sy]) cnt1++;
				}
				if(!a[i][j]) {
					if(cnt1 == 3) b[i][j] = 1;
					else b[i][j] = 0;
				}
				else {
					if(cnt1 == 2 || cnt1 == 3) b[i][j] = 1;
					else b[i][j] = 0;
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				a[i][j] = b[i][j];
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			std::cout << a[i][j];
		}
		std::cout << '\n';
	}
	
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
