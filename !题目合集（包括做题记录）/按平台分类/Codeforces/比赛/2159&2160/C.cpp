#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 3e6 + 200, INF = 1e9;
int n, a[N], f[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int calc(int x) {
	int ans = 0;
	while(true) {
		ans++;
		x /= 2;
		if(!x) break;
	}
	return ans - 1;
}
signed main() {
    int T = read();
    while(T--) {
    	n = read();
    	if(!n) {
    		cout << "YES\n";
    		continue;
		}
    	int f = false;
    	int p = calc(n);
    	for(int i = 0; i <= 62; i++) {
    		a[i] = (n >> i) & 1;
		}
		for(int i = p; i <= 62; i++) {
			int fx = true;
			for(int j = 0; j <= i; j++) {
				if(j == i - j) {
					if(a[j]) {
						fx = false;
						break;
					}
					continue;
				}
				if(a[j] != a[i - j]) {
					fx = false;
					break;
				}
			}
			if(fx) {
				f = true;
				//cout << i << endl; 
			}
		}
		if(f) cout << "YES\n";
		else cout << "NO\n";
	}
    return 0;
}
/*

*/
