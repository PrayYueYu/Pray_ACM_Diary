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
signed main() {
    int T = read();
    while(T--) {
    	n = read();
    	int now = 0;
    	for(int i = 1; i <= n; i++) {
    		f[i] = read();
    		if(i == 1) {
    			a[i] = 1;
    			now++;
    			continue;
			}
			f[i]--;
			if(f[i] == f[i - 1]) a[i] = a[i - 1];
			else if(f[i] == f[i - 1] + i - 1) a[i] = ++now;
			else {
				a[i] = a[i - 1 - (f[i] - f[i - 1])];
			}
			f[i]++;
		}
		for(int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << endl;
	}
    return 0;
}
/*

*/
