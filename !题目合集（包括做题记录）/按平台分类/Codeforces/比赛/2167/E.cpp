#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
int a[N], n, k, x;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
bool check(int mid) {
	int num = 0, now = 0, id = 1;
	a[n + 1] = x;
	for(int i = 1; i <= n + 1; i++) {
		int l = a[i - 1] + mid, r = a[i] - mid;
		if(i == 1) l = 0;
		if(i == n + 1) r = x;
		if(r >= l) num += r - l + 1;
	}
	if(num >= k) return true;
	return false;
}
void solve() {
	n = read();
	k = read();
	x = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	int l = 0, r = x;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
//	cout << l << endl;
	a[n + 1] = x;
	int num = 0, las = -1;
	for(int i = 1; i <= n + 1; i++) {
		int L = a[i - 1] + l, R = a[i] - l;
		if(i == 1) L = 0;
		if(i == n + 1) R = x;
		for(int j = L; j <= R; j++) {
			if(las == j) continue;
			las = j;
			cout << j << " ";
			num++;
			if(num == k) break;
		}
		if(num == k) break;
	}
	
	cout << endl;
}
signed main() {
	int T = read();
	while(T--) {
		solve();
	//	init();
	}
	return 0;
} 
