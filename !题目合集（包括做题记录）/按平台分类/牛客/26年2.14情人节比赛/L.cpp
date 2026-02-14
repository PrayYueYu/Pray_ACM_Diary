#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N];
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
void solve() {
	int cnt = 0;
	n = read();
	for(int i = 1; i <= n; i++) {
		int x = read();
		a[i] = x;
		mp[x] ^= 1;
		if(mp[x] == 1) cnt++;
		else cnt--;
	}
	if(cnt) std::cout << "NO\n";
	else {
		std::cout << "YES\n";
		std::sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i++) std::cout << a[i] << ' ';
	}
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
