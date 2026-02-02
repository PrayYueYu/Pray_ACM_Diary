#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 5e6 + 100, M = 998244353, INF = 1e18; 
int n, f[N];
string s;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void solve() {
	n = read();
	cin >> s;
	for(int i = 0; i < (1 << n); i++) f[i] = 0;
	f[0] = 1;
	for(int i = 1; i < (1 << n); i++) {
		int las = 0;
		for(int j = 0; j < n; j++) {
			if(!(i >> j & 1)) continue;
			if((int)s[j] == las) continue;
			int t = (i ^ (1ll << j));
			f[i] += f[t];
			f[i] %= M;
			las = s[j];
		}
	}
	int All = (1 << n) - 1;
	cout << f[All] << endl;
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = 1;
	while(T--) {
		solve();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
