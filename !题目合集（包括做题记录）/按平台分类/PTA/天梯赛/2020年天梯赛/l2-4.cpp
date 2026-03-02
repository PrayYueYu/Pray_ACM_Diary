#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, fl[300][300], vis[N];
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
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read(), d = read();
		fl[u][v] = fl[v][u] = d;
	}
	int q = read(), id = 0, minn = INF, ans_cnt = 0;
	for(int i = 1; i <= q; i++) {
		int cnt = read(), f = true, las = 0, sum = 0;
		if(cnt != n) f = false;
		for(int j = 1; j <= n; j++) vis[j] = false;
		for(int j = 1; j <= cnt; j++) {
			int x = read();
			if(!f) continue;
			if(vis[x] == true) f = false;
			vis[x] = true;
			if(j == 1 || j == cnt) {
				if(!fl[0][x]) f = false;
				sum += fl[0][x];
			}
			if(j >= 2) {
				if(!fl[las][x]) f = false;
				sum += fl[las][x];
			}
			las = x;
		}
		if(!f) continue;
		ans_cnt++;
		if(sum < minn) {
			minn = sum;
			id = i;
		}
	}
	std::cout << ans_cnt << '\n' << id << ' ' << minn << '\n';
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
