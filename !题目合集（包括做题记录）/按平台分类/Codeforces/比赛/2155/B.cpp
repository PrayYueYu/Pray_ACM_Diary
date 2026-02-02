#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e2 + 100, M = 998244353, INF = 1e18; 
int n, k, ans[N][N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void solve() {
	n = read(), k = read();
	if(n == 2 && k == 1) {
		cout << "YES\n";
		cout << "UD\n";
		cout << "RU\n";
		return;
	}
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++) ans[i][j] = 0;
	int f = 1;
	for(int i = 1; i <= n; i++) {
		if(!k) break;
		for(int j = 1; j <= n; j++) {
			ans[j][i] = 1;
			k--;
			if(!k) {
				if(n - j == 1) {
					if(i == n || (i != n && n <= 2)) {
						f = false;
					}
					else {
						ans[1][i + 1] = 1;
						ans[j][i] = 0;
					}
				}
				break;
			}
		}
	}
	if(!f) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(ans[i][j]) {
				cout << "U";
				continue;
			}
			if(i == 1 || ans[i - 1][j]) {
				cout << "D";
			}
			else cout << "U";
		}
		cout << endl;
	}
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = read(); 
	while(T--) {
		solve();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
