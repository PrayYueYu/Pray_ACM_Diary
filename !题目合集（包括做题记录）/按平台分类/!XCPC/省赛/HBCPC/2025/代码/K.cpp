#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, a[N], l[N], r[N];
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
void solve() {
	n = read(), m = read();
	std::string s;
	for(int i = 0; i < n; i++) {
		a[i] = read();
		r[i] = i + 1;
		l[i] = i - 1;
	}
	l[0] = n - 1; r[n - 1] = 0;
	std::cin >> s;
	int now = 0, f = 1;
	for(int i = 0; i < m; i++) {
		if(s[i] == 'S') {
			a[now]--;
			if(!a[now]) {
				r[l[now]] = r[now];
				l[r[now]] = l[now];
			}
			if(f) {
				now = r[now];
				now = r[now];
			}
			else {
				now = l[now];
				now = l[now];
			}
		}
		else if(s[i] == 'C') {
			a[now]--;
			if(!a[now]) {
				r[l[now]] = r[now];
				l[r[now]] = l[now];
			}
			if(f) now = r[now];
			else now = l[now];
		}
		else if(s[i] == 'R') {
			a[now]--;
			if(!a[now]) {
				r[l[now]] = r[now];
				l[r[now]] = l[now];
			}
			f = f ^ 1;
			if(f) now = r[now];
			else now = l[now];
		}
		else {
			a[now]--;
			if(!a[now]) {
				r[l[now]] = r[now];
				l[r[now]] = l[now];
			}
			if(f) now = r[now];
			else now = l[now];
			a[now] += 2;
			if(f) now = r[now];
			else now = l[now];
		}
	}
	for(int i = 0; i < n; i++) std::cout << a[i] << '\n';
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
