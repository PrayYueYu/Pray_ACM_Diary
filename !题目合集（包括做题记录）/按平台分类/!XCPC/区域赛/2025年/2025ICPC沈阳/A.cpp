#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5, INF = 4e18;
int n, k, a, b;
int read() {
	int x;
	cin >> x;
	return x;
}
bool check(int mid) {
	int sum = 0;
	for(int x = 1; x <= 2000000; x++) {
		int c = mid / x;
		c = c - (a * x + 2 * b);
		c = c / (2 * a);
		c = min(c, max(n - x, 0ll));
		sum += c;
		if(!c) break;
		if(sum >= k) return false;
	}
	if(sum >= k) return false;
	return true;
}
signed main() {
	n = read(), k = read();
	a = read(), b = read();
	int l = 3 * a + 2 * b - 1, r = 7e18;
	while(l < r) {
		__int128 lx = l, rx = r + 1;
		__int128 mid = (lx + rx) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	l++;
	int g = __gcd(l, a);
	cout << l / g << ' ' << a / g;
	return 0;
}
