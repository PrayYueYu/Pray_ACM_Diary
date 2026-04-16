#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 100;
int vis[20];
int check(int x) {
	int ans = 0;
	for(int i = 0; i <= 9; i++) vis[i] = false;
	for(int i = 1; i <= 4; i++) {
		int t = x % 10;
		if(!vis[t]) {
			ans++;
			vis[t] = true;
		}
		x /= 10;
	}
	return ans;
}
void print(int x) {
	if(x <= 9) std::cout << "000";
	else if(x <= 99) std::cout << "00";
	else if(x <= 999) std::cout << "0";
}
void solve() {
	int x, y; std::cin >> x >> y;
	for(int i = x; ; i++) {
		if(check(i) == y) {
			std::cout << i - x << ' ';
			print(i);
			std::cout << i; 
			break;
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
