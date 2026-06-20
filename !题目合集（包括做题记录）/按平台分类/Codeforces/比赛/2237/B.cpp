#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int a[N], b[N], c[N], vis[N], p[N], n;
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
void init() {
	for(int i = 0; i <= n + 2; i++) vis[i] = false;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		c[i] = a[i];
	}
	for(int i = 1; i <= n; i++) b[i] = read();
	std::sort(c + 1, c + n + 1);
	for(int i = 1; i <= n; i++) {
		if(c[i] > b[i]) {
			std::cout << "-1\n";
			return;
		}
	}
	for(int i = n; i >= 1; i--) {
		for(int j = 1; j < i; j++) c[j] = a[j];
		std::sort(c + 1, c + (i - 1) + 1);
		int t1 = 0, t2 = 0;
		for(int j = 1; j < i; j++) {
			t1++, t2++;
			while(true) {
				if(vis[t2] && t2 < n) t2++;
				else break;
			}
			if(c[t1] > b[t2]) {
				t2++;
				while(true) {
					if(vis[t2] && t2 < n) t2++;
					else break;
				}
				p[t2] = true;
			}
			else p[t2] = true;
		}
		int id = 0;
		for(int j = 1; j <= n; j++) {
			if(vis[j]) continue;
			if(!p[j]) id = j;
			p[j] = 0;
		}
		a[i] = b[id];
		vis[id] = true;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(a[i] > a[j]) ans++; 
		}
	}
	std::cout << ans << '\n';
}
signed main() {
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
1
5
1 5 4 3 2
2 3 4 5 6
*/
