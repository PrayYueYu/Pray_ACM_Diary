#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 100, INF = 1e16;
int a[N], b[N], n;
int sum[3][N], s[N];
int read() {
	int x;
	cin >> x;
	return x;
}
bool check(int mid) {
	int num = 0, Max = 0;
	for(int i = 1; i <= n; i++) {
		sum[1][i] = sum[1][i - 1];
		sum[2][i] = sum[2][i - 1];
		if(a[i] >= mid) sum[1][i]++;
		if(b[i] >= mid) sum[2][i]++;
		s[i] = sum[2][i] - sum[1][i];
	}
	int all = sum[1][n], Min = 0;
	for(int i = 1; i <= n; i++) {
		Max = max(Max, s[i] - Min);
		Min = min(Min, s[i]);
	}
	num = Max + all;
	if(num >= (n + 1) / 2) return true;
	return false; 
}
signed main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		b[i] = read();
	}
	int l = 1, r = 1e9;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
} 
