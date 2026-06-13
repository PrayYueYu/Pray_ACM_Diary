#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n;
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
int ask(int l, int r) {
	if(l > r) return 0;
	std::cout << "xor " << l << ' ' << r << std::endl;
	int x; std::cin >> x;
	return x;
}
int ALL, BC, C, A;
void solve() {
	std::cin >> n;
	ALL = ask(1, n);
	if(!ALL) {
		int id = 0;
		for(int i = 62; i >= 0; i--) {
			int t = (1ll << i);
			if(t > n) continue;
			int x = ask(t, n);
			if(x) {
				A = x;
				id = (1ll << i);
				break;
			}
		}
		int l = id, r = n;
		while(l < r) {
			int mid = (l + r) >> 1;;
			if(ask(mid, n) == A) l = mid + 1;
			else r = mid;
		}
		C = ask(l, n);
		std::cout << "ans " << A << ' ' << (A ^ C) << ' ' << C << std::endl;
		return;
	}
	int l = 2, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(ask(mid, n) == ALL) l = mid + 1;
		else r = mid;
	}
	BC = ask(l, n);
	l++, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(ask(mid, n) == BC) l = mid + 1;
		else r = mid;
	}
	C = ask(l, n);
	std::cout << "ans " << (ALL ^ BC) << ' ' << (BC ^ C) << ' ' << C << std::endl;
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T; std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
