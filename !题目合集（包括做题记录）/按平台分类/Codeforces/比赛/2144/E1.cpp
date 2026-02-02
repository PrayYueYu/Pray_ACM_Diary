#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 5e3 + 100, M = 998244353, INF = 1e16;	
int n, h[N], lh[N], rh[N], f[N][3][3], p[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void init() {
	for(int i = 0; i <= n + 5; i++) {
		for(int j = 0; j <= 1; j++) {
			f[i][j][0] = f[i][j][1] = 0;
		}
	}
}
signed main(){
	
	//freopen("1.in", "r", stdin);
	p[0] = 1;
	for(int i = 1; i <= N - 10; i++) {
		p[i] = p[i - 1] * 2ll;
		p[i] %= M;
	}
	int T = read();
	while(T--) {
		n = read();
		for(int i = 1; i <= n; i++) {
			h[i] = read();
		}
		int lcnt = 0, Max = -INF;
		for(int i = 1; i <= n; i++) {
			if(h[i] > Max) {
				lh[++lcnt] = h[i];
				Max = h[i];
			}
		}
		int rcnt = 0; Max = -INF;
		for(int i = n; i >= 1; i--) {
			if(h[i] > Max) {
				rh[++rcnt] = h[i];
				Max = h[i];
			}
		}
		init();
		for(int i = 1; i <= n; i++) {
			if(h[i] == lh[1]) f[i][1][0] = 1;
			if(h[i] == rh[1]) f[i][1][1] = 1;
		}
		for(int j = 2; j <= lcnt; j++) {
			int sum = 0;
			for(int i = 1; i <= n; i++) f[i][j % 2][0] = 0;
			for(int i = 1; i <= n; i++) {
				if(h[i] == lh[j]) f[i][j % 2][0] = sum;
				if(h[i] <= lh[j - 1]) sum *= 2ll;
				if(h[i] == lh[j - 1]) sum += f[i][(j - 1) % 2][0];
				sum %= M;
			}
		}
		for(int j = 2; j <= rcnt; j++) {
			int sum = 0;
			for(int i = 1; i <= n; i++) f[i][j % 2][1] = 0;
			for(int i = n; i >= 1; i--) {
				if(h[i] == rh[j]) f[i][j % 2][1] = sum;
				if(h[i] <= rh[j - 1]) sum *= 2ll;
				if(h[i] == rh[j - 1]) sum += f[i][(j - 1) % 2][1];
				sum %= M;
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				int res = max(0ll, j - i - 1);
				int now = p[res];
				now = now * f[i][lcnt % 2][0] % M;
				now = now * f[j][rcnt % 2][1] % M;
				ans += now;
				ans %= M;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*
1
9
3 5 5 7 4 6 7 2 4


5
5
4 2 4 8 3
5
1 2 3 2 1
6
1 2 3 3 2 1
9
3 5 5 7 4 6 7 2 4
1
10

*/
