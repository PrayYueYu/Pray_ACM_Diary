#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int a[4][4], vis[20];
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
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			a[i][j] = read();
			vis[a[i][j]]++;
			if(vis[a[i][j]] >= 2 || a[i][j] > 9 || a[i][j] < -1) {
				std::cout << "No\n";
				return;
			}
		}
	}
	int x1 = a[1][1] + a[1][2] + a[1][3];
	int x2 = a[2][1] + a[2][2] + a[2][3];
	int x3 = a[3][1] + a[3][2] + a[3][3];
	int y1 = a[1][1] + a[2][1] + a[3][1];
	int y2 = a[1][2] + a[2][2] + a[3][2];
	int y3 = a[1][3] + a[2][3] + a[3][3];
	int l = a[1][1] + a[2][2] + a[3][3];
	int r = a[1][3] + a[2][2] + a[3][1];
	if(x1 != x2 || x1 != x3 || x1 != y1 || x1 != y2 || x1 != y3 || x1 != l || x1 != r) {
		std::cout << "No";
	}
	else std::cout << "Yes";
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
