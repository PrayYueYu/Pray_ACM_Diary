#include<bits/stdc++.h>
#define int long long
const int N = 100 + 10, mod = 998244353, INF = 1e18;
int n, m, k, ans1[N][N], dx[10][30], dy[10][30];
std::string sx[N];
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
struct S {
	int x, y, t;
} s[N * N];
bool cmp(S x, S y) {
	return x.t < y.t;
}
std::pair<int, int> to[600][600][5];
void init() {
	for(int i = 0; i <= n + 2; i++) {
		for(int j = 0; j <= m + 2; j++) {
			for(int k = 1; k <= 4; k++) {
				to[i][j][k] = {0, 0};
			}
			ans1[i][j] = 0;
		}
	}
}
void solve() {
	std::cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) {
		std::cin >> sx[i];
		sx[i] = " " + sx[i];
	}
	
	for(int i = 1; i <= k; i++) {
		s[i].x = read(), s[i].y = read();
		s[i].t = read();
	}
	std::sort(s + 1, s + k + 1, cmp);
	int maxn = 0;
	for(int i = 1; i <= k; i++) {
		for(int x = s[i].x - 1; x <= s[i].x + 1; x++) {
			for(int y = s[i].y - 1; y <= s[i].y + 1; y++) {
				if(x < 1 || y < 1 || x > n || y > m) continue;
				ans1[x][y]++;
			}
		}
		for(int j = 1; j <= 4; j++) {
			for(int k = 1; k <= 19; k++) {
				int tx = s[i].x - dx[j][k];
				int ty = s[i].y - dy[j][k];
				if(tx < 1 || ty < 1 || tx > n || ty > m) continue;
				to[tx][ty][j] = {s[i].x, s[i].y};
			}
		}
		for(int x = 1; x <= n; x++) {
			for(int y = 1; y <= m; y++) {

				if(sx[x][y] == '.') continue;
				for(int j = 1; j <= 4; j++) {
					if(!to[x][y][j].first) continue;
					int tx = to[x][y][j].first;
					int ty = to[x][y][j].second;
					maxn = std::max(maxn, ans1[tx][ty]);
				}
			}
		}
	}
	std::cout << maxn << '\n';
}
signed main() {
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	for(int i = -5; i <= 5; i++) {
		for(int j = -5; j <= 5; j++) {
			if(std::abs(i) + std::abs(j) > 4) continue;
			if(i < 0) {
				if(i != -1 || std::abs(j) != 3) {
					dx[1][++cnt1] = i;
					dy[1][cnt1] = j;
				}
			}
			else if(i > 0) {
				if(i != 1 || std::abs(j) != 3) {
					dx[2][++cnt2] = i;
					dy[2][cnt2] = j;
				}
			}
			else {
				if(std::abs(j) <= 2) {
					dx[1][++cnt1] = i;
					dy[1][cnt1] = j;
					dx[2][++cnt2] = i;
					dy[2][cnt2] = j;
				}
			}
			if(j < 0) {
				if(j == -1 && std::abs(i) == 3) continue;
				dx[3][++cnt3] = i;
				dy[3][cnt3] = j;
			}
			else if(j > 0) {
				if(j == 1 && std::abs(i) == 3) continue;
				dx[4][++cnt4] = i;
				dy[4][cnt4] = j;
			}
			else {
				if(std::abs(i) > 2) continue;
				dx[3][++cnt3] = i;
				dy[3][cnt3] = j;
				dx[4][++cnt4] = i;
				dy[4][cnt4] = j;
			}
		} 
	}
	int T; std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
