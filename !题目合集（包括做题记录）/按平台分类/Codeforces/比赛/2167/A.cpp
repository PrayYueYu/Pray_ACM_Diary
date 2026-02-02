#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
int a, b, c, d;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}

void solve() {
	a = read(), b = read(), c = read(), d = read();
	if(a == b && b == c && c == d) {
		cout << "YES\n";
	}
	else cout << "NO\n";
}
signed main() {
	int T = read();
	while(T--) {
		solve();
	}
	return 0;
} 
