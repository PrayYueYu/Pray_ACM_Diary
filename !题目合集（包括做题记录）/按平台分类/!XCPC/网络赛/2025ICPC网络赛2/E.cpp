#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const ll N = 1e2 + 10, M = 998244353;
int n, m;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int ksm(int x, int y) {
	int ans = 1ll;
	//x = (x + M) % M;
	while(y) {
		if(y & 1) ans = (ans * x) % M;
		y >>= 1;
		x = (x * x) % M;
	}
	return ans;
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
    int T = read();
    while(T--) {
    	n = read(), m = read();
    	if(n == 1) {
    		cout << 1 << endl;
    		continue;
		}
		if(n == 2) {
			cout << 0 << endl;
			continue;
		}
		int q = ksm(2, m) - 1 + M; q %= M;
    	if(!(n & 1)) {
    		int s1 = 0;
    		int s2 = 0;
    		
    		if((n / 2) & 1) s1 = M - ksm(q, n / 2);
    		else s1 = ksm(q, n / 2);
    		
    		if(((n / 2) - 1) & 1) s2 = M - ksm(q, n / 2 - 1ll);
    		else s2 = ksm(q, n / 2 - 1);
    		//cout << s2 << " " << s1 << endl;
    		s2 = (1ll - s2 + M) % M;
    		int ans = ((s1 * s2) % M + M) % M;
			cout << ans << endl;
		}
		else {
			int ans = ksm(q, n - 1);
			cout << ans << endl;
		}
	}
    return 0;
}
/*
5
1 3
2 3
3 3
4 3
5 3

*/
