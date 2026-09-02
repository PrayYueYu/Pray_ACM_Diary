#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10;
int a[N], n, b[N];
void solve() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> ans;
	for(int i = 1; i <= n; i++) {
		if(!a[i]) continue;
		if(a[i] == -1) {
			int fx = false;
			for(int k = 1; k <= n; k++) {
				for(int j = 1; j <= n; j++) b[j] = a[j];
				b[i] = k;
				int sum = b[i], f = true, sumx = b[i];
				for(int j = 1; j <= n; j++) {
					if(i == j) continue;
					if(b[j] == -1) b[j] = b[i] - 1;
					else {
						sumx += b[j];
						if(b[j] >= b[i]) f = false;
					}
					sum += b[j];
				}
				if(sum >= n && f && sumx <= n) {
					fx = true;
					break;
				}
			}
			if(fx) ans.push_back(i);
		}
		else {
			int fx = false;
			for(int j = 1; j <= n; j++) b[j] = a[j];
			int sum = b[i], f = true, sumx = b[i];
			for(int j = 1; j <= n; j++) {
				if(i == j) continue;
				if(b[j] == -1) b[j] = b[i] - 1;
				else {
					sumx += b[j];
					if(b[j] >= b[i]) f = false;
				}
				sum += b[j];
			}
			if(sum >= n && f && sumx <= n) {
				fx = true;
			}
			if(fx) ans.push_back(i);
		}
	}
	for(auto x: ans) std::cout << x << ' ';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1;
//	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
