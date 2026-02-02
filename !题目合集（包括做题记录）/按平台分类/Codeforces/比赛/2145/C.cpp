#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 10, INF = 1e16;
int n;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
map<int, int> mp;
void solve() {
	n = read();
	string s;
	cin >> s;
	s = " " + s;
	int suma = 0, sumb = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'a') suma++;
		else sumb++;
	}
	if(suma == sumb) {
		cout << 0 << endl;
		return;
	}
	if(!suma || !sumb) {
		cout << -1 << endl;
		return;
	}
	int F = false, all = 0;
	int ans = INF, d = abs(suma - sumb);
	mp.clear();
	mp[0] = n + 1;
	for(int i = n; i >= 1; i--) {
		if(suma > sumb) {
			if(s[i] == 'a') all++;
			else all--;
		}
		else {
			if(s[i] == 'b') all++;
			else all--;
		}
		if(mp[all - d]) {
			ans = min(ans, mp[all - d] - i);
		}
		mp[all] = i;
	}
	if(ans == INF || ans == n) cout << -1 << endl;
	else cout << ans << endl;
}
signed main() {
   int T = read();
   while(T--) {
		solve();
	//	init();
   }
    return 0;
}
/*

*/
