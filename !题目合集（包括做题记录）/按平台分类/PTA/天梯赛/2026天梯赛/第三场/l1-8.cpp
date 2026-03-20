#include<bits/stdc++.h>
#define int long long
const int mod = 998244353, N = 1e5 + 3;
int n, m;
std::string s[N], b[N];
int read() {
	int x;
	std::cin >> x;
	return x;
}
bool check(int l, int r) {
	if(l < 1) return false;
	for(int i = l; i <= r; i++) {
		if(b[i - l + 1] != s[i]) return false;
	}
	return true;
}
void solve() {
	n = read(), m = read();
	int N = n;
	for(int i = 1; i <= n; i++) {
		std::cin >> s[i];
	}
	for(int i = 1; i <= m; i++) {
		int op = read();
		std::vector<std::string> sx;
		if(op == 1) {
			int L = read();
			for(int j = 1; j <= L; j++) {
				std::cin >> b[j];
			}
			std::string t; std::cin >> t;
			for(int j = 1; j <= n; j++) {
				sx.push_back(s[j]);
				if(check(j - L + 1, j)) {
					sx.push_back(t);
				}
			}
			n = sx.size();
		}
		if(op == 2) {
			int pos1 = read(), L = read(), pos2 = read();
			for(int j = 1; j <= n; j++) {
				if(j >= pos1 && j <= pos1 + L - 1) continue;
				sx.push_back(s[j]);
				if(j == pos2) {
					for(int k = pos1; k <= pos1 + L - 1; k++) {
						sx.push_back(s[k]);
					}
				}
			}
		}
		if(op == 3) {
			int l = 1, r = (n + 1) / 2 + 1;
			int mid = (n + 1) / 2;
			while(true) {
				if(l <= mid) {
					sx.push_back(s[l]);
					l++;
				}
				if(r <= n) {
					sx.push_back(s[r]);
					r++;
				}
				if(l > mid && r > n) break;
			}
		}
		for(int j = 1; j <= n; j++) s[j] = sx[j - 1];
	}
	for(int i = 1; i <= n; i++) {
		std::cout << s[i];
		if(i != n) std::cout << ' ';
	}
}
signed main() {
//	freopen("1.in", "r", stdin);
//	freopen("1x.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	solve();
	return 0;
}
