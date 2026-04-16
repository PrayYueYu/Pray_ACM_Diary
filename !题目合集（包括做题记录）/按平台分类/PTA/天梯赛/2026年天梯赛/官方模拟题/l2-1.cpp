#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 100;
int n;
std::stack<int> a;
std::stack<char> c;
void solve() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		int x; std::cin >> x;
		a.push(x);
	}
	for(int i = 1; i < n; i++) {
		char x; std::cin >> x;
		c.push(x);
	}
	while(true) {
		if(a.size() == 1) break;
		int n1 = a.top(); a.pop();
		int n2 = a.top(); a.pop();
		char x = c.top(); c.pop();
		if(x == '+') a.push(n1 + n2);
		if(x == '-') a.push(n2 - n1);
		if(x == '*') a.push(n1 * n2);
		if(x == '/') {
			if(!n1) {
				std::cout << "ERROR: " << n2 << "/0";
				return;
			}
			a.push(n2 / n1);
		}
	}
	std::cout << a.top();
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
