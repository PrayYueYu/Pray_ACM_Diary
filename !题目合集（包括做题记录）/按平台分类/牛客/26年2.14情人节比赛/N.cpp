#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, q, x[N], y[N];
char c[N];
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
struct S {
	int t, x, y, id, ans;
} s[N];
bool cmp1(S x, S y) {
	return x.t < y.t;
}
bool cmp2(S x, S y) {
	return x.id < y.id;
}
std::map<int, int> mp;
bool check(int xx, int yy) {
	if(xx == 0 || yy == 0 || xx > n || yy > n) return false;
	return true;
}
void solve() {
	n = read(), m = read(), q = read();
	for(int i = 1; i <= m; i++) {
		x[i] = read(), y[i] = read();
		std::cin >> c[i];
		mp[x[i] * (n + 2) + y[i]]++;
	}
	for(int i = 1; i <= q; i++) {
		s[i].t = read();
		s[i].x = read();
		s[i].y = read();
		s[i].id = i;
	}
	std::sort(s + 1, s + q + 1, cmp1);
	int id = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			mp[x[j] * (n + 2) + y[j]]--;
			if(check(x[j], y[j])) {
				if(c[j] == 'U') x[j]--;
				if(c[j] == 'D') x[j]++;
				if(c[j] == 'L') y[j]--;
				if(c[j] == 'R') y[j]++;
			}
			mp[x[j] * (n + 2) + y[j]]++;
		}
		while(true) {
			if(id > q) break;
			if(s[id].t > i) break;
			if(s[id].t == i) {
				s[id].ans = mp[s[id].x * (n + 2) + s[id].y];
				id++;
			}
		}
	}
	std::sort(s + 1, s + q + 1, cmp2);
	for(int i = 1; i <= q; i++) {
		std::cout << s[i].ans << '\n';
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
