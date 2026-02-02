#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e9 + 10;

int read() {
	int x;
	scanf("%lld", &x);
	return x;
}

void solve() {
	int x = read(), y = read(), z = read();
	int a = 0, b = 0, c = 0;
	for(int i = 33; i >= 0; i--) {
		if((x >> i & 1)) {
			if(!(a >> i & 1)) a += (1ll << i);
			if(!(b >> i & 1)) b += (1ll << i);
		}
		if((y >> i & 1)) {
			if(!(c >> i & 1)) c += (1ll << i);
			if(!(b >> i & 1)) b += (1ll << i);
		}
		if((z >> i & 1)) {
			if(!(c >> i & 1)) c += (1ll << i);
			if(!(a >> i & 1)) a += (1ll << i);
		}
	}
	if((a & b) == x && (b & c) == y && (a & c) == z) {
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
/*

*/
