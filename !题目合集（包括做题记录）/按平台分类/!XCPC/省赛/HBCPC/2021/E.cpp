#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n;
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
void print(int x, int y, int t) {
	if(x == 1 && y != 0) return;
	if(x > 0 && t) std::cout << "+" << x;
	else std::cout << x;
}
void solve() {
	std::cin >> s;
	int n = s.size();
	s = " " + s;
	std::vector<std::pair<int, int>> v;
	int a = 0, b = 0, f = 0, c = 1;
	for(int i = 6; i <= n; i++) {
		if(s[i] <= '9' && s[i] >= '0') {
			if(!f) a = a * 10 + s[i] - '0';
			else b = b * 10 + s[i] - '0';
		}
		if((s[i] == '-' || s[i] == '+') && i != 6) {
			if(!a) a = 1;
			if(!b) b = 1;
			v.push_back({a * c, b});
			a = b = f = 0;
			c = 1;
		}
		if(s[i] == '-') c = -1;
		if(s[i] == '+') c = 1;
		if(s[i] == 'x') f = 1;
	}
	if(f) {
		if(!a) a = 1;
		if(!b) b = 1;
		v.push_back({a * c, b});
	}
	else {
		if(a) v.push_back({a * c, b});
	}
	std::cout << "f'(x)=";
	int t = 0;
	if(v.size() == 1) {
		if(v[0].second == 0) {
			std::cout << "0\n";
			return;
		}
	}
	for(auto x: v) {
		a = x.first;
		b = x.second;
		a = a * b;
		b--;
		if(!a) continue;
		print(a, b, t);
		t++;
		if(b) std::cout << "x";
		if(b > 1) std::cout << "^" << b;
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
