#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int read() {
	int x;
	cin >> x;
	return x;
}
void solve() {
	n = read();
	if(n & 1) cout << n << '\n';
	else cout << (n ^ (n / 2)) << '\n';
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
