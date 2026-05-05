#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, x, y, sum0[N], sum1[N];
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
int calc(int a, int b) {
	if(a % b == 0) return a / b;
	return a / b;
}
void solve() {
	n = read(), x = read(), y = read();
	std::cin >> s;
	if(!x && !y) {
		for(int i = 0; i < n; i++) {
			if(s[i] == '2') std::cout << 0;
			else std::cout << s[i];
		}
		std::cout << '\n';
		return;
	}
	s = " " + s;
	if(!x) {
		for(int i = 1; i <= std::min(n, y); i++) {
			if(s[i] == '0') {
				std::cout << -1 << '\n';
				return;
			}
		}
		for(int i = 1; i <= std::min(n, y); i++) 
			std::cout << 1;
		for(int i = std::min(n, y) + 1; i <= n; i++) {
			if(s[i] == '2') std::cout << 0;
			else std::cout << s[i];
		}
		std::cout << '\n';
		return;
	}
	if(!y) {
		for(int i = 1; i <= std::min(n, x); i++) {
			if(s[i] == '1') {
				std::cout << -1 << '\n';
				return;
			}
		}
		for(int i = 1; i <= std::min(n, x); i++) 
			std::cout << 0;
		for(int i = std::min(n, x) + 1; i <= n; i++) {
			if(s[i] == '2') std::cout << 0;
			else std::cout << s[i];
		}
		std::cout << '\n';
		return;
	}
	for(int i = 1; i <= n; i++) {
		sum1[i] = sum1[i - 1];
		sum0[i] = sum0[i - 1];
		if(s[i] == '1') sum1[i]++;
		if(s[i] == '0') sum0[i]++;
	}
	std::string ans = "";
	for(int i = std::min(n - 1, n - sum1[n]); i >= std::max(1ll, sum0[n]); i--) {
		int a = i, b = n - i;
		int t1 = calc(x, a), t2 = calc(y, b);
		int t = std::min(t1, t2);
		a = a * t, b = b * t;
		a = x - a, b = y - b;
		if(a + b > n) continue;
		if(sum0[a + b] <= a && sum1[a + b] <= b) {
			std::string now = "";
			if(sum0[n] - sum0[a + b] > i - a) continue;
			if(sum1[n] - sum1[a + b] > (n - i) - b) continue;
			int a0 = a;
			a = a - sum0[a + b]; 
			for(int j = 1; j <= a0 + b; j++) {
				if(s[j] == '2') {
					if(a) {
						now += "0";
						a--;
					}
					else now += "1";
				}
				else now += s[j];
			}
			a = a0; a = i - a - (sum0[n] - sum0[a + b]);
			for(int j = a0 + b + 1; j <= n; j++) {
				if(s[j] == '2') {
					if(a) {
						now += "0";
						a--;
					}
					else now += "1";
				}
				else now += s[j];
			}
			if(ans == "") ans = now;
			else ans = std::min(ans, now);
		}
		
	}	
	if(ans == "") std::cout << "-1\n";
	else std::cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
