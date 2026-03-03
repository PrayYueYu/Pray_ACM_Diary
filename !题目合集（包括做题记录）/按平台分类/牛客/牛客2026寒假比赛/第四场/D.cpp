#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 9e18;

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
int Exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	int d = Exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - (a / b) * y;
	return d;
}
int calc_up(int x, int y) {
	if(x % y == 0) return x / y;
	if((x <= 0 && y < 0) || (x >= 0 && y > 0)) 
		return x / y + 1;
	return x / y;
}
int calc_down(int x, int y) {
	if(x % y == 0) return x / y;
	if((x <= 0 && y < 0) || (x >= 0 && y > 0)) 
		return x / y;
	return x / y - 1;
}
void solve() {
	int L = read(), a = read(), b = read();
	int x, y; int g = Exgcd(a, b, x, y);
	if(L % g != 0) {
		std::cout << "No\n";
		return;
	}
	if(x < 0 && y < 0) {
		std::cout << "No\n";
		return;
	}	
	x *= (L / g); y *= (L / g);
	int tx;
	if(a > b) tx = calc_down(y, a / g);
	else tx = calc_up(-x, b / g);
	int X = calc_up(-x, b / g), Y = calc_down(y, a / g); 
	if(X > Y) {
		std::cout << "No\n";
		return;
	}
	int k = (b + a) / g;
	int m = x - y;
	//|x-y|=|kt+m| 
	int t = calc_up(-m, k);
	int minn = INF, ansc1 = 0, ansc2 = 0;
	for(int i = t - 50; i <= t + 50; i++) {
		int nowx = x + i * (b / g);
		int nowy = y - i * (a / g);
		if(nowx < 0 || nowy < 0) continue;
		if(std::max(nowx, nowy) < minn) {
			minn = std::max(nowx, nowy);
			ansc1 = nowx, ansc2 = nowy;
		}
	}
	std::cout << "Yes\n" << ansc1 << ' ' << ansc2 << '\n';
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
1
2 1 1
*/
