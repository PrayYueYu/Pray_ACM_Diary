#include<bits/stdc++.h>
#define int long long
const int N = 2e3 + 100;
void solve() {
	int x, f = 0; std::cin >> x;
	int y = x;
	if(x % 2 == 0) {
		y /= 2;
		int z = sqrt(y);
		if(z * z == y) {
			f = 1;
		}
	}
	y = x;
	if(x % 3 == 0 && f == 1) {
		y /= 3;
		for(int i = 1; i <= 50000; i++) {
			int z = i * i * i;
			if(z == y) {
				f = 2;
			}
		}
	}
	if(f == 1) std::cout << x << " is a double flower\n";
	else if(f == 2) std::cout << x << " is a triple flower\n";
	else std::cout << x << " is " << x << '\n';
}
signed main() {
	int T; std::cin >> T;
	while(T--) {
		solve();
	}
	return 0;
} 
