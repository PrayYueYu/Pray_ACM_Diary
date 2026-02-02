#include<bits/stdc++.h>
//#define getchar getchar_unlocked

using namespace std;
const int N = 5e5 + 10, M = 1e9 + 7, INF = 1e18;
int a[N], n, q, nex[N], las[2000], f[N][26];
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
void init() {
	for(int i = 0; i <= 2 * n + 3; i++) {
		for(int j = 0; j <= 21; j++) {
			f[i][j] = 0;
		}
		nex[i] = 0;
	}
	for(int i = 0; i <= 25; i++) {
		las[i] = 0;
	}
}
void solve() {
	n = read(), q = read();
	string s;
	cin >> s;
	s = s + s;
	s = " " + s;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		a[i + n] = a[i];
		s[i] = s[i] - 'A' + 'a';
		s[i + n] = s[i];
	}
	for(int i = 0; i <= 25; i++) {
		las[i] = 2 * n + 1;
		f[2 * n + 1][i] = f[2 * n + 2][i] = 2 * n + 1;
	}
	
	for(int i = 2 * n; i >= 1; i--) {
		nex[s[i] - 'a'] = las[s[i] - 'a'];
		f[i][0] = nex[s[i] - 'a'] + 1;
		for(int j = 1; j <= 20; j++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
		las[s[i] - 'a'] = i;
	}
	for(int i = 1; i <= q; i++) {
		int op = read();
		if(op == 1) {
			int x = read(), y = read();
			a[x] = a[x + n] = y;
		}
		else {
			int l = read(), r = read();
			if(r < l) r += n;
			int ans = 0, now = l;
			while(true) {
				if(now > r) break;
				for(int j = 20; j >= 0; j--) {
					if(f[now][j] <= r + 1) {
						now = f[now][j];
					}
				}
				if(now <= r) ans += a[now];
				now++;
			}
			cout << ans << '\n';
		}
	}
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
