#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 100, INF = 2e18; 
int n, m, las[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
struct P {
	int u, v;
} s[N];
bool cmp(P x, P y) {
	if(x.v == y.v) return x.u > y.u;
	return x.v < y.v;
}
void solve() {
    n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		las[i] = i;
	}
    for(int i = 1; i <= m; i++) {
    	s[i].u = read(), s[i].v = read();
    	if(s[i].u > s[i].v) swap(s[i].u, s[i].v);
	}
	sort(s + 1, s + m + 1, cmp);
	for(int i = 1; i <= m; i++) {
		if(s[i].u == las[s[i].v] - 1) {
			las[s[i].v]--;
		}
	}
	int r = 1, ans = 0;
	for(int i = 1; i <= n; i++) {
		r = max(r, i);
		while(true) {
			if(r == n) break;
			if(las[r + 1] <= i) r++;
			else break;
		}
		ans += r - i + 1;
	}
	cout << ans << '\n';
	
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
	}
    return 0;
}
/*

*/
