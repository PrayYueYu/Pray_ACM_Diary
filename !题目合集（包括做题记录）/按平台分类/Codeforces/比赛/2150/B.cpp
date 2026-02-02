#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e5 + 100, M = 1e9 + 7, INF = 1e9; 
int n, m, a[N], ans[N];
string s;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
map<int, int> mp, to;
void init() {
	mp.clear();
	to.clear();
}
void solve() {
	n = read(); m = read();
	cin >> s; s = " " + s;
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		a[i] = read();
		ans[++cnt] = a[i];
		mp[a[i]] = true;
	}
	for(int i = m; i >= 1; i--) {
		if(a[i] != a[i + 1] - 1 || i == m) {
			to[a[i]] = a[i] + 1;
		}
		else {
			to[a[i]] = to[a[i + 1]];
		}
	}
	int now = 1;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'A') now++;
		else {
			if(!mp[now + 1]) now++;
			else now = to[now + 1];
		}
		
		if(!mp[now]) {
			ans[++cnt] = now;
			mp[now] = true;
		}
		if(s[i] == 'B') {
			if(!mp[now + 1]) now++;
			else now = to[now + 1];
		}
	}
	sort(ans + 1, ans + cnt + 1);
	cout << cnt << endl;
	for(int i = 1; i <= cnt; i++) cout << ans[i] << " ";
	cout << endl;
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
