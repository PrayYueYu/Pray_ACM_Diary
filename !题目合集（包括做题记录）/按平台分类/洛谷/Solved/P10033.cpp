#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e6 + 9;
int a[N], ans[N], sum1[N], sum2[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void print(int n) {
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';
}
void solve() {
	int n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		ans[i] = n;
	}
	if(n == 2 || n == 3) {
		if(n == 3) {
			if(a[1] == 1 && a[2] == 2 && a[3] == 3) {
				printf("3 1 1\n");
			}
			if(a[1] == 1 && a[2] == 3 && a[3] == 2) {
				printf("2 1 1\n");
			}
			if(a[1] == 2 && a[2] == 1 && a[3] == 3) {
				printf("3 3 2\n");
			}
			if(a[1] == 2 && a[2] == 3 && a[3] == 1) {
				printf("1 1 2\n");
			}
			if(a[1] == 3 && a[2] == 1 && a[3] == 2) {
				printf("2 3 3\n");
			}
			if(a[1] == 3 && a[2] == 2 && a[3] == 1) {
				printf("1 1 3\n");
			}
			return;
		}
		cout << -1 << endl;
		return;
	}
	if(a[1] == n || a[n] == n) {
		if(a[1] == n && a[2] == n - 1) {
			ans[1] = n - 2;
			print(n);
			return;
		}
		if(a[n] == n && a[n - 1] == n - 1) {
			ans[n] = n - 2;
			print(n);
			return;
		}
		if(a[1] == n) ans[1] = n - 1;
		else ans[n] = n - 1;
		print(n);
		return;
	}
	int t = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == n) t = i;
	}
	if(a[t - 1] == n - 1 || a[t + 1] == n - 1) {
		if(a[t - 1] == n - 1 && a[t + 1] == n - 2) {
			ans[t] = n - 3;
			ans[t + 1] = n - 1;
			print(n);
			return;
		}
		if(a[t + 1] == n - 1 && a[t - 1] == n - 2) {
			ans[t] = n - 3;
			ans[t - 1] = n - 1;
			print(n);
			return;
		}
		ans[t] = n - 2;
		print(n);
		return;
	}
	ans[t] = n - 1;
	print(n);
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = read();
	while(T--) solve();
    return 0;
}
