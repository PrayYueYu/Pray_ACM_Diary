#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n, m, num[N];
int read() {
	int x;
	cin >> x;
	return x;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int x = read();
			num[x]++;
		}
	}
	int f = true;
	for(int i = 1; i <= n; i++) {
		if(num[i] != m) f = false;
		num[i] = 0;
	}
	if(!f) cout << "Yes\n";
	else cout << "No\n";
}
signed main() {
    int T = read();
    while(T--) solve();
    return 0;
}
/*

*/
