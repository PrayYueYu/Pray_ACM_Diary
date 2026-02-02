#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, a[N], ans[N];
int read() {
	int x;
	cin >> x;
	return x;
}
void solve() {
	n = read();
	int num = 0, f = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(!a[i]) num++;
		else f = a[i];
	}
	int sum = 1e9; int t = sum / 100;
	int now = 0;
	for(int i = 1; i <= n; i++) {
		ans[i] = a[i] * t;
		now += ans[i];
	}
	for(int i = 1; i <= n; i++) {
		if(now > sum && ans[i]) {
			int x = t / 2;
			x = min(x, now - sum);
			ans[i] -= x;
			now -= x;
		}
		else if(now < sum) {
			int x = t / 2 - 1;
			x = min(x, sum - now);
			ans[i] += x;
			now += x;
		}
	}
	if(now != sum) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';
}
signed main() {
    int T = read();
    while(T--) solve();
    return 0;
}
/*

*/
