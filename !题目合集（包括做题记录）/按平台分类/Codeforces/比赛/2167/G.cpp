#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 8e3 + 100, INF = 1e18;
int f[N], a[N], b[N], n, sum[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void init() {
	for(int i = 1; i <= n; i++) {
		f[i] = INF;
	}
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		f[i] = INF;
	}
	for(int i = 1; i <= n; i++) {
		b[i] = read();
		sum[i] = sum[i - 1] + b[i];
	}
	f[n + 1] = INF; 
	a[n + 1] = INF;
	b[n + 1] = 0;
	a[0] = -INF;
	b[0] = 0;
	//多一个首尾即可覆盖全区间 
	for(int i = 1; i <= n + 1; i++) {
		//if(i != 1) f[i] = min(f[i], f[i - 1] + b[i]);
		for(int j = 0; j < i; j++) {
			if(a[i] >= a[j])
				f[i] = min(f[i], f[j] + sum[i - 1] - sum[j]);
			//f[j] = min(f[j], )
		}
	}
	cout << f[n + 1] << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		//init();
	}
	return 0;
} 
/*
1
3
3 1 2
100 1 1
*/
