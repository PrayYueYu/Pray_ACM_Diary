#include<bits/stdc++.h>
#define int long long
const int N = 5e3 + 10, mod = 998244353, INF = 1e18;
int f1[N][N], f2[N][N], tr[N][N], cnt[N][N], n;
std::string s;
void pre(){
	for(int i = 1; i <= n; i++) {
		f1[i][n + 1] = f1[n + 1][i] = 0;
	}
    for(int i = n; i >= 1; i--) {
    	for(int j = n; j >= i + 1; j--) {
    		if(s[i] == s[j]) {
    			f1[i][j] = f1[i + 1][j + 1] + 1;
			}
			else f1[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(s[i] == s[j]) {
				f2[i][j] = f2[i - 1][j - 1] + 1;
			}
			else f2[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			f1[i][j] = std::min(f1[i][j], j - i);
			f2[i][j] = std::min(f2[i][j], j - i);
		}
	}
}
int gets1(int l1, int l2, int r1, int r2) {
	if(l1 > l2 || r1 > r2) return 0;
	int ans = tr[l2][r2] - tr[l1 - 1][r2] - tr[l2][r1 - 1] + tr[l1 - 1][r1 - 1];
	ans = (ans % mod + mod) % mod;
	return ans;
}
int gets2(int l1, int l2, int r1, int r2) {
	if(l1 > l2 || r1 > r2) return 0;
	int ans = cnt[l2][r2] - cnt[l1 - 1][r2] - cnt[l2][r1 - 1] + cnt[l1 - 1][r1 - 1];
	ans = (ans % mod + mod) % mod;
	return ans;
}
void solve() {
	std::cin >> s;
	n = s.size();
	s = " " + s;
	pre();
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(!f2[i][j]) continue;
			int L = i - f2[i][j] + 1;
			tr[1][j] += f2[i][j];
			tr[L][j] -= f2[i][j];
			
			tr[L][j] += i;
			tr[i][j] -= i;
			
			cnt[L][j]++;
			cnt[i][j]--;
		}
	}
	for(int r = 1; r <= n; r++) {
		int sumt = 0, sumc = 0;
		for(int l = 1; l <= n; l++) {
			sumt += tr[l][r];
			sumc += cnt[l][r];
			int t = sumt - sumc * l;
			tr[l][r] = t + tr[l - 1][r] + tr[l][r - 1] - tr[l - 1][r - 1];
			cnt[l][r] = t * (l - 1) + cnt[l - 1][r] + cnt[l][r - 1] - cnt[l - 1][r - 1];
			tr[l][r] %= mod, cnt[l][r] %= mod;
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 4; j <= n; j++) {
			int L = i + f1[i][j] - 1;
			if(!f1[i][j]) continue;
			int t1 = gets2(i + 1, L, i + 3, j - 1);
			int t2 = gets1(L + 1, j - 3, L + 3, j - 1);
			int t3 = gets1(i + 1, j - 3, i + 3, j - 1);
			int now = (((t1 + L * t2 % mod - (i - 1) * t3 % mod) % mod) + mod) % mod;
			ans = (ans + now) % mod;
		}
	} 
	std::cout << ans << '\n';
}
signed main() {
	solve(); 
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
