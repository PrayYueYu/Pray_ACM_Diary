#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 3e5 + 100, M1 = 1e9 + 7, INF = 1e16;	
int n, m, f[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

signed main(){
	//freopen("1.in", "r", stdin);
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		f[u]++, f[v]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int resn = n - 1, resm = m - f[i];
		if(resn % 2 == 0 && resm % 2 == 0) ans++;
	}
	if(n % 2 == 0 && (m - 1) % 2 == 0) ans += m;
	cout << ans;
	return 0;
}
/*

*/
