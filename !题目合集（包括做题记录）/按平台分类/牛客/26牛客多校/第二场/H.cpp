#include<bits/stdc++.h>
const int N = 5e6 + 10;
int n, a, b, vis[N];
void solve() {
	std::cin >> n >> a >> b;
	int now = (a ^ b), cnt = 0;
	for(int i = 0; i < n; i++) {
		if(now >> i & 1) cnt++;
	}
	if(cnt & 1) {
		std::cout << "No\n";
		return;
	}
	vis[a] = vis[b] = true;
	std::cout << "Yes\n";
	for(int i = 0; i < (1 << n); i++) {
		if(vis[i]) continue;
		now = 0;
		for(int j = 0; j < n; j++) {
			if(now) break;
			for(int k = j + 1; k < n; k++) {
				int t = (1 << j) + (1 << k);
				if(!vis[i ^ t]) {
					now = t;
					break;
				}
			}
		}
		std::cout << i << ' ' << (i ^ now) << '\n';
		vis[i] = vis[(i ^ now)] = true;
	}
	for(int i = 0; i < (1 << n); i++) vis[i] = false;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}
