#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, m, vis[N];
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
	int a, id, h;
} s[N];
bool cmp(S x, S y) {
	return x.a < y.a;
}
void init() {
	for(int i = 0; i <= n; i++) {
		s[i].a = s[i].id = s[i].h = 0;
		vis[i] = 0;
	}
}
void solve() {
	n = read(); m = read();
	for(int i = 1; i <= n; i++) {
		s[i].a = read();
		s[i].id = i;
		s[i].h = s[i].a;
		vis[i] = false;
	}
	if(m > n / 2) {
		cout << -1 << '\n';
		return;
	}
	sort(s + 1, s + n + 1, cmp);
	int num = 0;
	vector<pair<int, int>> ans;
	ans.resize(2 * n);
	if(!m) {
		int f = false, now = 0;
		for(int i = 1; i < n; i++) {
			if(s[n].h - s[i].a <= 0) {
				now = i;
				f = true;
				break;
			}
			else {
				if(!vis[n]) {
					ans[++num] = {n, i};
					vis[n] = 1;
				}
				else ans[++num] = {i, n};
				s[n].h -= s[i].a;
			}
		}
		if(!f) {
			cout << -1 << endl;
			return;
		}
		for(int i = now; i < n; i++) {
			if(i + 1 == n) break;
			ans[++num] = {i, i + 1};
		}
		ans[++num] = {n - 1, n};
		cout << num << '\n';
		for(int i = 1; i <= num; i++) {
			cout << s[ans[i].first].id << ' ';
			cout << s[ans[i].second].id << endl;
		}
		return;
	}
	int t = n % m;
	int now = 1;
	for(int i = t + 1; i <= t + m; i++) {
		if(now == t + 1) break;
		ans[++num] = {i, now};
		now++;
	}
	while(true) {
		if(t == n - m) break;
		for(int i = t + 1; i <= t + m; i++) {
			ans[++num] = {m + i, i};
		}
		t += m;
	}
	cout << num << '\n';
	for(int i = 1; i <= num; i++) {
		cout << s[ans[i].first].id << ' ';
		cout << s[ans[i].second].id << endl;
	}
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
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
