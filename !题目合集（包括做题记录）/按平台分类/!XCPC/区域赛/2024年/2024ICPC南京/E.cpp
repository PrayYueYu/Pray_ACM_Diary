#include<bits/stdc++.h>
using namespace std;
void solve() {
	string s;
	int n, k;
	cin >> n >> k >> s;
	if (k > 6)k = 6;
	int ans = 0;
	for (int qs = 0; qs <= n - 7 + k; qs++) {
		string s1 = "";
		for (int j = qs; j < qs + 7; j++) {
			s1 += s[j % n];
		}
		if (s1 == "nanjing")ans++;
	}
	cout << ans << "\n";
}

signed main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
