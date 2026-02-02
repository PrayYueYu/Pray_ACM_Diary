#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000;
int n, m, a[N], vis[N], c[N];
ll ans, mod = 998244353, f[N];
ll read() {
	ll x;
	scanf("%lld", &x);
	return x;
}
void dfs(int t, int s1, int s2) {
	if(s2 >= m) {
		ans += f[n - t + 1];
		ans %= mod;
		return;
	}
	if(t == n + 1) {
		//cout << s1 << ' ' << s2 << endl;
		//if(s2 >= m) ans++;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		vis[i] = true;
		if(a[t] && s1 < c[i]) dfs(t + 1, s1, s2 + 1);
		else dfs(t + 1, s1 + 1, s2);
		vis[i] = false;
	}
}
signed main() {
	n = read(), m = read();
	string s = "";
	cin >> s;
	s = " " + s;
	f[0] = 1;
	int cnt = 0, num = 0;
	for(int i = 1; i <= n; i++) {
		f[i] = (f[i - 1] * i) % mod;
		a[i] = s[i] - '0';
		c[i] = read();
		if(a[i]) cnt++;
		if(!c[i]) num++;
	}
	if(num > n - m || cnt < m) {
		cout << 0;
		return 0;
	}
	if(m == n) {
		cout << f[n];
		return 0;
	}
	if(cnt == n) {
		cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(!c[i]) cnt++;
		}cout << cnt << endl;
		if(cnt > n - m) cout << 0;
		else {
			cout << f[n];
		}
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

*/
