#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
int n, ans[N];
int read() {
	int x;
	cin >> x;
	return x;
}
signed main() {
	n = read();
	int l = 1, r = n, f1 = 1, f2 = 0;
	int a = 0, b = n + 1;
	while(true) {
		if(f1) ans[l] = ++a;
		else ans[l] = --b;
		l++;
		if(l > r) break;
		if(f2) ans[r] = ++a;
		else ans[r] = --b;
		f1 = 1 - f1, f2 = 1 - f2;
		r--;
		if(l > r) break;
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}
/*

*/
