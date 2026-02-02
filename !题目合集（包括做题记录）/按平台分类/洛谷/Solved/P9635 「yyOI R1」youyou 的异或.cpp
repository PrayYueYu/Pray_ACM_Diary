#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, a[N], vis[N];
int read() {
	int x;
	scanf("%d", &x);
	return x;
}
void solve() {
	n = read();
	if(n == 1) {
		cout << 1 << '\n';
		return;
	}
	if(n <= 8) {
		if(n == 1) {
			cout << 1 << '\n';
		}
		else if(n == 2) {
			cout << "3 1\n";
		}
		else if(n == 3) {
			cout << "-1\n";
		}
		else if(n == 4) {
			cout << "1 2 3 4\n";
		}
		else if(n == 5) {
			cout << "2 3 5 6 7\n";
		}
		else if(n == 6) {
			cout << "1 2 3 4 5 7\n";
		}
		else if(n == 7) {
			cout << "2 3 4 5 6 8 9\n";
		}
		else if(n == 8) {
			cout << "1 2 3 4 5 6 7 8\n";
		}
		return;
	}
	int ans = 0, cnt = 0, num = 0;
	for(int i = 20; i >= 0; i--) {
		if((n >> i & 1)) {
			num = i;
			break;
		}
	}
	for(int i = 1; i <= n - 2; i++) {
		a[++cnt] = i;
		ans = ans ^ i;
	}
	if(ans == n) {
		a[1] = n - 1;
		ans = (ans ^ 1 ^ (n - 1));
	}
	a[++cnt] = (1ll << (num + 1));
	ans ^= a[cnt];
	a[++cnt] = (ans ^ n);
	ans ^= a[cnt];
	
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += a[i];
		cout << a[i] << ' ';
	}
	cout << '\n';
//	cout << sum << ' ' << n * n << endl;
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
