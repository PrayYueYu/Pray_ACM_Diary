#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n, sum[N], cnt[N][3], m, k, b;
int read() {
	int x;
	cin >> x;
	return x;
}
void solve() {
	n = read(), m = read(), k = read(), b = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int x = read();
			sum[i] += x;
			if(x <= 0) cnt[i][0]++;
			else cnt[i][1]++;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(sum[i] >= k) {
			ans++;
			continue;
		}
		int now = sum[i] + cnt[i][0] - cnt[i][1];
		if(now >= k && b) b--, ans++;
	}
	cout << ans << '\n';
	for(int i = 1; i <= n; i++) {
		cnt[i][0] = cnt[i][1] = sum[i] = 0;
	}
}
signed main() {
    int T = read();
    while(T--) solve();
    return 0;
}
/*

*/
