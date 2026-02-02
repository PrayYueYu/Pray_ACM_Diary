#include<bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
const int N = 2e5 + 100, M = 1e9 + 7;//, INF = 1e16; 
int n, a[N], vis[N], ansl[N], ansr[N];
int read() {
	int x;
	scanf("%d", &x);
	return x;
}
void P(int l, int r) {
	int L = min(l, r);
	int R = max(l, r);
	cout << L << " " << R << endl;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	string s = "";
	cin >> s;
	s = " " + s;
	int d1 = 0, d2 = 0, F = true;
	for(int i = 1; i <= n; i++) {
		if(i == 1 || i == n) {
			if(s[i] == '1') {
				F = false;
			}
		}
		if(a[i] == 1 || a[i] == n) {
			if(s[i] == '1') {
				F = false;
			}
			if(!d1) d1 = i;
			else d2 = i;
		}
	}
	if(!F) {
		cout << -1 << endl;
		return;
	}
	cout << 5 << endl;
	P(d1, d2);P(1, d2);P(1, d1);P(d1, n);P(d2, n);
}
signed main(){
	int T = read();
	while(T--) solve();
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
