#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e18; 

ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void solve() {
	int n = read();
	int s1 = n, s2 = 0, ans = 0;
	int ds2 = 0;
	while(true) {
		s2 += ds2;
		//cout << s1 << " " << s2 << endl;
		if(s1 == 1 && s2 == 1) break;
		ds2 = 0;
		if(s1 >= 2) {
			ds2 = s1 / 2;
			ans += s1 / 2;
			if(s1 % 2 == 0) {
				s1 = s1 / 2;
			}
			else s1 = s1 / 2 + 1;
		}
		if(s2 >= 2) {
			ans += s2 / 2;
			if(s2 % 2 == 0) {
				s2 /= 2;
			}
			else s2 = s2 / 2 + 1;
		}
		
	}
	cout << ans + 1 << endl;
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
