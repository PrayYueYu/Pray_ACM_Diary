#include<bits/stdc++.h>
#define ll long long
#define int long long 
using namespace std;
const int N = 3e5 + 200, INF = 2e18;
int n, a[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void solve() {
	n = read();
	a[1] = 4;
	a[2] = -1;
	if(n == 2) {
		cout << "1 -3 -3 1\n";
		return;
	}
	for(int i = 3; i <= 2 * n; i += 2) {
		a[i] = 2;
		a[i + 1] = -1;
	}
	a[2 * n] = -n;
	for(int i = 1; i <= 2 * n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
signed main() {
	int T = read();
	while(T--) {
		solve();
	}
    return 0;
}
