#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 10, INF = 1e13 + 7, M = 1e16;
ll k, n, m, x;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct Test {
	ll c, b;
} s[N];
bool cmp(Test x, Test y) {
	ll tx = x.c - x.b * k;
	ll ty = y.c - y.b * k;
	return tx > ty;
}
int main() {
	//freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		n = read(), m = read(), k = read(), x = read();
		for(int i = 1; i <= n; i++) {
			s[i].b = read();
			s[i].c = read(); 
		}
		if(n * x < m) {
			cout << "NO\n";
			continue;
		}
		sort(s + 1, s + n + 1, cmp);
		ll sc = x, ans1 = 0, ans1num = 0;
		ll ans2 = 0, ans2num = 0;
		int F = true;
		for(int i = 1; i <= n; i++) {
			if(!F) sc = 0; 
			else if(i * x >= m && F) {
				sc = m - (i - 1) * x;
				m = 0;
				F = false;
			}
			else sc = x;
			ll t = s[i].c + k * sc;
			ans1 = ans1 + t * sc;
			if(ans1 >= M) {
				ans1num += ans1 / M;
				ans1 %= M;
			}
			ans2 = ans2 + t * s[i].b;
			if(ans2 >= M) {
				ans2num += ans2 / M;
				ans2 %= M;
			}
		}
		if(ans1num > ans2num) cout << "YES\n";
		else if(ans1num < ans2num) cout << "NO\n";
		else {
			if(ans1 > ans2) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
/*

*/
