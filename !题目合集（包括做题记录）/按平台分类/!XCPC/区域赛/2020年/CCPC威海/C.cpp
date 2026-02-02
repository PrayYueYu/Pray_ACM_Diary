#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int INF = 1e18, N = 1e6 + 100;
int d[4][N], n, vis[4][N], cnt[4][N], k[6];
int ne[N], to[N], fi[N], w[N], num;
int sum[4], las[4][N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void add(int u, int v, int c) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
	w[num] = c;
}
void dfs(int u, int fa) {
	for(int i = 1; i <= 3; i++) {
		if(vis[i][u]) cnt[i][u]++;
	}
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs(v, u);
		for(int j = 1; j <= 3; j++) {
			cnt[j][u] += cnt[j][v];
			d[j][u] += d[j][v];
			d[j][u] += cnt[j][v] * w[i];
		}
	}
}
int Find(int x, int y) {
	for(int i = 1; i <= 3; i++) {
		if(i != x && i != y) return i;
	}
	return 0;
}
void getsum(int u, int fa) {
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		for(int j = 1; j <= 3; j++) {
			d[j][u] -= (cnt[j][v] * w[i] + d[j][v]);
			cnt[j][u] -= cnt[j][v];
			d[j][v] += d[j][u] + cnt[j][u] * w[i];
			las[j][v] = cnt[j][v];
			cnt[j][v] = k[j];
		}	
		getsum(v, u);
		for(int j = 1; j <= 3; j++) {
			cnt[j][v] = las[j][v];
			d[j][v] -= (d[j][u] + cnt[j][u] * w[i]);
			cnt[j][u] += cnt[j][v];
			d[j][u] += cnt[j][v] * w[i] + d[j][v];
		}
	}
	int sx = 0;
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			if(!vis[i][u]) continue;
			if(i == j) continue;
			int el = Find(i, j);
			sum[el] += d[j][u];
		}
	}
}
signed main() {
    n = read();
    for(int i = 1; i < n; i++) {
    	int u = read(), v = read(), c = read();
    	add(u, v, c);
    	add(v, u, c);
	}
	for(int i = 1; i <= 3; i++) {
		k[i] = read();
		for(int j = 1; j <= k[i]; j++) {
			int x = read();
			vis[i][x] = true;
		}
	}
	
	dfs(1, 0);
	getsum(1, 0);
	
	long double ans = 0;
	ans += (double)sum[1] / (double)(k[2] * k[3]);
	ans += (double)sum[2] / (double)(k[1] * k[3]);
	ans += (double)sum[3] / (double)(k[1] * k[2]);
	ans /= 4.0;
	printf("%.10Lf", ans);
    return 0;
}
/*

*/
