#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7, INF = 1e18;
int n, ansu[N], ansv[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
vector<int> p[N];
void solve() {
	n = read();
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		p[u].push_back(v);
		p[v].push_back(u);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		for(auto x: p[i]) {
			ansu[++cnt] = x;
			ansv[cnt] = i;
		}
		if(p[i].size() % 2 == 0) {
			ansu[++cnt] = i;
			ansv[cnt] = i;
		}
	}
	cout << cnt << '\n';
	for(int i = 1; i <= cnt; i++) {
		cout << ansu[i] << ' ' << ansv[i] << '\n';
	}
	for(int i = 1; i <= n; i++) p[i].clear();
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
