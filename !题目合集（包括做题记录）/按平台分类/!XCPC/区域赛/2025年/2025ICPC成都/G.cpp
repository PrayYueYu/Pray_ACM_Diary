#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
int read() {
	int x;
	cin >> x;
	return x;
}
void solve() {
	n = read(), k = read(), m = read() + 1;
	m = min(m, n);
	int x = n / k - 1;
	int ans = m;
	x = min(x, n - m);
	ans += x / 2;
	cout << ans << '\n';
}
signed main() {
    int T = read();
    while(T--) solve();
    return 0;
}
/*

*/
