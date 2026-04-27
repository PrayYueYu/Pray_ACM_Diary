#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int n, m, l[N], r[N], f[N][26], p[50];
std::map<int, int> mp;
std::set<int> ls;
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
	mp.clear();
	ls.clear();
}
struct S {
	int l, r;
} s[N];
bool cmp(S x, S y) {
	if(x.r == y.r) return x.l < y.l;
	return x.r < y.r;
}
void solve() {
	//输入 
	n = read();
	for(int i = 1; i <= n; i++) {
		s[i].l = read(), s[i].r = read();
		ls.insert(s[i].l);
		ls.insert(s[i].r);
	}
	m = read();
	for(int i = 1; i <= m; i++) {
		l[i] = read(), r[i] = read();
		ls.insert(l[i]);
		ls.insert(r[i]);
	}
	//离散化 
	int cnt = 0;
	for(auto x: ls) {
		mp[x] = ++cnt;
	}
	for(int i = 1; i <= n; i++) {
		s[i].l = mp[s[i].l];
		s[i].r = mp[s[i].r];
	}
	//倍增 
	std::sort(s + 1, s + n + 1, cmp);
	int now = 1;
	s[n + 1].r = cnt + 1;
	for(int i = 1; i <= cnt; i++) {
		while(true) {
			if(now > n) break;
			if(s[now].l < i) now++;
			else break;
		}
		f[i][0] = s[now].r;
	}
	f[cnt + 1][0] = cnt + 1;
	for(int j = 1; j <= 25; j++) {
		for(int i = 1; i <= cnt + 1; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	//求答案 
	for(int i = 1; i <= m; i++) {
		l[i] = mp[l[i]];
		r[i] = mp[r[i]];
		int ans = 0;
		now = l[i];
		for(int j = 25; j >= 0; j--) {
			if(f[now][j] <= r[i]) {
				ans += p[j];
				now = f[now][j];
			}
		}
		std::cout << ans << '\n';
	}
	for(int i = 0; i <= cnt + 2; i++) {
		for(int j = 0; j <= 25; j++) {
			f[i][j] = 0;
		}
	}
}
signed main() {
	p[0] = 1;
	for(int i = 1; i <= 30; i++) p[i] = p[i - 1] * 2;
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
