#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;

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
std::string s;
bool check(int x) {
	if(x < 0 || x >= s.size()) return false;
	char c = s[x];
	if(c >= '0' && c <= '9') return true;
	if(c >= 'A' && c <= 'Z') return true;
	if(c >= 'a' && c <= 'z') return true;
	return false;
}
std::string gets(int l, int r) {
	std::string ans = "";
	for(int i = l; i <= r; i++) {
		ans += s[i];
	}
	return ans;
}
void solve() {
	int n = read();
	for(int i = 1; i <= n; i++) {
		s = "";
		getline(std::cin, s);
		std::cout << s << '\n' << "AI: ";
		int ed, ft;
		for(int j = s.size() - 1; j >= 0; j--) {
			if(s[j] != ' ') {
				ed = j;
				break;
			}
		}
		for(int j = 0; j <= ed; j++) {
			if(s[j] != ' ') {
				ft = j;
				break;
			}
		}
		std::string sx = "";
		int cnt = 0;
		for(int j = ft; j <= ed; j++) {
			if(s[j] == ' ') {
				cnt++;
				continue;
			}
			else {
				if(check(j) && cnt) sx += ' ';
				cnt = 0;
			}
			sx += s[j];
		}
		s = sx; sx = "";
		ft = 0, ed = s.size() - 1;
		for(int j = ft; j <= ed; j++) {
			if(s[j] >= 'A' && s[j] <= 'Z' && s[j] != 'I') {
				s[j] = (char)(s[j] + 'a' - 'A');
			}
		}
		for(int j = ft; j <= ed; j++) {
			if(j + 6 <= ed && gets(j, j + 6) == "can you" && !check(j - 1) && !check(j + 7)) {
				j = j + 6;
				sx += "I can";
				continue;
			}
			if(j + 8 <= ed && gets(j, j + 8) == "could you" && !check(j - 1) && !check(j + 9)) {
				j += 8;
				sx += "I could";
				continue;
			}
			if(s[j] == 'I' && !check(j - 1) && !check(j + 1)) {
				sx += "you";
				continue;
			}
			if(j + 1 <= ed && gets(j, j + 1) == "me" && !check(j - 1) && !check(j + 2)) {
				j += 1;
				sx += "you";
				continue;
			}
			if(s[j] == '?') sx += '!';
			else sx += s[j];
		}
		std::cout << sx;
		std::cout << '\n';
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
