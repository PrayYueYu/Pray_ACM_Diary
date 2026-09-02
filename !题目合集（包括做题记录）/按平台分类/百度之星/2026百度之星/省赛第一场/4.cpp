#include<bits/stdc++.h>
#define int long long
const int N = 2e3 + 10, INF = 2000000000000000000ll;
int sum[N][N], a[N][N], n, s[N][N], f[2][N][N];
int calc(int x1, int y1, int x2, int y2) {
	int ans = sum[x2][y2] - sum[x1 - 1][y2];
	ans = ans - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
	return ans;
}
void solve() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			a[i][j] = 0;
			sum[i][j] = a[i][j];
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
		for(int j = i; j <= n; j++) {
			std::cin >> a[i][j];
			sum[i][j] = a[i][j];
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			f[0][i][j] = f[1][i][j] = INF;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int c = calc(1, i, i, j - 1) + calc(i + 1, j, j, n);
			s[i][j] = c;
		}
	}
	int now = 1, las = 0;
	f[now][1][2] = 0;
	for(int i = 4; i <= n; i += 2) {
		now ^= 1; las ^= 1;
		for(int j = 1; j <= i - 3; j++) {
			for(int k = j + 1; k <= i - 2; k++) {
				f[now][i - 1][i] = std::min(f[now][i - 1][i], f[las][j][k] + s[j][k]);
				f[now][j][k] = f[las][j][k] + s[i - 1][i];
				f[now][j][i - 1] = std::min(f[now][j][i - 1], f[las][j][k] + s[k][i]);
				f[now][j][i] = std::min(f[now][j][i], f[las][j][k] + s[k][i - 1]);
				f[now][k][i - 1] = std::min(f[now][k][i - 1], f[las][j][k] + s[j][i]);
				f[now][k][i] = std::min(f[now][k][i], f[las][j][k] + s[j][i - 1]);
			}
		}
	}
	int ans = INF;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			ans = std::min(ans, f[now][i][j] + s[i][j]);
		}
	}
	std::cout << ans;
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1;
//	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
