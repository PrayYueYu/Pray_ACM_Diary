#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int p[100], n, k, x;
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
	int x = read(), k = read();
	std::vector<int> ans;
	while(true) {
		if(!k) break;
		for(int i = 1; i <= x; i++) {
			if(x - i > 60) {
				ans.push_back(i);
				x--;
				k--;
				break;
			}
			else {
				if(k > p[x - i]) {
					k -= p[x - i];
				}
				else {
					ans.push_back(i);
					x -= i;
					k--;
					break;
				}
			}
		}
		
	}
	for(auto s: ans) std::cout << s << ' ';
	std::cout << '\n';
}
signed main() {
	p[0] = 1;
	for(int i = 1; i <= 61; i++) p[i] = p[i - 1] * 2;
	int T = read();
 	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
