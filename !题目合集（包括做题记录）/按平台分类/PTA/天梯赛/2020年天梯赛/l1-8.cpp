#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int ans[100] = {0, 0, 0, 0, 0, 0, 10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};
int n, vis[20], a[6][6];
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
	int idx = 0, idy = 0;
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			a[i][j] = read();
			if(!a[i][j]) {
				idx = i, idy = j;
			}
			vis[a[i][j]] = true;
		}
	}
	for(int i = 1; i <= 9; i++) {
		if(!vis[i]) {
			a[idx][idy] = i;
			break;
		}
	}
	for(int i = 1; i <= 3; i++) {
		int x = read(), y = read();
		std::cout << a[x][y] << '\n';
	}
	int x = read(), sum = 0;
	if(x <= 3) {
		for(int i = 1; i <= 3; i++) sum += a[x][i];
	}
	else if(x <= 6) {
		for(int i = 1; i <= 3; i++) sum += a[i][x - 3];
	}
	else if(x == 7) {
		sum = a[1][1] + a[2][2] + a[3][3];
	}
	else sum = a[1][3] + a[2][2] + a[3][1];
	std::cout << ans[sum];
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
