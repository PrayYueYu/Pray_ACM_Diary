#include<bits/stdc++.h>
#define int long long
const int N = 1e5 + 10, mod = 998244353, INF = 1e18;
int n, m;
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
std::map<std::string, char> mp;
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		std::string s = "";
		std::cin >> s;
		char c; std::cin >> c;
		mp[s] = c;
	}
	for(int i = 1; i <= m; i++) {
		std::string s = "";
		std::cin >> s;
		if(mp[s]) {
			std::cout << mp[s] << '\n';
			continue;
		}
		std::string s1 = "", s2 = "";
		int ans_cnt = 0;
		char ans1, ans2;
		for(int j = 0; j < s.size() - 1; j++) {
			s1 += s[j];
			s2 = "";
			for(int k = j + 1; k < s.size(); k++) s2 += s[k];
			if(mp[s1] && mp[s2]) {
				ans_cnt++;
				ans1 = mp[s1], ans2 = mp[s2];
			}
//			std::cout << s1 << ' ' << s2 << '\n';
		}
		if(ans_cnt == 0 || ans_cnt >= 2) std::cout << "D\n";
		else std::cout << ans1 << ans2 << '\n';
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
