#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e16; 
int n, a[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void solve() {
	n = read();
	int Max = -INF, num1 = 0, num2 = 0, num3 = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(a[i] < 0) num1++, Max = max(Max, a[i]);
		else if(a[i] == 0) num2++;
	}
	if(num1 % 2 == 0) num3 = 0;
	else num3 = 1 - Max;
	cout << num2 + num3 << endl;
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		solve();
	//	init();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
