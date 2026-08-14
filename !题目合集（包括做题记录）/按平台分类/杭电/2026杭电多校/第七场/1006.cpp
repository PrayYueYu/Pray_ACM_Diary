#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, fl[N], fr[N];
std::vector<int> sl[N];
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
void init() {
	for(int i = 0; i <= n + 1; i++) {
		fl[i] = fr[i] = 0;
		sl[i].clear();
//		sr[i].clear();
	}
}
bool check(int l1, int r1, int l2, int r2) {
	if(r1 < l2 || r2 < l1) return false;
	return true;
}
std::pair<int, int> calc(int l1, int r1, int l2, int r2) {
	std::pair<int, int> ans;
	ans.first = std::max(l1, l2);
	ans.second = std::min(r1, r2);
	return ans;
}
void solve() {
	std::cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int l, r; std::cin >> l >> r;
		if(l > r) std::swap(l, r);
		sl[l].push_back(r);
	}
	for(int i = n; i >= 1; i--) {
		std::sort(sl[i].begin(), sl[i].end());
		if(!sl[i].size()) {
			fl[i] = fl[i + 1];
			fr[i] = fr[i + 1];
			continue;
		}
		if(!fl[i + 1]) {
			fl[i] = i + 1;
			fr[i] = sl[i][0];
		}
		else {
			if(fl[i + 1] == -1) {
				fl[i] = fr[i] = -1;
				continue;
			}
			int l = i + 1, r = sl[i][0];
			if(!check(l, r, fl[i + 1], fr[i + 1])) {
				fl[i] = fr[i] = -1;
			}
			std::pair<int, int> now = calc(l, r, fl[i + 1], fr[i + 1]);
			fl[i] = now.first; fr[i] = now.second;
		}
	}
	int maxr = 0, minr = INF;
	for(int i = 1; i < n; i++) {
		if(sl[i].size()) {
			maxr = std::max(maxr, sl[i][sl[i].size() - 1]);
			minr = std::min(minr, sl[i][0]);
		}
		if(minr <= i) continue;
		if(fl[i + 1] == -1) continue;
		if(!fl[i + 1]) {
			std::cout << "Yes\n";
			std::cout << i + 1 << ' ' << n << '\n';
			return;
		}
		if(fr[i + 1] >= maxr + 1) {
			std::cout << "Yes\n";
			std::cout << i + 1 << ' ' << fr[i + 1] << '\n';
			return; 
		}
	}
	std::cout << "No\n";
}
signed main() {
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
