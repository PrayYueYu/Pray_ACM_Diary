#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353;
int px[N], num;
int n, p[N], cnt, l, r;
int ans, P;
bool vis[10000007], R[10000007];
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
void pre() {
	vis[1] = true;
//	int las = 0, maxn = 0;
	for(int i = 2; i <= 10000000; i++) {
		if(!vis[i]) {
			px[++num] = i;
//			maxn = std::max(maxn, i - las); las = i;
		}
		for(int j = 1; j <= num; j++) {
			if(i * px[j] > 1e7) break;
			vis[i * px[j]] = true;
			if(i % px[j] == 0) break;
		}
	}
//	std::cout << maxn;
}
int calc(int x) {
	int minn = std::min(r, P);
	return (minn / x) - (l - 1) / x;
}
void dfs(int x) {
	if(x == cnt + 1) {
		int now = 1, val = 0;
		for(int i = 1; i <= x; i++) {
			if(R[i]) val++, now = now * p[i];
		}
		if(now == 1) return;
		if(val & 1) ans = ans + calc(now); 
		else ans -= calc(now);
//		std::cout << now << ' ' << calc(now) << '\n';
		return;
	}
	R[x] = true;
	dfs(x + 1);
	R[x] = false;
	dfs(x + 1);
}
void solve() {
	ans = 0; cnt = 0, P = 0;
	std::cin >> l >> r >> n;
	int nx = n;
	if(n == 2) {
		if(l == 1 && r == 1) std::cout << "1\n";
		return;
	}
	for(int i = n - 1; i >= n - 200; i--) {
		if(!vis[i]) {
			P = i;
			break;
		}
	}
	if(P < l) {
		int leng = nx - P;
		std::vector<int> dp(leng+1, 0x3f3f3f3f3f3f3f3f3fll);
		dp[leng] = 0;
		for (int i = nx - 1; i > P; i--) {
		    for (int j = i + 1; j <= nx; j++)
		  	  dp[i - P] = std::min(dp[i - P], std::__gcd(i, j) + dp[j - P]);
		}
		for(int i = l; i <= r; i++) {
			ans += dp[i - P];
		}
		std::cout << ans << '\n';
		return;
	}
	
	for(int i = 2; i <= sqrt(n); i++) {
		if(vis[i]) continue;
		if(n % i == 0) {
			p[++cnt] = i;
			while(true) {
				if(n % i == 0) n /= i;
				else break;
			}
		}
	}
	if(!vis[n]) p[++cnt] = n;
	dfs(1);
	if(r <= P) {
//		std::cout << ans << '\n';
		ans = r - l + 1 - ans;
		std::cout << 2 * (r - l + 1) - ans << '\n';
		return;
	}
	ans = P - l + 1 - ans;
	ans = 2 * (P - l + 1) - ans;

	int leng = nx - P;
	std::vector<int> dp(leng+1, 0x3f3f3f3f3f3f3f3f3f);
	
	dp[leng] = 0;
	for (int i = nx - 1; i > P; i--) {
	    for (int j = i + 1; j <= nx; j++) {
//			std::cout << i - P << ' ' << j - P << '\n';
	  	  	dp[i - P] = std::min(dp[i - P], std::__gcd(i, j) + dp[j - P]);
			
		}
	}	
	for(int i = P + 1; i <= r; i++) {
		ans += dp[i - P];
	}
	std::cout << ans << '\n';
}
signed main() {
	pre();
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
1
2 33 36

	Writer: ÔÂö§Þ±‹¬ 
*/
