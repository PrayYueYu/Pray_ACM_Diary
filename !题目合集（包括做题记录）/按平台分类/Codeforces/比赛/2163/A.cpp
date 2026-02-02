#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e5 + 100, M = 1e9 + 7, INF = 1e16; 
int n, a[N], num[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		num[a[i]]++;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		cnt += (num[i] / 2);
	}
	int F = true;
	sort(a + 1, a + n + 1);
	for(int i = 2; i < n; i += 2) {
		if(a[i] != a[i + 1]) F = false;
	}
	if(F) cout << "YES\n";
	else cout << "NO\n";
	for(int i = 1; i <= n; i++) {
		num[a[i]]--;
	}
}
signed main(){
	int T = read();
	while(T--) solve();
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
