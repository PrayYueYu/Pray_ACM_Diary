#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 100;
int n;
std::string s;
std::string gets(int l, int r) {
	std::string ans = "";
	if(l > r) return ans;
	for(int i = l; i <= r; i++) {
		ans += s[i];
	}
	return ans;
}
void solve() {
	std::cin >> n;
	std::cin >> s;
	for(int i = 1; i <= n; i++) {
		int op; std::cin >> op;
		if(op == 1) {
			std::string s1;
			std::cin >> s1;
			int len = s1.size(), f = false;
			for(int j = 0; j < s.size(); j++) {
				if(j + len - 1 >= s.size()) break;
				if(gets(j, j + len - 1) == s1) {
					std::cout << j << '\n';
					f = true;
					break;
				}
			}
			if(!f) std::cout << -1 << '\n';
		}
		else if(op == 2) {
			std::string s2, s3, ans = "";
			std::cin >> s2 >> s3;
			int len = s2.size(), f = false;
			for(int j = 0; j < s.size(); j++) {
				if(j + len - 1 >= s.size()) break;
				if(gets(j, j + len - 1) == s2) {
					ans = gets(0, j - 1) + s3 + gets(j + len, s.size() - 1);
					f = true;
					break;
				}
			}
			if(f) s = ans;
			std::cout << s << '\n';
		}
		else {
			std::string ans = "", s4;
			char c1, c2;
			std::cin >> c1 >> c2 >> s4;
			for(int j = 0; j < s.size() - 1; j++) {
				ans += s[j];
				if(s[j] == c1 && s[j + 1] == c2) {
					ans += s4;
				}
			}
			ans += s[s.size() - 1];
			s = ans;
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
