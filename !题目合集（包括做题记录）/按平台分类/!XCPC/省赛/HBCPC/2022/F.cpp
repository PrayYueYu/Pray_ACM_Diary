#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, a[N];
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
void solve() {
	n = read(), m = read();
	int sum = 0;
	int ans = 0, cnt = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		sum += a[i] / 2;
	}
	if(sum < m) {
		std::cout << "-1\n";
		return;
	}
	std::sort(a + 1, a + n + 1);
	ans = n;
	for(int i = n; i >= 1; i--) {
		a[i]--;
		if(!(a[i] & 1)) {
			if(cnt + a[i] / 2 < m) {
				cnt += a[i] / 2;
				ans += a[i];
				a[i] = 0;
			}
			else {
				ans += (m - cnt) * 2;
				ans--;
				cnt = m;
				break;
			}
		}
		else {
			if(cnt + a[i] / 2 < m) {
				cnt += a[i] / 2;
				ans += a[i] - 1;
				a[i] = 1;
			}
			else {
				ans += (m - cnt) * 2;
				ans--;
				cnt = m;
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(cnt == m) break;
		if(a[i] == 1) {
			ans++;
			cnt++;
		}
	}
	std::cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
