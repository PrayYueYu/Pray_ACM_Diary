#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int n;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
set<int> s;
void solve() {
	n = read();
	s.clear();
	for(int i = 1; i <= sqrt(n); i++) {
		if(n % i == 0) {
			s.insert(i);
			s.insert(n / i);
		}
	}
	int las = 0, ans = 0;
	for(auto u: s) {
		if(las) ans += (u - las) * (n / las);
		las = u;
	}
	cout << ans + 1 << '\n';
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
