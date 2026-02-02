#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e6 + 100, M = 998244353, INF = 1e18; 
int n, a[N], vis[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
signed main() {
	//freopen("1.in", "r", stdin);
	n = read(); int f = 0;
	for(int i = 1; i <= n; i++) {
		int x = read();
		a[i] = x;
		if(x == -1) continue;
		vis[x]++;
		if(vis[x] >= 2) {
			f = true;
		}
	}
	if(f) {
		cout << "No";
		return 0;
	}
	int now = 1;
	cout << "Yes\n";
	for(int i = 1; i <= n; i++) {
		if(a[i] == -1) {
			while(true) {
				if(!vis[now]) break;
				else now++;
			}
			cout << now << " ";
			now++;
		}
		else cout << a[i] << " ";
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
