#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 100, INF = 2e18; 
int n, m, a[N], ans[N], num[N], b[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
int check(int mid) {
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		if(b[i] >= a[i]) {
			if(mid % b[i] == 0) sum += mid / b[i];
			else sum += mid / b[i] + 1;
		}
		else {
			if(a[i] * m >= mid) {
				if(mid % a[i] == 0) sum += mid / a[i];
				else sum += mid / a[i] + 1;
			}
			else {
				int now = mid - a[i] * m;
				sum += m;
				if(now % b[i] == 0) sum += now / b[i];
				else sum += now / b[i] + 1;
			}
		}
	}
	if(sum <= n * m) return true;
	return false;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		num[i] = 0;
		a[i] = read();
	}
	for(int i = 1; i <= n; i++) {
		b[i] = read();
		//q.push({0, i});
		//ans[i] = 0;
	}
	int l = 1, r = 1e18;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	} 
	cout << l;
}
signed main() {
	int T = 1;
	while(T--) solve(); 
    return 0;
}
/*
1152921504606846975
*/
