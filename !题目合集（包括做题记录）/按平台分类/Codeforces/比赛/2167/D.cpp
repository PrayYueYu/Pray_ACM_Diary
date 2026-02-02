#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
int n, p[N], cnt;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
bool check(int x) {
	for(int i = 2; i <= sqrt(x); i++) {
		if(x % i == 0) return false;
	}
	return true;
}
void pre() {
	for(int i = 2; i <= 10000; i++) {
		if(check(i)) p[++cnt] = i;
	}
}
void solve() {
	n = read();
	int g = 0;
	for(int i = 1; i <= n; i++) {
		int x = read();
		g = __gcd(x, g);
	}
	for(int i = 1; i <= cnt; i++) {
		if(__gcd(p[i], g) == 1) {
			cout << p[i] << endl;
			return;
		}
	}
}
signed main() {
	pre();
	int T = read();
	while(T--) {
		solve();
	//	init();
	}
	return 0;
} 
