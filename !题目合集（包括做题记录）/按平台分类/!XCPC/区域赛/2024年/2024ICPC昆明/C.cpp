#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 1000;
int k, n, L[N], R[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
int calc(int x, int y) {
	if(x % y == 0) return x / y;
	return x / y + 1;
}
int calc2(int l, int d) {
	int lx = 0, rx = 1000000000000;
	while(lx < rx) {
		int mid = (lx + rx + 1) >> 1;
		if(l + mid * d <= n) lx = mid;
		else rx = mid - 1;
	}
	return l + lx * d;
}
signed main() {
	//freopen("M.in","r",stdin);
	int T = read();
	while(T--) {
		n = read(), k = read();
		if(n < k + 1) {
			cout << n << endl;
			continue;
		}
		if(k <= sqrt(n) || k <= 100000) {
			int now = k;
			while(true) {
				int ne = calc(now * k, k - 1);
				if(now <= n && n < ne) {
					cout << now << endl;
					break;
				}
				now = ne;
			}
			continue;
		}
		
		int d = 1, lasl = k - 1;
		for(int i = 2; i <= 1000000; i++) {
			int l = lasl + i - 1;
			int r = i * k - i;
			int dx = r - l;
			if(dx % i != 0) {
				int x = dx % i;
				r -= x;
			}
			L[i] = l;
			R[i] = r;
			if(L[i] <= n && n <= R[i] + i - 1) {
				cout << calc2(L[i], i) << '\n';
				break;
			}
			lasl = r;
		}
	}
	return 0;
}
/*

*/
