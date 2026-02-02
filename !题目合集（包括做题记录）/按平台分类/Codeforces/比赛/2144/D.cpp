#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 2e5 + 100, M = 998244353, INF = 1e16;	
int val[N], n, num[N], numx[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

signed main(){
	//freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		n = read(); int y = read();
		int Max = -INF;
		for(int i = 1; i <= n; i++) {
			int x = read();
			num[x]++;
			Max = max(Max, x);
		}
		for(int i = 1; i <= Max; i++) {
			numx[i] = num[i];
			num[i] += num[i - 1];
		}
		for(int i = 1; i <= N - 10; i++) {
			val[i] = -y * n;
		}
		for(int i = 1; i <= Max; i++) {
			for(int x = 2; x <= N - 10; x++) {
				int l = (i - 1) * x + 1;
				int r = min(i * x, Max);
				
				if(l > Max) break;
				int res = num[r] - num[l - 1];
				val[x] += i * res;
				val[x] += min(numx[i], res) * y;
				
			}
		}
		int ans = -INF;
		for(int i = 2; i <= N - 10; i++) 
			ans = max(ans, val[i]);
		cout << ans << endl;
		for(int i = 0; i <= Max; i++) {
			val[i] = num[i] = numx[i] = 0;
		}
	}
    return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
