#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m;
std::string s[200000];
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
std::map<std::string, int> mp;
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		std::cin >> s[i];
		mp[s[i]] = true;
	}
	int now = 0;
	for(int i = 1; i <= n / m; i++) {
		std::vector<int> v;
		for(int j = 1; j <= m; j++) {
			int x = read();
			v.push_back(x);
		}
		for(int j = m - 1; j >= 0; j--) {
			now++;
			mp[s[now]] = v[j];
		}
	}
	int q = read();
	for(int i = 1; i <= q; i++) {
		std::string t = "";
		std::cin >> t;
		if(!mp[t]) std::cout << "Wrong Number\n";
		else std::cout << mp[t] << '\n';
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
