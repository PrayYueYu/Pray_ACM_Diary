#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
std::string s, a[2000], re[10];
int n, cnt, num[2000];
std::vector<std::string> v[N], vx;
std::vector<std::string> calc(std::string t) {
	std::vector<std::string> ans;
	for(int i = 0; i <= 3; i++) {
		int f = false;
		std::string p = "";
		for(int j = 0; j < t.size() - 1; j++) {
			p = t[j]; p += t[j + 1];
			if(p == re[i]) {
				f = true;
				break;
			}
		}
		if(f) ans.push_back(re[i]);
	}
	return ans;
}
void dfs(int x, int t, std::string now) {
	if(x == t + 1) {
		a[++cnt] = now;
		num[cnt] = a[cnt].size();
		v[cnt] = calc(a[cnt]);
		return;
	}
	dfs(x + 1, t, now + "0");
	dfs(x + 1, t, now + "1");
}
bool check(int x) {
	if(v[x].size() != vx.size()) return false;
	for(int i = 0; i < v[x].size(); i++) {
		if(vx[i] != v[x][i]) return false;
	}
	return true;
}
void solve() {
	std::cin >> s;
	vx = calc(s);
	n = s.size();
	int ans = 0;
	for(int i = 1; i <= cnt; i++) {
		int f = false, now = 0;
		for(int j = 0; j < n; j++) {
			if(s[j] == a[i][now]) {
				now++;
				if(now == num[i]) {
					f = true;
					break;
				}
			}
		}
		if(f && check(i)) {
			ans = num[i];
			break;
		}
	}
	if(!ans) ans = 6;
	std::cout << ans << '\n';
}
signed main() {
	re[0] = "00";
	re[1] = "01";
	re[2] = "10";
	re[3] = "11";
	for(int i = 1; i <= 5; i++) dfs(1, i, "");
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
