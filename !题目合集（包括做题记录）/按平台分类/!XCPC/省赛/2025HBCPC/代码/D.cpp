#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10, INF = 1e9 + 7, M = 998244353;
ll n, k, sum[N], a[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

ll check(ll x) {
	ll l = 1, sumx = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] != a[i - 1]) {
			if(a[i] - a[l] > x) {
				while(true) {
					l++;
					if(a[i] - a[l] <= x) break;
				}
			}
		}
		sumx += (i - l);
	}
	return sumx;
}

int main() {
//	freopen("1.in", "r", stdin);
	n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	ll l = 0, r = a[n] - a[1];
	while(l < r) {
		ll mid = (l + r) >> 1;
		if(check(mid) >= k) r = mid;
		else l = mid + 1;
	}
	ll del = l;
	while(true) {
		if(check(del) >= k) del--;
		else break;
	}
	ll ans = 0, sumx = check(del); l = 1;
	ans = (k - sumx) * (del + 1);
	for(int i = 1; i <= n; i++) {
		if(a[i] != a[i - 1]) {
			if(a[i] - a[l] > del) {
				while(true) {
					l++;
					if(a[i] - a[l] <= del) break;
				}
			}
		}
		ll num = i - l;
		ans += num * a[i] - (sum[i - 1] - sum[l - 1]);
	}
	cout << ans;
	return 0;
}
/*

*/
