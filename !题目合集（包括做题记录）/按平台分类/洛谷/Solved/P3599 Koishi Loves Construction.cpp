#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 100;
int n, a[N], X, M;
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
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % M;
		x = (x * x) % M;
		y >>= 1;
	}
	return ans;
}
void solve() {
	n = read();
	if(X == 1) {
		if(n == 1) {
			cout << "2 1" << '\n';
			return;
		}
		if(n & 1) cout << 0 << '\n';
		else {
			cout << 2 << " " << n << " ";
			for(int i = 1; i <= n - 1; i++) {
				if(i & 1) cout << i << " ";
				else cout << n - i << " ";
			}
			cout << '\n';
		}
		return;
	}
	else {
		if(n == 4) {
			cout << "2 1 3 2 4\n";
			return;
		}
		int x = n;
		for(int i = 1; i <= n - 1; i++) {
			int g = __gcd(i, x);
			x /= g;
		}
		if(x != n) {
			cout << 0 << '\n';
			return;
		}
		M = n;
		a[1] = 1;
		int Pi = 1;
		for(int i = 2; i <= n; i++) {
			int now = i * ksm(Pi, M - 2);
			a[i] = now % M;
			Pi = (Pi * now) % M;
		}
		cout << "2 ";
		for(int i = 1; i <= n; i++) {
			if(!a[i]) a[i] = n;
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
}
signed main() {
	X = read();
	int T = read();
	while(T--) {
		solve();
	}
	return 0;
}
