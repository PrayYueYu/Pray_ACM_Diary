#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10;
int n, k, st;
struct S {
	int a, b;
} s[N];
bool cmp(S x, S y) {
	return x.a < y.a;
}
void solve() {
	std::cin >> n >> k >> st;
	for(int i = 1; i <= n; i++) {
		std::cin >> s[i].a >> s[i].b;
	}
	std::sort(s + 1, s + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		if(st >= s[i].a) {
			st += s[i].b;
		}
		else {
			while(true) {
				if(!k || st >= s[i].a) {
					break;
				}
				else {
					st *= 2ll;
					k--;
				}
			}
			if(st >= s[i].a) st += s[i].b;
			else break;
		}
	}
	while(true) {
		if(k) {
			st *= 2ll;
			k--;
		}
		else break;
	}
	std::cout << st << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1;
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
