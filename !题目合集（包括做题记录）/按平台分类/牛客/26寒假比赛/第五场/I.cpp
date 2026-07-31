#include<bits/stdc++.h>
#define int long long
//#define int __int128
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, h, d[N], d1[N], d2[N], p[N], f[N];
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
bool check(int mid) {
	for(int i = 0; i <= n + 10; i++) {
		d[i] = d1[i] = d2[i] = 0;
	}
	for(int i = 1; i <= mid; i++) {
		int l = std::max(1ll, p[i] - f[i] + 1);
		int fl = f[i] - (p[i] - l);
		int r = std::min(n, p[i] + f[i] - 1);
		int fr = f[i] - (r - p[i]);
		d[l] += fl;
		d[l + 1] += (1 - fl);
		d[p[i] + 1] -= 2;
		d[r + 1] += (1 - fr);
		d[r + 2] += fr;
	}
	for(int i = 1; i <= n; i++) {
		d1[i] = d1[i - 1] + d[i];
	}
	for(int i = 1; i <= n; i++) {
		d2[i] = d2[i - 1] + d1[i];
		if(d2[i] > h) return false;
	}
	return true;
}
void solve() {
	n = read(), m = read(), h = read();
	for(int i = 1; i <= m; i++) {
		p[i] = read(), f[i] = read();
	}
	int l = 1, r = m;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	int ans = -1;
	for(int i = std::max(1ll, l - 10); i <= std::min(m, l + 10); i++) {
		if(!check(i)) {
			ans = i;
			break;
		}
	}
	if(ans == -1) std::cout << "No";
	else std::cout << "Yes\n" << ans;
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
