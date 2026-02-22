#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
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

void solve() {
	int info_cnt = 0, fs_h = 0, chg_cnt = 0;
	std::string chg = "chi1 huo3 guo1";
	while(true) {
		std::string s = "";
		getline(std::cin, s);
		if(s.size() == 1 && s[0] == '.') break;
		info_cnt++;
		s = " " + s;
		int sz = s.size();
		for(int i = 1; i <= sz; i++) {
			if(i + 13 > sz) break;
			int flag = true;
			for(int j = i; j <= i + 13; j++) {
				if(s[j] != chg[j - i]) {
					flag = false;
					break;
				}
			}
			if(flag) {
				if(!fs_h) fs_h = info_cnt;
				chg_cnt++;
				break;
			}
		}
	}
	std::cout << info_cnt << '\n';
	if(fs_h) std::cout << fs_h << ' ' << chg_cnt << '\n';
	else std::cout << "-_-#";
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
