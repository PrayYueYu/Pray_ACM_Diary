#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7;
int n, v[N], l[N], vx[N];
int suml[N], sumv[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

void solve() {
	n = read();
	for(int i = 1; i <= n; i++) vx[i] = read();
	for(int i = 1; i <= n; i++) l[i] = read();
	sort(vx + 1, vx + n + 1);
	for(int i = 1; i <= n; i++) v[i] = vx[n - i + 1];
	sort(l + 1, l + n + 1);
	for(int i = 1; i <= n; i++) sumv[i] = sumv[i - 1] + v[i];
	for(int i = 1; i <= n; i++) suml[i] = suml[i - 1] + l[i];
	int q = read();
	for(int i = 1; i <= q; i++) {
		int t = read();
		int L = 0, R = n;
		while(L < R) {
			int mid = (L + R + 1) >> 1;
			if(v[mid] - l[mid] * t < 0) R = mid - 1;
			else L = mid;
		}
		cout << sumv[L] - suml[L] * t << ' ';
	}
	cout << '\n';
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = read();
	while(T--) solve();
    return 0;
}
/*

*/
