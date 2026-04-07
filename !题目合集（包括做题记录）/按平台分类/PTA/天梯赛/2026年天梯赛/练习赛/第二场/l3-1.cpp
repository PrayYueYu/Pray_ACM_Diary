#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
std::string s;
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
void spc(int x) {
	for(int i = 1; i <= 2 * x; i++) std::cout << ' ';
}
std::string gets(int l, int r) {
	std::string ans;
	for(int i = l; i <= r; i++) {
		ans += s[i];
	}
	return ans;
}
void solve() {
	getline(std::cin, s);
	int f = false, ff = false, tb = 0;
	int ffor = false, st = false;
	int fif = false, felse = false, ffor = false;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '{') {
			if(!ff) {
				ff = true;
				std::cout << "\n{\n";
			}
			st = true;
			continue;
		}
		else if(s[i] == '}') {
			tb--;
			if(st) spc(tb);
			std::cout << "}\n";
			st = true;
			continue;
		}
		else {
			if(s[i] == ' ' && !f) continue;
			f = true;
			if(s[i] == ')') ffor = false;
			if(gets(i - 2, i) == "for") ffor = true;
			if(gets(i - 1, i) == "if") {
				std::cout << " {"
			}
			if(gets(i - 3, i) == "else") felse = true;
			if(st) {
				st = false;
				spc(tb);
			}
			std::cout << s[i];
			if(s[i] == ';' && !ffor) {
				std::cout << "\n";
				st = true;
				f = false;
			}
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
