#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e16; 
int a[N], sum1[N], sum2[N];
string s;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int calc(vector<int> &v, int nx) {
	int n = v.size() - 1;
	for(int i = 0; i <= n; i++) {
		sum1[i] = sum1[i - 1] + v[i] - (i + 1);
	}
	int now = nx;
	sum2[n + 1] = 0;
	for(int i = n; i >= 0; i--) {
		sum2[i] = sum2[i + 1] + nx - v[i];
		nx--;
	}
	int ans = INF;
	for(int i = 0; i <= n; i++) {
		ans = min(ans, sum1[i] + sum2[i + 1]);
	}
//	cout << sum1[n] << " " << sum2[0] << endl;
	ans = min(ans, sum1[n]);
	ans = min(ans, sum2[0]);
	return ans;
}
void solve() {
	int n = read();
	cin >> s;
	s = " " + s;
	int ans = INF;
	vector<int> v1, v2;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'a') v1.push_back(i);
		else v2.push_back(i);
	}
	ans = min(ans, calc(v1, n));
	ans = min(ans, calc(v2, n));
	cout << ans << endl;
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		solve();
		//init();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*


*/
