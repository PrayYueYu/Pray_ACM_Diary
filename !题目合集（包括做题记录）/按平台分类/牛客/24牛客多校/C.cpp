#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 100, INF = 2e18; 
int n, fa[N], cnt[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void merge(int x, int y) {
	int fax = getfa(x), fay = getfa(y);
	if(fax == fay) return; 
	cnt[fay] += cnt[fax];
	fa[fax] = fay;
}
void solve() {
    n = read();
    for(int i = 1; i <= n; i++) {
    	fa[i] = i;
    	cnt[i] = 1;
	}
    for(int i = 1; i <= n; i++) {
    	int x = read();
    	merge(i, x);
	}
	int ans = 0, cnt2 = 0;
	for(int i = 1; i <= n; i++) {
		int fai = getfa(i);
		if(i != fai) continue;
		if(cnt[i] == 3 || cnt[i] == 4) ans++;
		if(cnt[i] == 2) cnt2++;
		if(cnt[i] == 1) continue;
		if(cnt[i] >= 5) {
			while(true) {
				cnt[i] -= 3;
				ans++;
				if(cnt[i] == 4 || cnt[i] == 3) {
					ans++;
					break;
				}
				if(cnt[i] == 2) {
					cnt2++;
					break;
				}
			}
		} 
	}
	if(cnt2 & 1) ans += ((cnt2 + 1) / 2);
	else ans += cnt2 / 2;
	cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) solve();
    return 0;
}
/*

*/
