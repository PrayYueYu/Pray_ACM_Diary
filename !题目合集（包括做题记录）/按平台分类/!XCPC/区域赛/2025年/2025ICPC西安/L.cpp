#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int a[N], n, sum[N], ans[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		ans[i] = 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int re = n - 1;
	for(int i = n; i >= 3; i--) {
		re = min(re, i - 1);
		int l = 2, r = re;
		if(re < l) break;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(sum[i - 1] - sum[i - mid - 1] > a[i]) r = mid;
			else l = mid + 1;
		}
		int F = true;
		for(int j = l; j <= re; j++) {
			if(sum[i - 1] - sum[i - j - 1] <= a[i]) {
				F = false;
				break;
			}
			ans[j + 1] = sum[i] - sum[i - j - 1];
		}
		if(F) re = l - 1;
	}
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
