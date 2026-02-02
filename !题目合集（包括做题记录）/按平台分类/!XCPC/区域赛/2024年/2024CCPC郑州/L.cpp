#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100;
int d[N], Max, n;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void solve() {
	int l = read(), r = read();
	for(int i = 63; i >= 0; i--) {
		int s1 = (l >> i & 1);
		int s2 = (r >> i & 1);
		if(s1 == s2) {
			
			if(s1) l -= (1ll << i);
		}
		else break;
	}
	cout << l << '\n';
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
