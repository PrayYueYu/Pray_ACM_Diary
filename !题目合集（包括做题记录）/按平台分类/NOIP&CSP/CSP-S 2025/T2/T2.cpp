#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 100, INF = 2e18;
int n, m, k, fa[N], vis[N], c[N], cnt, ans;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
struct Pa {
	int u, v, w;
} p[N], s[N * 2];
bool cmp(Pa x, Pa y) {
	return x.w < y.w;
}
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
int solve(int num) {
	int now = 0;
	num += n;
	for(int i = 1; i <= n + k; i++) fa[i] = i;
	for(int i = 1; i <= cnt; i++) {
		//cout << s[i].u << " " << s[i].v << endl;
		if(s[i].u > n) {
			if(!vis[s[i].u]) continue;
		}
		int fau = getfa(s[i].u);
		int fav = getfa(s[i].v);
		if(fau == fav) continue;
		
		now += s[i].w;
		fa[fau] = fav;
		num--;
		if(num == 0) break;
	}
	return now;
}
void dfs(int t) {
	if(t == k + 1) {
		int now = 0, num = 0;
		for(int i = 1; i <= k; i++) {
			if(vis[i + n]) {
				now += c[i];
				num++;
			}
		}
		//if(num) return;
		//cout << now << " " << solve(num) << endl;
		ans = min(ans, solve(num) + now);
		return;
	}
	vis[t + n] = true;
	dfs(t + 1);
	vis[t + n] = false;
	dfs(t + 1);
}
signed main() {
	//freopen("road3.in", "r", stdin);
	ans = INF;
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read(), c = read();
		p[i] = {u, v, c};
	} 
	sort(p + 1, p + m + 1, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		int fau = getfa(p[i].u);
		int fav = getfa(p[i].v);
		if(fau == fav) continue;
		fa[fau] = fav;
		s[++cnt] = p[i];
		if(cnt == n - 1) break;
	}
	for(int i = 1; i <= k; i++) {
		c[i] = read();
		for(int j = 1; j <= n; j++) {
			int x = read();
			s[++cnt] = {n + i, j, x};
		}
	}
	sort(s + 1, s + cnt + 1, cmp);
	dfs(1);
	cout << ans;
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/

