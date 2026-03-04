#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
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
struct S {
	std::string t1, t2;
} s[N];
bool cmp(S x, S y) {
	return x.t1 < y.t1;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		char c;
		std::cin >> s[i].t1 >> c >> s[i].t2;
	}
	std::sort(s + 1, s + n + 1, cmp);
	std::string las = "00:00:00";
	std::string end = "23:59:59";
	for(int i = 1; i <= n; i++) {
		if(s[i].t1 != las) {
			std::cout << las << " - " << s[i].t1 << '\n';
		}
		las = s[i].t2;
	}
	if(las != end) std::cout << las << " - " << end;
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
8
13:00:00 - 18:00:00
00:00:00 - 01:00:05
08:00:00 - 09:00:00
07:10:59 - 08:00:00
01:00:05 - 04:30:00
06:30:00 - 07:10:58
05:30:00 - 06:30:00
18:00:00 - 19:00:00
*/
