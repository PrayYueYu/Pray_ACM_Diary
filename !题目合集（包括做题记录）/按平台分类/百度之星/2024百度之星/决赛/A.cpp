#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
#define iint int
using namespace std;
const int N = 3e6 + 10, M = 1e9 + 7, INF = 1e18;
int f[N], n, vis[N], a[100], b[100][100];
bool visx[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
int calc(int s) {
	int x = 0, y = 0, z = 0;
	for(int i = 0; i < n; i++) {
		if(s >> i & 1) {
			if(!x) x = i;
			else if(!y) y = i;
			else z = i;
		}
	}
	int maxn = -INF;
	maxn = max({maxn, a[x], a[y], a[z], b[x][y], b[x][z], b[y][z], b[x][y] * b[y][z] * b[x][z]});
	return maxn;
}
vector<iint> v[100];

void solve() {
	n = read();
	int F = 1;
	if(F) for(int i = 0; i < n; i++) a[i] = read();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(F) b[i][j] = read();
		}
	}
	for(iint i = 0; i < (1 << n); i++) {
		int num = 0;
		for(int j = 0; j < n; j++) {
			if(i >> j & 1) {
				num++;
			}
		}
		vis[i] = num;
		if(num == 3) v[3].push_back(i);
		f[i] = -INF;
	}
	for(auto x: v[3]) f[x] = calc(x);
	for(register int i = 6; i <= n; i += 3) {
		for(auto x: v[i - 3]) {
			for(auto y: v[3]) {
				int z = x | y;
				if(vis[z] != i) continue;
				if(!visx[z]) {
					visx[z] = true;
					v[i].push_back(z);
				}
				f[z] = max(f[z], f[x] + f[y]);
			}
		}
	}
	int ALL = (1 << n) - 1;
	cout << f[ALL];
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
