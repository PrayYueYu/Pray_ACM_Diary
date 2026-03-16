#include<bits/stdc++.h>
#define int long long
const int N = 2e3 + 100;
void print(int x) {
	if(x <= 9) std::cout << 0 << x;
	else std::cout << x;
}
void solve() {
	int h = 0, m = 0, s = 1;
	int a, b, x;
	std::cin >> a >> b;
	a = a + b; 
	while(true) {
		if(h == 3) break;
		std::cin >> x;
		if(x == a) {
			std::cout << a << " Accepted ";
			print(h); std::cout << ":";
			print(m); std::cout << ":";
			print(s);
			return;
		}
		
		s += 2;
		if(s >= 60) {
			s-= 60;
			m++;
		}
		if(m >= 60) {
			m -= 60;
			h++;
		}
	}
	std::cout << x << " Wrong Answer ";
	std::cout << "02:59:59";
}
signed main() {
	solve();
	return 0;
} 
