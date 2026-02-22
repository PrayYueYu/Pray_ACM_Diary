#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 4e4 + 10, mod = 998244353, INF = 1e18;
int d, p;
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
struct A {
	int health, f;
	std::string name, id, time;
} g[N], ans[N];
bool cmp(A x, A y) {
	if(x.time == y.time) return x.f < y.f; 
	return x.time < y.time;
}
std::map<std::string, int> mp, vis;
bool check(std::string x) {
	if(x.size() != 18) return false;
	for(int i = 0; i <= 17; i++) {
		if(x[i] < '0' || x[i] > '9') return false;
	}
	return true;
}
void solve() {
	d = read(), p = read();
	int cnt = 0;
	for(int i = 1; i <= d; i++) {
		int t = read(), s = read();
		for(int j = 1; j <= t; j++) {
			std::cin >> g[j].name;
			std::cin >> g[j].id;
			std::cin >> g[j].health;
			std::cin >> g[j].time;
			g[j].f = j;
			if(!check(g[j].id)) continue;
			if(g[j].health) {
				if(!vis[g[j].id]) {
					vis[g[j].id] = true;
					ans[++cnt] = g[j];
				}
			}
		}
		std::sort(g + 1, g + t + 1, cmp);
		for(int j = 1; j <= t; j++) {
			if(!check(g[j].id)) continue;
			if(mp[g[j].id] && i - mp[g[j].id] <= p) continue;
			if(!s) continue;
			mp[g[j].id] = i;
			std::cout << g[j].name << ' ' << g[j].id << '\n';
			s--;
		}
	}
	for(int i = 1; i <= cnt; i++) {
		std::cout << ans[i].name << ' ' << ans[i].id << '\n';
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:
4 2
5 3
A 123456789012345670 1 13:58
B 123456789012345671 0 13:58
C 12345678901234567 0 13:22
D 123456789012345672 0 03:24
C 123456789012345673 0 13:59
4 3
A 123456789012345670 1 13:58
E 123456789012345674 0 13:59
C 123456789012345673 0 13:59
F F 0 14:00
1 3
E 123456789012345674 1 13:58
1 1
A 123456789012345670 0 14:11
*/
