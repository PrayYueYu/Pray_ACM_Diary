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
std::string gets(int l, int r) {
	std::string ans = "";
	if(r < l) return ans;
	for(int i = l; i <= r; i++) ans += s[i];
	return ans;
}
std::map<std::string, bool> mp;
void solve() {
	std::string now = "";
	std::cin >> s;
	int ans = 1, len = s.size();
	for(int i = 0; i < len; i++) {
		now = gets(0, i - 1) + gets(i + 1, len - 1);
		if(!mp[now]) {
			mp[now] = true;
			ans++;
		}
	}
	mp.clear();
	for(int i = 0; i < len; i++) {
		for(int j = i + 1; j < len; j++) {
			now = gets(0, i - 1) + gets(i + 1, j - 1) + gets(j + 1, len - 1);
			if(!mp[now]) {
				mp[now] = true;
				ans++;
			}
		}
	}
	mp.clear();
	for(int i = 0; i < len; i++) {
		for(int j = i + 1; j < len; j++) {
			for(int k = j + 1; k < len; k++) {
				now = gets(0, i - 1) + gets(i + 1, j - 1) + gets(j + 1, k - 1) + gets(k + 1, len - 1);
				if(!mp[now]) {
					mp[now] = true;
					ans++;
				}
			}
		}
	}
	std::cout << ans;
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
