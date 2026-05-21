#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int a[10], b[10], n;
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
bool check() {
	int cnt = 0;
	for(int i = 1; i <= 4; i++) {
//		std::cout << a[i] << ' ' << b[i] << '\n';
		for(int j = 7; j >= 0; j--) {
			cnt++;
			int f = true;
			if(cnt > a[5]) return true;
			int x = (b[i] >> j & 1) & f;
			int y = (a[i] >> j & 1);
			if(x != y) return false;
		}
	}
	return true;
}
void solve() {
	std::string s;
	std::cin >> s;
	int t = 1;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '.' || s[i] == '/') {
			t++;
			continue;
		}
		a[t] = a[t] * 10 + s[i] - '0';
	}
	n = read();
	for(int i = 1; i <= n; i++) {
		std::cin >> s;
		t = 1;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == '.' || s[j] == '/') {
				t++;
				continue;
			}
			b[t] = b[t] * 10 + s[j] - '0';
		}
		if(check()) std::cout << "YES\n";
		else std::cout << "NO\n";
		for(int j = 1; j <= 4; j++) b[j] = 0;
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
