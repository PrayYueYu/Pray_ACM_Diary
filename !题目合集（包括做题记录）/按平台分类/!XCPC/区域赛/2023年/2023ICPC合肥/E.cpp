#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 1e3 + 200, INF = 2e18;
int n, a[N][N], sum[N * N], m, num[N * N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
map<int, int> mp;
signed main() {
	n = read(), m = read();
	int cnt = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			a[i][j] = read();
			if(!mp[a[i][j]]) mp[a[i][j]] = ++cnt;
			a[i][j] = mp[a[i][j]];
			num[a[i][j]]++;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			ans += sum[a[i][j]] * i;
		}
		for(int j = 1; j <= m; j++) {
			sum[a[i][j]]++;
		}
		for(int j = 1; j <= m; j++) {
			ans -= (num[a[i][j]] - sum[a[i][j]]) * i;
		}
	}
	memset(sum, 0, sizeof(sum));
	for(int j = 1; j <= m; j++) {
		for(int i = 1; i <= n; i++) {
			ans += sum[a[i][j]] * j;
		}
		for(int i = 1; i <= n; i++) {
			sum[a[i][j]]++;
		}
		for(int i = 1; i <= n; i++) {
			ans -= (num[a[i][j]] - sum[a[i][j]]) * j;
		}
	}
	cout << ans * 2 << endl;
    return 0;
}
/*

*/
