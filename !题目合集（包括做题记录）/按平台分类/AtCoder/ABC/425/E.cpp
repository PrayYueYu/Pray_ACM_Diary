#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 5e3 + 100, M = 998244353, INF = 1e18; 
int n, m, mod, num[N], p[N], vis[N], cnt, v[N][N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void init() {
	vis[1] = 1;
	for(int i = 2; i <= 5000; i++) {
		if(!vis[i]) {
			p[++cnt] = i;
		}
		for(int j = 1; j <= cnt; j++) {
			if(p[j] * i > 5000) break;
			vis[i * p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
	
	
	for(int i = 2; i <= 5000; i++) {
		for(int j = 1; j <= cnt; j++) v[i][j] = v[i - 1][j];
		int x = i;
		for(int j = 1; j <= cnt; j++) {
			while(true) {
				if(x % p[j] != 0) break;
				x /= p[j];
				v[i][j]++;
			}
		}
	}
}
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ans;
}
void solve() {
	n = read();
	int ans = 1, Max = -INF, sum = 0;
	for(int i = 1; i <= n; i++) {
		int x = read();sum += x;
		for(int j = 1; j <= cnt; j++) {
			num[j] += v[x][j];
		}
		
	}
	for(int i = 1; i <= cnt; i++) {
		if(!v[sum][i]) continue;
		int now = ksm(p[i], v[sum][i] - num[i]);
		ans = (ans * ksm(p[i], v[sum][i] - num[i]));
		ans %= mod;
		num[i] = 0;
	}
	cout << ans << endl;

}
signed main() {
	//freopen("1.in", "r", stdin);
	init();
	int T = read();
	mod = read();
	while(T--) {
		solve();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*
*/
