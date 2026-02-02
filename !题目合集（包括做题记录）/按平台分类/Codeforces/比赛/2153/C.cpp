#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e16;
int n, a[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}

void solve() {
	n = read();
	int ans = -INF, sum = 0, Max = -INF, num = 0;
	int Mex = -INF;
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		if(a[i] == a[i + 1]) {
			sum += 2 * a[i];
			num += 2;
			i++;
		}
	}
	if(num >= 4) {
		ans = sum;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] == a[i + 1]) {
			i++;
		}
		else {
			if(sum > a[i]) {
				Max = a[i];
			}
		}
	}
	if(Max != -INF) ans = max(ans, Max + sum);
	int las = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == a[i + 1]) {
			i++;
		}
		else {
			Max = a[i];
			if(las) {
				if(Max - las < sum) {
					ans = max(Max + las + sum, ans);
				}
			}
			las = a[i];
		}
	}
	if(ans > 0) cout << ans << endl;
	else cout << 0 << endl;
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
