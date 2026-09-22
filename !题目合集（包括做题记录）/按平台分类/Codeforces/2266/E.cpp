#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;

int a[N], vis[N], p[N], num;
int f[N], r[N];
void pre() {
	int maxn = 200000;
    num = 0;
    for(int i = 2; i <= maxn; i++) {
	    if(!vis[i]) {
	        p[++num] = i;
	        vis[i] = i;
	        for(int j = 2; j <= maxn; j++) {
	            if(i * j > maxn) break;
	            vis[i * j] = std::max(vis[i * j], i);
	        }
	    }
	}
	for(int i = 2; i <= 200000; i++) {
		r[i] = r[i / vis[i]] + i / vis[i];
	}
}

void solve() {
	int n, k;
	std::cin >> n >> k;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int x = 0;
		std::cin >> x;
		if(x <= k) continue;
		int minn = INF;
		for(int j = 1; j <= sqrt(x); j++) {
			if(x % j == 0) {
				int s1 = j, s2 = x / j;
				if(s1 <= k) minn = std::min(minn, r[s2]);
				if(s2 <= k) minn = std::min(minn, r[s1]);
			}
		}
//		std::cout << minn << '\n';
		ans += minn;
	}
	std::cout << ans << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	pre();
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
