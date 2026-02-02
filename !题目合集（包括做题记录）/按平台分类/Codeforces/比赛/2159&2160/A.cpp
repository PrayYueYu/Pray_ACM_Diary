#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 3e6 + 200, INF = 1e9;
int n, a[N], cnt[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
signed main() {
    int T = read();
    while(T--) {
    	n = read();
    	for(int i = 1; i <= n; i++) {
    		a[i] = read();
    		cnt[a[i]]++;
		}
		int ans = 0, num = 0;
		for(int i = 0; i <= 101; i++) {
			if(!cnt[i]) {
				ans = i;
				break;
			}
			else {
				num = min(num, cnt[i]);
			}
		}
		for(int i = 0; i <= 101; i++) cnt[i] = 0; 
		cout << ans << endl;
	}
    return 0;
}
/*

*/
