#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 5e5 + 100, M = 998244353, INF = 1e16;
int n, r[N];
int read() {
	int x;
	cin >> x;
	return x;
}
signed main() {
	n = read();
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		r[u]++;
		r[v]++;
	}
	if(n == 2) {
		cout << "Bob";
		return 0;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(r[i] == 1) cnt++;
	}
	cnt = n - 1 - cnt;
	if(cnt & 1) cout << "Alice";
	else cout << "Bob";
	return 0;
}
/*

*/
