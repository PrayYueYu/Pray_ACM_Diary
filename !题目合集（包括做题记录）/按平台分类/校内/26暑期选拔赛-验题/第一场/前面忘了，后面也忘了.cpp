#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, k, s1[N], s2[N], id;
int ask(int x) {
	std::cout << "? " << x << '\n';
	std::cout.flush();
	int ans; std::cin >> ans;
	return ans;
}
bool check(int mid) {
	int s = ask(mid);
	if(s1[(mid - 1) % k + 1] == s) return true;
	return false;
}
void print(int x) {
	if(x == -1) {
		std::cout << "! " << -1 << '\n';
		std::cout.flush();
		return;
	}
	std::cout << "! " << x << ' ' << n - x << '\n';
	std::cout.flush();
}
void getans(int l, int r) {
	r = std::min(r, n);
	int L = l, R = r;
	for(int i = l; i <= r; i++) {
		int x = ask(i);
		if(i >= n - k + 1) {
			R = std::min(R, i);
			continue;
		}
		if(i <= k) {
			L = std::max(L, i);
			continue;
		}
		if(s1[(i - 1) % k + 1] == s2[n - (n - i) % k]) continue;
		if(x == s1[(i - 1) % k + 1]) {
			L = std::max(L, i);
		}
		else R = std::min(R, i);
	}
	if(L + 1 == R) {
		print(L);
		return;
	}
	print(-1);
}
void solve() {
	id = 0;
	std::cin >> n >> k;
	if(n == k * 2) {
		print(k);
		return;
	}
	for(int i = 1; i <= k; i++) s1[i] = ask(i);
	for(int i = n; i >= n - k + 1; i--) s2[i] = ask(i);
	for(int i = 1; i <= k; i++) s2[i] = s2[n - (n - i) % k];
	int cnt = 0;
	for(int i = 1; i <= k; i++) {
		if(s1[i] != s2[i] && !id) id = i;
		if(s1[i] == s2[i]) cnt++;
	}
	if(cnt == k) {
		print(-1);
		return;
	}
	if(n <= 3 * k) {
		getans(k, n - k + 1);
		return;
	}
	int l = 1, r = n / k;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check((mid - 1) * k + id)) l = mid;
		else r = mid - 1;
	}
	getans((l - 1) * k + id, l * k + id);
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T; std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
