#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 2e5 + 200, INF = 2e18;
int n, m, k, f[N][6], a[N], sum[N], Min[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
bool check(int Len) {
	for(int i = 0; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			f[i][j] = INF;
			Min[j] = INF;
		}
	}
	int ans = INF;
	//可以发现如果有k段连续的>=Len的，那么全部取刚好Len显然是最优解 
	for(int i = 1; i <= n; i++) {
		for(int j = k; j >= 1; j--) {
			if(j >= 2) {
				f[i][j] = f[i - 1][j];
				//当前位不选 
				if(i - Len >= 1 && !a[i - Len]) {
					f[i][j] = min(f[i][j], Min[j] + sum[i] - sum[i - Len]);
					//选择[i-Len+1,i]，那么必须保证a[i-Len]=0
					//更新需要前面min(f[x][j-1])，其中x<=i-Len-1 
				}
				if(i - Len >= 1 && !a[i - Len + 1]) 
					Min[j] = min(Min[j], f[i - Len][j - 1]);
				//为下一次选择更新Min 
			}
			else {
				f[i][j] = f[i - 1][j];
				//不选择 
				if(i >= Len) f[i][j] = min(f[i][j], sum[i] - sum[i - Len]);
				//第一段只需要选最小的即可，没有其他限制 
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		ans = min(ans, f[i][k]);
		//最小答案 
	}
	if(ans > m) return false;
	return true;
}
signed main() {
	//freopen("1.in", "r", stdin);
	n = read(), m = read(), k = read();
	string s;
	cin >> s;
	s = " " + s;
	for(int i = 1; i <= n; i++) {
		a[i] = s[i] - '0';
		sum[i] = sum[i - 1] + 1 - a[i];
	}
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	if(check(l)) cout << l;
	else cout << -1;
    return 0;
}
/*

*/
