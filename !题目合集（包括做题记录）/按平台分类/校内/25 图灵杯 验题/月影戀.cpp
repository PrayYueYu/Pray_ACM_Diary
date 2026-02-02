#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
	ll a = 1ll << 60, ans = 0;
	while(true) {
		ll b = a - ans;
		cout << "? " << a << ' ' << b << '\n';
		cout.flush();
		ll g; scanf("%lld", &g);
		if(g == a) break;
		ans += g;
	}
	cout << "! " << ans << '\n';
	cout.flush();
}
signed main() {
	int T; scanf("%d", &T);
	while(T--) {
		solve();
	}
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
