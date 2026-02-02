#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
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
string s;
string check(int l, int r) {
	string ans = "";
	for(int i = l; i <= r; i++) ans += s[i];
	return ans;
}
void solve() {
	int n = read();
	std::cin >> s;
	int len = s.size();
	for(int i = 1; i <= n; i++) {
		int op = read();
		len = s.size();
		if(op == 1) {
			string s1;
			std::cin >> s1;
			int lx = s1.size(), ans = -1;
			for(int j = 0; j < len; j++) {
				if(j + lx - 1 >= len) break;
				if(check(j, j + lx - 1) == s1) {
					ans = j;
					break;
				}
			}
			std::cout << ans << '\n';
		}
		if(op == 2) {
			string s1, s2, nw = "";
			std::cin >> s1 >> s2;
			int lx = s1.size(), ans = -1;
			for(int j = 0; j < len; j++) {
				if(j + lx - 1 >= len) break;
//				std::cout << check(j, j + lx - 1) << '\n';
				if(check(j, j + lx - 1) == s1) {
					ans = j;
					break;
				}
			}
			if(ans != -1) {
				for(int j = 0; j < ans; j++) nw += s[j];
				nw += s2;
				for(int j = ans + lx; j < len; j++) nw += s[j];
				s = nw;
			}
			std::cout << s << '\n';
		}
		if(op == 3) {
			char c1, c2;
			string s1, nw = "";
			std::cin >> c1 >> c2 >> s1;
			int lx = s1.size();
			for(int j = 0; j < len; j++) {
				nw += s[j];
				if(j == len - 1) break;
				if(s[j] == c1 && s[j + 1] == c2) {
					nw += s1;
				}
			}
			s = nw;
			std::cout << s << '\n';
		}
	}
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
