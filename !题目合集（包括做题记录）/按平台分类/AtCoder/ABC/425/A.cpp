#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e6 + 100, M = 998244353, INF = 1e18; 
int n ;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
signed main() {
	//freopen("1.in", "r", stdin);
	n = read();
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(i & 1) ans -= pow(i, 3);
		else ans += pow(i, 3);
	}
	cout << ans;
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
