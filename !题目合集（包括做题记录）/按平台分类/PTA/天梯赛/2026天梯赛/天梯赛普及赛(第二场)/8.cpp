#include<bits/stdc++.h>
#define rex register
const int N = 1e4 + 100;
int a[N], vis[N], b[N], re[N];
std::string mp[N];
std::string gets(int x) {
	std::string ans = "";
	for(int i = x; i <= x + 2; i++) {
		ans += (char)a[i];
	}
	return ans;
}
std::map<int, int> mpx;
std::vector<int> v;
void init() {
	v.clear();
	mpx.clear();
}
inline void solve() {
	int n = 0;
	while(true) {
		int x ; scanf("%d", &x);
		if(x == -1) break;
		a[++n] = x;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		int g = mpx[a[i]];
		if(!g) {
			mpx[a[i]] = ++cnt;
			re[cnt] = a[i];
			g = cnt;
		}
		a[i] = g;
	}
	for(rex int i = 1; i <= n - 2; i++) {
		std::string s = gets(i);
		if(mp[a[i]] == "") {
			mp[a[i]] = s;
		}
		else {
			if(mp[a[i]] == s) {
				if(!vis[a[i]]) {
					v.push_back(a[i]);
					vis[a[i]] = 1;
				}
			}
			else {
				vis[a[i]] = -1;
			}
		}
	}
	for(rex int i = n - 1; i <= n; i++) vis[a[i]] = -1;
	int ans = 0;
	for(rex auto x: v) {
		if(vis[x] == 1) {
			ans = x;
			break;
		}
	}
	for(rex int i = 0; i <= cnt + 2; i++) {
		vis[i] = 0;
		mp[i] = "";
	}
	if(!ans) {
		printf("NONE\n");
	}
	else {
		for(rex int i = 1; i <= n; i++) {
			if(ans == a[i]) {
				printf("%d %d %d\n", re[a[i]], re[a[i + 1]], re[a[i + 2]]);
				return;
			}
		}
	}
}
signed main() {
	int T; std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
} 
