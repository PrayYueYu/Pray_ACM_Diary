#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, q, ne[N], to[N], num, fi[N], m, d[N], vis[N];
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
char st[10] = {'r', 'g', 'b'};
void init1() {
	for(int i = 0; i <= num + 5; i++) {
		fi[i] = to[i] = 0;
	}
	num = 0;
	for(int i = 0; i <= n + 5; i++) {
		fi[i] = d[i] = vis[i] = false;
	}
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num]  = v;
}
void solve1() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		add(u, v);
		add(v, u);
	}
	std::queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = true;
		for(int i = fi[u]; i; i = ne[i]) {
			int v = to[i];
			if(vis[v]) continue;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	
	for(int i = 1; i <= n; i++) {
		std::cout << st[d[i] % 3];
	}
	std::cout << '\n';
}
void solve2() {
	q = read();
	for(int i = 1; i <= q; i++) {
		int cnt = read();
		std::string s;
		std::cin >> s;
		s = " " + s;
		int f0 = 0, f1 = 0, f2 = 0;
		for(int j = 1; j <= cnt; j++) {
			if(s[j] == 'r') f0 = true;
			if(s[j] == 'g') f1 = true;
			if(s[j] == 'b') f2 = true;
		}
		if((!f0 && !f1) || (!f1 && !f2) || (!f0 && !f2)) {
			std::cout << 1 << '\n';
			continue;
		}
		if(!f0) {
			for(int j = 1; j <= cnt; j++) {
				if(s[j] == 'b') {
					std::cout << j << '\n';
					break;
				}
			}
		}
		if(!f1) {
			for(int j = 1; j <= cnt; j++) {
				if(s[j] == 'r') {
					std::cout << j << '\n';
					break;
				}
			}
		}
		if(!f2) {
			for(int j = 1; j <= cnt; j++) {
				if(s[j] == 'g') {
					std::cout << j << '\n';
					break;
				}
			}
		}
	}
}
signed main() {
	std::string test;
	std::cin >> test; 
	int T = read();
	while(T--) {
		if(test == "first") {
			solve1();
			init1();
		}
		else solve2();
//		init();
	}
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
