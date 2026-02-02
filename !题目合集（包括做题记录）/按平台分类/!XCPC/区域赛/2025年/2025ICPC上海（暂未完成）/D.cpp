#include<bits/stdc++.h>
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7;
int n, ans, p[100], vis[100], a[1000000];
int f[50000005];
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
void dfs(int t, int now, int d) {
	if(t == n) {
		int s1 = now, s2 = now;
		if(d == -1) {
			ans = ans ^ f[now];
			return;
		}
		s1 -= p[d];
		s2 -= p[d] * 2;
		f[now] = f[s1] + f[s2];
		ans = ans ^ f[now];
		return;
	}
	vis[t] = 0;
	dfs(t + 1, now, d);
	vis[t] = 1;
	dfs(t + 1, now + p[t], d);
	vis[t] = 2;
	dfs(t + 1, now + 2 * p[t], t);
}
void solve() {
	n = read();	
	p[0] = 1;
	for(int i = 1; i <= n; i++) p[i] = p[i - 1] * 3;
	for(int i = 0; i < (1 << n); i++) {
		a[i] = read();
		int now = 0;
		for(int j = 0; j < n; j++) {
			if((i >> j & 1)) now += p[j];
		}
//		cout << now << '\n';
		f[now] = a[i];
	}

	dfs(0, 0, -1);
	cout << ans << '\n';
}
signed main() {
	int T = 1; 
	while(T--) solve();
	return 0;
}

/*

*/
