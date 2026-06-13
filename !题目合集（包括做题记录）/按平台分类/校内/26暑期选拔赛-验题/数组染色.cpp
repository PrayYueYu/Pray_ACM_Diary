#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, k, a[N], maxnL[N], maxnR[N];
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
struct S {
	int a, id;
} s[N];
bool cmp(S x, S y) {
	return x.a < y.a;
}
void solve() {
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		s[i].a = a[i]; s[i].id = i;
	}
	std::sort(s + 1, s + n + 1, cmp);
	maxnR[n + 1] = 0;
	for(int i = n; i >= 1; i--)
		maxnR[i] = std::max(maxnR[i + 1], a[i]);
	for(int i = 1; i <= n; i++) 
		maxnL[i] = std::max(maxnL[i - 1], a[i]);
	int ans = 0;
	for(int i = 2; i < n; i++) {
		if(k == 1) continue;
		int cnt = 0, f1 = 0, f2 = 0, las = 0, sum = 0;
		for(int j = n; j >= 1; j--) {
			if(s[j].id == i) continue;
			sum += s[j].a;
			if(s[j].id < i) f1 = true;
			else f2 = true;
			cnt++;
			if(cnt == k) {
				las = s[j].a;
				break;
			}
		}
		if(f1 && f2) {
			ans = std::max(ans, sum + a[i]);
			continue;
		}
		if(!f1) sum = sum - las + maxnL[i - 1];
		else sum = sum - las + maxnR[i + 1];
		ans = std::max(ans, sum + a[i]);
	}
	ans = std::max(ans, a[1] + maxnR[2]);
	ans = std::max(ans, a[n] + maxnL[n - 1]);
	std::cout << ans << '\n';
}
signed main() {
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
