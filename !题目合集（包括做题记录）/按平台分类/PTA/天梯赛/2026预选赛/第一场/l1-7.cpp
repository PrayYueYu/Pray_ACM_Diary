#include<bits/stdc++.h>
#define int long long
const int N = 1e5 + 10, mod = 998244353, INF = 1e18;
std::string s;
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
std::string Find(int x, int L) {
	std::string ans = "";
	for(int i = x; i <= L; i++) ans += s[i];
	return ans;
}
void solve() {
	n = read();
	std::cin >> s;
	for(int i = 1; i <= n; i++) {
		int op = read();
		std::string t = "";
		if(op == 1) {
			std::cin >> t;
			int szt = t.size();
			int f = -1;
			for(int j = 0; j < s.size(); j++) {
				if(j + szt - 1 >= s.size()) break;
				std::string now = Find(j, j + szt - 1);
				if(now == t) {
					f = j;
					break;
				}
			}
			std::cout << f << '\n';
		}
		else if(op == 2) {
			std::string x1 = "", x2 = "";
			std::cin >> x1 >> x2;
			for(int j = 0; j < s.size(); j++) {
				if(j + x1.size() - 1 >= s.size()) break;
				std::string now = Find(j, j + x1.size() - 1);
				if(now == x1) {
					std::string p1 = Find(0, j - 1);
					std::string p2 = Find(j + x1.size(), s.size() - 1);
					s = p1 + x2 + p2;
					break;
				}
			}
			std::cout << s << '\n';
		}
		else {
			char c1, c2;
			std::string news = "";
			std::cin >> c1 >> c2 >> t;
			for(int j = 0; j < s.size() - 1; j++) {
				if(s[j] == c1 && s[j + 1] == c2) {
					std::string x1 = Find(0, j), x2 = Find(j + 1, s.size() - 1);
					s = x1 + t + x2;
					j += t.size();
				}
			}
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

*/
