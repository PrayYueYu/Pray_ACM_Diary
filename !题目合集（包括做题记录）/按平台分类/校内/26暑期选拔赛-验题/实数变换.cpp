#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
double a, b, p[100];
int vis[100];
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
	std::cin >> a >> b;
	double eps = 1e-6;
	std::string ans = "", ansr = "";
	p[0] = 1.0;
	a = 0;
	for(int i = 1; i <= 14; i++) {
		p[i] = p[i - 1] * 0.5;
		if(a + p[i] <= b) {
			vis[i] = true;
			a += p[i];
		}
	}
	for(int i = 1; i <= 14; i++) {
		if(vis[i]) ansr += "2";
		else ansr += "1";
	}
	std::reverse(ansr.begin(), ansr.end());
	ans += ansr;
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
