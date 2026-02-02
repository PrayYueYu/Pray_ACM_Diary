#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 305, M = 1e9 + 7;
int n, f[3][N][N][4], sum[N][N][N], q;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void solve() {
	string s;
	n = read(), q = read();
	cin >> s;
	s = " " + s;
	for(int i = 0; i <= 1; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				for(int p = 1; p <= 3; p++) {
					f[i][j][k][p] = 0;
				}
			}
		}
	}
	int num = 0;
	if(s[1] == '?') {
		f[1][0][0][3] = 1;
		f[1][1][0][1] = 1;
		f[1][0][1][2] = 1;
		num++;
	}
	else f[1][0][0][s[1] - 'a' + 1] = 1;
	//f[i][j][k][p]: 前i个，其中j个'?'变成了'a'，k个'?'变成了'b'， num[i]-j-k个'?'变成了'c'，最后一个是p的总方案数 
	for(int i = 2; i <= n; i++) {
		if(s[i] == '?') num++;
		int t1 = (i - 1) % 2;
		int t2 = i % 2;
		for(int j = 0; j <= num; j++) {
			for(int k = 0; k <= num; k++) {
				f[t2][j][k][1] = f[t2][j][k][2] = f[t2][j][k][3] = 0;
				int s1 = 0, s2 = 0, s3 = 0;
				if(s[i] != '?') {
					int op = s[i] - 'a' + 1;
					int s1 = f[t1][j][k][1];
					int s2 = f[t1][j][k][2];
					int s3 = f[t1][j][k][3];
					f[t2][j][k][op] = (s1 + s2 + s3 - f[t1][j][k][op]) % M;
					continue;
				}
				if(j) {
					s1 = f[t1][j - 1][k][2];
					s2 = f[t1][j - 1][k][3];
					f[t2][j][k][1] = (s1 + s2) % M;
				}
				if(k) {
					s1 = f[t1][j][k - 1][1];
					s2 = f[t1][j][k - 1][3];
					f[t2][j][k][2] = (s1 + s2) % M;
				}
				if(num - j - k >= 1) {
					s1 = f[t1][j][k][1];
					s2 = f[t1][j][k][2];
					f[t2][j][k][3] = (s1 + s2) % M;
				}
			}
		}
	}
	for(int i = 0; i <= num; i++) {
		for(int j = 0; i + j <= num; j++) {
			sum[i][j][num - i - j] = (f[n % 2][i][j][1] + f[n % 2][i][j][2] + f[n % 2][i][j][3]) % M;
		}
	}
	for(register int i = 0; i <= 300; i++) {
		for(register int j = 0; j <= 300; j++) {
			for(register int k = 0; k <= 300; k++) {
				int s1 = 0, s2 = 0, s3 = 0;
				int s4 = 0, s5 = 0, s6 = 0, s7 = 0;
				if(i) s1 = sum[i - 1][j][k];
				if(j) s2 = sum[i][j - 1][k];
				if(k) s3 = sum[i][j][k - 1];
				if(i && j) s4 = sum[i - 1][j - 1][k];
				if(i && k) s5 = sum[i - 1][j][k - 1];
				if(j && k) s6 = sum[i][j - 1][k - 1];
				if(i && j && k) s7 = sum[i - 1][j - 1][k - 1];
				sum[i][j][k] = s1 + s2 + s3 - s4 - s5 - s6 + s7 + sum[i][j][k];
				sum[i][j][k] %= M;
				sum[i][j][k] += M;
				sum[i][j][k] %= M;
			}
		}
	}
	for(int i = 1; i <= q; i++) {
		int x = read(), y = read(), z = read();
		cout << sum[x][y][z] << endl;
	}
}
signed main() {
	int T = 1; 
	while(T--) solve();
	return 0;
} 
