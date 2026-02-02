#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100, M = 998244353, INF = 2e18;
int n, ans = 0, a[N]; 
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
map<int, bool> mp;
void merge(int x) {
	if(!mp[x]) {
		mp[x] = true;
		ans++;
	}
}
void solve() {
	n = read();
	ans = 0;
    merge(0);
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(i != 1) {
			int s = a[i] ^ a[i - 1];
			merge(s);
			s = a[i] & a[i - 1];
			merge(s);
			s = a[i] | a[i - 1];
			merge(s);
			s = (a[i] | a[i - 1]) ^ a[i];
			merge(s);
			s = (a[i] | a[i - 1]) ^ a[i - 1];
			merge(s);
			s = (a[i] ^ a[i - 1]) | a[i];
			merge(s);
			s = (a[i] ^ a[i - 1]) | a[i - 1];
			merge(s);
			s = (a[i] & a[i - 1]) ^ a[i];
			merge(s);
			s = (a[i] & a[i - 1]) ^ a[i - 1];
			merge(s);
		}
		merge(a[i]);
	}
	cout << ans << endl;
	mp.clear();
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
