#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5; 
int n, sx[N], sy[N], sz[N], m;
int read() {
	int x;
	cin >> x;
	return x;
}
map<int, int> m1, m2, m3;
void solve() {
	m1.clear(), m2.clear(), m3.clear();
	n = read(), m = read();
	int tot = 0;
	for(int i = 1; i <= n; i++) {
		sx[i] = read();
		sy[i] = read();
		sz[i] = read();
		m1[sx[i]]++;
		m2[sy[i]]++;
		m3[sz[i]]++;
	}
	for(int i = 1; i <= m; i++) {
		sx[i + n] = read();
		sy[i + n] = read();
		sz[i + n] = read();
		m1[sx[i + n]]++;
		m2[sy[i + n]]++;
		m3[sz[i + n]]++;
	}
	for(int i = 1; i <= n + m; i++) {
		if(m1[sx[i]] % 2 == 1) {
			cout << "No\n";
			return;
		}
		if(m2[sy[i]] % 2 == 1) {
			cout << "No\n";
			return;
		}
		if(m3[sz[i]] % 2 == 1) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
/*
1
19 198
*/
