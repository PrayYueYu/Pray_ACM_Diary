#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 5e3, M = 998244353, INF = 1e14;
char ans[100] = {'(', ')'};
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
signed main() {
	freopen("1.in", "w", stdout);
	srand(time(0));
	int T = 1000000;
	cout << T << endl;
	while(T--) {
		int n = 1;
		for(int i = 1; i <= n; i++) {
			int x = rand() % 2;
			cout << ans[x];
		}
		cout << endl;
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
