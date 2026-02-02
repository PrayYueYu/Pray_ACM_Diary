#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 2e3 + 10, M = 1e9 + 7;
int n, suma[N][N], sum[N][N], a[N][N];
int l1[200005], r2[200005], l2[200005], r1[200005];
int read() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		l1[i] = read();
		l2[i] = read();
		r1[i] = read();
		r2[i] = read();
		sum[l2[i] + 1][r2[i] + 1]++;
		sum[l1[i]][r1[i]]++;
		sum[l1[i]][r2[i] + 1]--;
		sum[l2[i] + 1][r1[i]]--;
	}

	int ans = 0;
	for(int i = 1; i <= 2000; i++) {
		for(int j = 1; j <= 2000; j++) {
			sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			a[i][j] = sum[i][j];
			if(a[i][j] == 0) ans++;
			if(a[i][j] >= 2) a[i][j] = 0;
		}
	}
	for(int i = 1; i <= 2000; i++) {
		for(int j = 1; j <= 2000; j++) {
			suma[i][j] = a[i][j];
			suma[i][j] += suma[i - 1][j] + suma[i][j - 1] - suma[i - 1][j - 1];
		}
	}
	for(int i = 1; i <= n; i++) {
		int nowans = ans;
		nowans += suma[l2[i]][r2[i]] - suma[l2[i]][r1[i] - 1] - suma[l1[i] - 1][r2[i]] + suma[l1[i] - 1][r1[i] - 1];
		cout << nowans << '\n';
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
