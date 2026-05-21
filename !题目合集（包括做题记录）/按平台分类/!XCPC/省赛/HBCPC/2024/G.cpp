#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[10], b[10];
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
int gets(char x, char y) {
	if(x == '0' && y == '0') return 0;
	if(x == '1' && y == '1') return 2;
	return 1; 
}
bool check(int mid) {
	int cnt = 0;
	b[0] = b[1] = b[2] = 0;
	for(int i = 0; i + 1 < 2 * n; i += 2) {
		int op = gets(s[i], s[i + 1]);
		b[op]++;
		if(cnt < mid) cnt++;
		else {
			op = gets(s[i - mid * 2], s[i + 1 - mid * 2]);
			b[op]--;
		}
		if(cnt == mid) {
			int f = true;
			for(int j = 0; j < 3; j++) {
				if(b[j] > a[j]) f = false;
			}
			if(f) return true;
		}
		
	}
	cnt = 0;
	b[0] = b[1] = b[2] = 0;
	for(int i = 1; i + 1 < 2 * n; i += 2) {
		int op = gets(s[i], s[i + 1]);
		b[op]++;
		if(cnt < mid) cnt++;
		else {
			op = gets(s[i - mid * 2], s[i + 1 - mid * 2]);
			b[op]--;
		}
		if(cnt == mid) {
			int f = true;
			for(int j = 0; j < 3; j++) {
				if(b[j] > a[j]) f = false;
			}
			if(f) return true;
		}
	}
	return false;
}
void solve() {
	for(int i = 0; i < 3; i++) a[i] = read();
	std::cin >> s;
	s = s + s;
	n = s.size() / 2;
	int l = 0, r = n / 2;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	std::cout << l * 2;
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
