#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int n, m, bs[N][24];
//std::bitset<30> bs[N], ck;
void solve() {
	std::cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		for(int j = 1; j <= m; j++) {
			if(s[j - 1] == 'Y') bs[i][j] = 1;
			else bs[i][j] = 0;
		}
	}
//	for(int i = 1; i <= m; i++) ck[i] = 1;
	int maxn = -1, ansx = 0, ansy = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int flag = true, cnt = 0;
			for(int k = 1; k <= m; k++) {
				if((bs[i][k] | bs[j][k]) == 0) {
					flag = false;
					break;
				}
				if(bs[i][k] && bs[j][k]) cnt++;
			}
			if(!flag) continue;
			if(maxn < cnt) {
				maxn = cnt;
				ansx = i;
				ansy = j;
			}
		}
	}
	if(maxn == -1) std::cout << "No";
	else std::cout << ansx << ' ' << ansy << '\n';
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
