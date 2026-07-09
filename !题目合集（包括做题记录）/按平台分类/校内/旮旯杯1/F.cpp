#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int ne[N], to[N], fi[N], w[N], n, m, num, d[N];
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
void add(int u, int v, int c) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
	w[num] = c;
}
void solve() {
	std::cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int op, a, b, c;
		std::cin >> op >> a >> b;
		if(op == 1) {
			std::cin >> c;
			add(a, b, -c);
		}
		if(op == 2) {
			std::cin >> c;
			add(b, a, c);
		}
		if(op == 3) {
			add(a, b, 0);
			add(b, a, 0);
		}
	}
	for(int i = 1; i <= n; i++) {
		int f = false;
		for(int u = 1; u <= n; u++) {
			for(int j = fi[u]; j; j = ne[j]) {
				int v = to[j];
				if(d[v] > d[u] + w[j]) {
					d[v] = d[u] + w[j];
					f = true;
				}
			}
		}
		if(!f) break; 
		if(i == n && f) {
			std::cout << "No\n";
			return;
		}
	}
	std::cout << "Yes\n";
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
	Writer: ����ޱ�� 
*/
