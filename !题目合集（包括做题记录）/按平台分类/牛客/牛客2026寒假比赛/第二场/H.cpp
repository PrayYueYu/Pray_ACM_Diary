#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int n, a[N], f[N], nex[N];
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
std::map<int, int> mp;
int calc(int x) {
	return (x * (x + 1)) / 2;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = n; i >= 1; i--) {
		if(!mp[a[i]]) nex[i] = n + 1;
		else nex[i] = mp[a[i]];
		mp[a[i]] = i;
	}
	f[n] = 1;
	int ans = 1;
	for(int i = n - 1; i >= 1; i--) {
		f[i] = n - i + 1;
		f[i] += f[i + 1] + calc(n - i) - calc(n - nex[i] + 1);
		ans += f[i]; 
	}
	std::cout << ans << '\n';
	mp.clear();
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
