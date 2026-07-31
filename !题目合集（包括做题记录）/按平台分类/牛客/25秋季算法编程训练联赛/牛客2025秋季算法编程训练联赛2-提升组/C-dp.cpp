#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3 + 100, M = 1e9 + 7;
int n, f[N][N], p[3][N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
signed main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		p[1][i] = read();
		p[2][i] = ((1 - p[1][i]) % M + M) % M;
	}
	f[1][1] = p[1][1];
	f[1][0] = p[2][1];
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j <= i; j++) {
			int s1 = (f[i - 1][j] * p[2][i]) % M;
			int s2 = (f[i - 1][j - 1] * p[1][i]) % M;
			f[i][j] = (s1 + s2) % M;
		}
	}
	for(int i = 0; i <= n; i++) {
		cout << f[n][i] << " ";
	}
	return 0;
} 
