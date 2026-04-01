#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e7 + 2;
int ans, n, vis[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
bool check(int x) {
	int y = sqrt(x);
	if(y * y == x) return true;
	return false;
}
signed main() {
	n = read();
	for(int x = 1; x <= sqrt(n); x++) {
		int a = x * x;
		for(int y = 1; y <= sqrt(a); y++) {
			if(a % y != 0) continue;
			int i = a / y, j = y;
			if(i == j) ans++;
			else ans += 2;
		}
	}
	cout << ans;
	return 0;
} 
