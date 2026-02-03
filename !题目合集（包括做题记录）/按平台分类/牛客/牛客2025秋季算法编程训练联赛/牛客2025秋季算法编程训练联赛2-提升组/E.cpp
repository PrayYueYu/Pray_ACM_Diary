#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100, INF = 1e18;
int n, a[N], num[40][3];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
map<int, bool> mp;
signed main() {
	n = read();
	int sum = n - 1;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(mp[a[i]]) {
			sum--;
		}
		else mp[a[i]] = true;
		for(int j = 0; j <= 31; j++) {
			int ff = (a[i] >> j & 1);
			num[j][ff]++;
		}
	}
	for(int i = 0; i <= 31; i++) {
		if(num[i][0] && num[i][1]) {
			cout << sum * (1ll << i);
			return 0;
		}
	}
	cout << 0;
	return 0;
} 
