#include<bits/stdc++.h>
const int N = 1e6 + 10, M = 1e9 + 7;
int n, a[N];
std::vector<int> v;
void solve() {
	v.clear();
	std::cin >> n;
	n *= 2;
	for(int i = 1; i <= n; i++) std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	a[n + 1] = -1;
	int cnt = 1, s = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == a[i + 1]) {
			cnt++;
			if(!(cnt & 1)) s ^= a[i];
		}
		else {
			if(cnt & 1) {
				v.push_back(a[i]);
			}
			cnt = 1;
		}
	}
	if(v.size() > 2) {
		std::cout << "Bot\n";
		return;
	}
	if(!v.size()) {
		if(!s) std::cout << "Menji\n";
		else std::cout << "Bot\n";
		return;
	}
	if(s == v[0] || s == v[1]) {
		std::cout << "Menji\n";
		return;
	}
	std::cout << "Bot\n";
}

signed main() {
	int T; std::cin >> T;
	while(T--) solve();
	return 0;
}
/*

*/
