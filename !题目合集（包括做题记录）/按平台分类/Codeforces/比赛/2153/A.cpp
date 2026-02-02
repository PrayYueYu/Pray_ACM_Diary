#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e9 + 10;
int n, a[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}

void solve() {
	n = read();
	int num = 0;
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		if(a[i] != a[i + 1] || i == n) num++;
	}
	cout << num << endl;
}
signed main() {
	int T = read();
	while(T--) {
		solve();
	}
	return 0;
}
/*

*/
