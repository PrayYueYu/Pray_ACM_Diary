#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int INF = 1e16, N = 1e6 + 100;
int n, m;
int f[N][22][3], k, a[N];
string s;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void init() {
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= k; j++) {
			f[i][j][0] = f[i][j][1] = 0;
		}
	}
}
void solve() {
	n = read(), m = read(), k = read();
	cin >> s;
	s = " " + s;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'A') a[i] = 0;
		else a[i] = 1;
	}
	vector<vector<int>> p;
	p.resize(n + 5);
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		p[u].push_back(v);
	}
	k *= 2;
	for(int i = 1; i <= n; i++) {
		if(a[i] == 0) {
			f[i][k][0] = 1;
			f[i][k][1] = 0;
		}
		else {
			f[i][k][0] = 0;
			f[i][k][1] = 1;
		}
	}
	for(int i = k - 1; i >= 0; i--) {
		for(int u = 1; u <= n; u++) {
			int s1 = 0, s2 = 0;
			for(auto v: p[u]) {
				if(!f[v][i + 1][1]) s1 = 1;
				if(!f[v][i + 1][0]) s2 = 1;
			}
			f[u][i][0] = s1;
			f[u][i][1] = s2;
		}
	}
	if(f[1][0][0] == 1) cout << "Alice\n";
	else cout << "Bob\n";
}
signed main() {
    int T = read();
    while(T--) {
    	solve();
    //	init();
	}
    return 0;
}
/*

*/
