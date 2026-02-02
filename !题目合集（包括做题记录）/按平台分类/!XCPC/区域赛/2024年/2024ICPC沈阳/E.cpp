#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 1e5 + 10, M = 1e9 + 7, INF = 1e18;
string s1, s2;
int Min[N], r[N], p[N], n, m, f[18][N], a[N], ne[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
// 8 4 2 1
// 12 3
// 10 5
// 15
void dfs(int val, int now, int t, int c) {
	if(val > Min[t]) return;
	if(now == 15) {
		Min[t] = val;
		return;
	}
	if(c == 10) return;
	dfs(val + r[c], now ^ p[c], t, c + 1);
	dfs(val, now, t, c + 1);
}

signed main() {

	int T = read();
	int minn = INF;
	for(int i = 1; i <= 4; i++) {
		int x = read();
		minn = min(minn, x);
		if(i == 1) {
			r[1] = r[2] = r[3] = r[4] = x;
		}
		else if(i == 2) {
			r[5] = r[6] = x;
		}
		else if(i == 3) {
			r[7] = r[8] = x;
		}
		else r[9] = x;
	}
	p[1] = 8, p[2] = 4, p[3] = 2, p[4] = 1;
	p[5] = 12, p[6] = 3, p[7] = 10, p[8] = 5;
	p[9] = 15;
	for(int i = 0; i <= 15; i++) {
		ne[i] = i ^ 15;
	}
	for(int i = 0; i <= 14; i++) {
		Min[i] = INF;
		dfs(0, i, i, 1);
	//	cout << Min[i] << endl;
	}
	Min[15] = 2 * minn;


	for(int i = 0; i <= 15; i++) a[i] = i;
	for(int i = 0; i <= 15; i++) {
		for(int j = 0; j < (1 << 16); j++) {
			f[i][j] = INF;
		}
	}
	for(int i = 0; i <= 15; i++) {
		int to = (1 << a[i]);
		f[a[i]][to] = Min[a[i]];
		ne[i] = i ^ 15;
	}
	for(int j = 0; j < (1 << 16); j++) {
		for(int i = 0; i <= 15; i++) {
			for(int k = 0; k <= 15; k++) {
				int p1 = (j >> a[i]) & 1;
				int p2 = (j >> a[k]) & 1;
				if(!p1 || p2) continue;
				int to = j ^ (1 << a[k]);
				int now = a[k] ^ ne[a[i]];
				f[a[k]][to] = min(f[a[k]][to], f[a[i]][j] + Min[now]);
			}
		}
	}
	while(T--) {
		n = read();
		int ALL = 0, ans = INF;
		for(int i = 0; i < n; i++) {
			cin >> s1 >> s2;
			a[i] = 0;
			for(int j = 0; j < 2; j++) {
				a[i] = (a[i] * 2) + s1[j] - '0';
			}
			for(int j = 0; j < 2; j++) {
				a[i] = (a[i] * 2) + s2[j] - '0';
			}
			ALL += (1 << a[i]);
			//cout << i << ": " << a[i] << endl;
		}
		//cout << ALL << endl;
		for(int i = 0; i < n; i++) {
			ans = min(ans, f[a[i]][ALL]);
		}
		cout << ans << endl;
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
