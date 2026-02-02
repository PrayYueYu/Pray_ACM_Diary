#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int a[N], n;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
signed main() {
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	int sc = 0;
	for(int i = 1; i <= n; i++) {
		if(sc >= a[i]) sc++;
		else sc--;
	}
	cout << sc << " "; sc = 0;
	for(int i = n; i >= 1; i--) {
		if(sc >= a[i]) sc++;
		else sc--;
	}
	cout << sc;
	return 0;
}
