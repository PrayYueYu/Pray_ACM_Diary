#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7, INF = 1e18;
int n, k, num, ans, vis[100], g[100];
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
vector<int> val[40];
void dfs(int t, int sum, int nown) {
	if(t == num + 1) {
		if(sum > k) return;
		int kx = k - sum, now = 0;
		for(int i = 1; i <= kx; i++) {
			int maxn = -1, l = -1, r = 0, p = 0;
			for(int j = 40; j >= 0; j--) {
				if((nown >> j & 1)) {
					if(l == -1) l = j;
				}
				else {
					if(l >= 0) {
						r = j + 1;
						if(maxn <= l - r + 1) {
							maxn = l - r + 1;
							p = r;
						}
					}
					l = r = -1;
				}
			}
			if(l >= 0) {
				r = 0;
				if(maxn <= l - r + 1) {
					maxn = l - r + 1;
					p = r;
				}
			}
			if(p == 40) {
				now += maxn;
				continue;
			}
			now += maxn;
			nown += (1ll << p);
		}
		ans = max(ans, now);
		return;
	}
	vis[t] = true;
	dfs(t + 1, sum + val[t].size(), nown + g[t]);
	vis[t] = false;
	dfs(t + 1, sum, nown);

}
void solve() {
	n = read(), k = read();
	int cnt = 0;
	for(int i = 0; i < 30; i++) {
		if(!(n >> i & 1)) cnt++;
		val[i].clear();
		g[i] = 0;
	}
	if(k > cnt) {
		cout << (k - cnt + 29) << '\n';
		return;
	}
	ans = 0;
	num = 1;
	for(int i = 0; i <= 29; i++) {
		if(!(n >> i & 1)) {
			val[num].push_back(i);
		}
		else {
			if(val[num].size()) num++;
		}
	}
	if(val[num].size() == 0) num--;
	for(int i = 1; i <= num; i++) {
		for(auto x: val[i]) {
			g[i] += (1ll << x);
		}
	}
	dfs(1, 0, n);
	
	cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
