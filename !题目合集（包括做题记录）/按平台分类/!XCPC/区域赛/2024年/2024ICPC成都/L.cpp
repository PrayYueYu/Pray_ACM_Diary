#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void solve() {
	int a = read(), b = read(), c = read();
	cout << 100 << endl;
	n = 100;
	int mid1 = 50, mid2 = 45, mid3 = 4;
	for(int i = 1; i <= n; i++) {
		if(mid1) {
			cout << a << " ";
			mid1--;
		}
		else if(mid2) {
			cout << b << " ";
			mid2--;
		}
		else if(mid3) {
			cout << c << " ";
			mid3--;
		}
		else cout << c + 1;
	}
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
