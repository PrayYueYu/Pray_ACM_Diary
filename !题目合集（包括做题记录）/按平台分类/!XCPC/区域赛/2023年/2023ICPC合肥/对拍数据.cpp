#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 5e3, M = 998244353, INF = 1e14;
int T, n, m, k;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
signed main() {
	freopen("1.in", "w", stdout);
	srand(time(0));
	n = rand() % 200000 + 1;
	m = rand() % n + 1;
	k = rand() % min(n, 5ll) + 1;
	cout << n << " " << m << " " << k << endl;
	for(int i = 1; i <= n; i++) {
		cout << rand() % 2;
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
