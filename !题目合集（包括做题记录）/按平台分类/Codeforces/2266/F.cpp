#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, p[100], ne[N];
struct S {
	int x, y;
} s[N];
bool cmp(S x, S y) {
	return x.x < y.x;
}
bool checkx(int x, int y) {
	if(!x || !y) return true;
	return x <= (1000000000000000000 / y);
}
bool check(int mid) {
	int val = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i].x == mid) return true;
		ne[i] = 0;
	}
	for(int i = n; i >= 1; i--) {
		if(s[i].x > mid) {
			val += s[i].y;
			continue;
		}
		else {
			if(i == n || s[i + 1].x > mid) {
				if(mid - s[i].x >= 55) return false;
				ne[i] = p[mid - s[i].x - 1];
			}
			else {
				if(s[i + 1].x - s[i].x >= 55) return false;
				int t = ne[i + 1] + std::max(0ll, ne[i + 1] - s[i + 1].y);
				if(!checkx(t, p[s[i + 1].x - s[i].x - 1])) return false;
				ne[i] = t * p[s[i + 1].x - s[i].x - 1];
			}
			val += std::max(0ll, s[i].y - ne[i]);
		}
	}
	if(!s[1].x) {
		if(ne[1] > s[1].y + val) return false;
		return true;
	}
	int t = ne[1] + std::max(0ll, ne[1] - s[1].y);
	if(s[1].x >= 55) return false;
	if(t > (val / p[s[1].x - 1] + 100)) return false;
	if(t <= val / p[s[1].x - 1]) return true;
	return false;
	
}
void solve() {
	std::cin >> n;
	int maxn = 0;
	for(int i = 1; i <= n; i++) {
		std::cin >> s[i].x >> s[i].y;
		maxn = std::max(maxn, s[i].x);
	}
	std::sort(s + 1, s + n + 1, cmp);
	int l = 0, r = 2000000000;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	std::cout << std::max(maxn, l)  << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	p[0] = 1;
	for(int i = 1; i <= 60; i++) {
		p[i] = p[i - 1] * 2ll;
	}
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
