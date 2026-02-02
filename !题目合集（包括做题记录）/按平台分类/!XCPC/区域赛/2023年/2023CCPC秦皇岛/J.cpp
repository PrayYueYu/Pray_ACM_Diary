#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e16; 
int n, m, f[N], cnt[N], W, p[N], a[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void dfs(int x, int now, int t, int sum, vector<int> & v) {

	if(sum > W) return;
	if(t == v.size()) {
		f[x] = min(f[x], f[now] + 1);
		return;
	} 
	dfs(x, now - p[v[t]], t + 1, sum + cnt[v[t] + 1], v);
	dfs(x, now, t + 1, sum, v);
}
void solve() {
	n = read(); W = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(a + 1, a + n + 1);
	int num = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] != a[i - 1]) {
			num++;
			cnt[num]++;
		}
		else cnt[num]++;
	}
	n = num;
	for(int i = 0; i < (1 << n); i++) f[i] = INF;
	f[0] = 0;
	for(int i = 1; i < (1 << n); i++) {
		vector<int> v; v.push_back(-10);
		for(int j = n; j >= 0; j--) {
			if((i >> j) & 1) {
				v.push_back(j);
			}
		}
		dfs(i, i, 1, 0, v);
	}
	cout << f[(1 << n) - 1];
}
signed main() {
	//freopen("1.in", "r", stdin);
	p[0] = 1;
	for(int i = 1; i <= 60; i++) p[i] = p[i - 1] * 2;
	int T = 1;
	while(T--) {
		solve();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
