#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], vis[N], cnt[N];
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void solve() {
	std::vector<int> ans;
	n = read();
	for(int i = 1; i <= 2 * n; i++) a[i] = read();
	int f = false;
	for(int i = 1; i <= 2 * n; i++) {
		cnt[a[i]]++;
		if(!f && vis[a[i]] == false) {
			vis[a[i]] = true;
			continue;
		}
		if(!f && vis[a[i]] == true) {
			ans.push_back(i - 1);
			f ^= 1;
			continue;
		}
		if(f && vis[a[i]] == false && cnt[a[i]] == 1)
			continue;
		if(f && vis[a[i]] == true) continue;
		ans.push_back(i - 1);
		vis[a[i]] = true;
		f ^= 1;
	}
	std::cout << ans.size() << '\n';
	for(auto x: ans) std::cout << x << ' ';
	std::cout << '\n';
	for(int i = 1; i <= 2 * n; i++){
		vis[a[i]] = cnt[a[i]] = 0;
	}
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
