#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int fac[N], invfac[N], cnt[100], sum[100];
int n, q, p2[100];
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
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ans;
}
void pre() {
	fac[0] = 1;
	for(int i = 1; i < N; i++) fac[i] = (fac[i - 1] * i) % mod;
	invfac[N - 1] = ksm(fac[N - 1], mod - 2);
	for(int i = N - 2; i >= 0; i--) {
		invfac[i] = invfac[i + 1] * (i + 1);
		invfac[i] %= mod;
	}
	p2[0] = 1;
	for(int i = 1; i <= 60; i++) {
		p2[i] = p2[i - 1] * 2;
	}
}
int C(int x, int y) {
	if(y > x) return 0;
	int ans = fac[x];
	ans = (ans * invfac[y]) % mod;
	ans = (ans * invfac[x - y]) % mod;
	return ans;
}
void solve() {
	n = read(), q = read();
	for(int i = 1; i <= n; i++) {
		int x = read();
		cnt[x]++;
	}
	for(int i = 0; i <= 60; i++) {
		if(!i) sum[i] = cnt[i];
		else sum[i] = sum[i - 1] + cnt[i];
	}
	for(int i = 1; i <= q; i++) {
		int op = read(), x = read();
		if(op == 1) {
			cnt[x]++;
			for(int i = 0; i <= 60; i++) {
				if(!i) sum[i] = cnt[i];
				else sum[i] = sum[i - 1] + cnt[i];
			}
			continue;
		}
		if(op == 2) {
			cnt[x]--;
			for(int i = 0; i <= 60; i++) {
				if(!i) sum[i] = cnt[i];
				else sum[i] = sum[i - 1] + cnt[i];
			}
			continue;
		}
		std::vector<int> r;
		r.resize(70);
		int capa = 0, np = 0;
		for(int j = 60; j >= 0; j--) {
			int val = 0;
			while(true) {
				if(np > j) break;
				if(capa + p2[j] / p2[np] <= x) {
					capa += p2[j] / p2[np];
					val++;
					np++;
				}
				else break;
			}
			r[j] = val;
		}
		//r数组即计算每种能力的需要多少个 
		//显然\sum ri <= 60 
		int now = 1, ans = 0, f = true;
		for(int j = 60; j >= 0; j--) {
			//计算的是从r+1到cnt的贡献 
			if(r[j] == cnt[j]) continue;
			if(r[j] > cnt[j]) {
				//如果r>cnt，说明从这里开始不会产生贡献，退出 
				f = false;
				break;
			}
			int s1 = 1, s2 = 1, sumx = 0;
			if(j) s1 = ksm(2, sum[j - 1]);
			s2 = ksm(2, cnt[j]);
			for(int k = 0; k <= r[j]; k++) {
				sumx += C(cnt[j], k);
				sumx %= mod;
			}
			s2 = (s2 - sumx + mod) % mod;
			ans += ((now * s1) % mod * s2) % mod;
			ans %= mod;
			now *= C(cnt[j], r[j]); now %= mod;
			//可以从大到小计算，从j+1~60的种类选取个数肯定是确定的
			//即选取个数等于r
			//如果j+1~60这些种类选取个数 < r
			//可以验证发现最后总能力值一定小于x
			//而且j+1~60这些种类在之前已经计算过从r+1~cnt的方案数
			//所以为了不重复计算，j+1~60这些种类只能选r个 
		}
		if(f) ans += now;//如果f=true说明最后还需要多加一次
		//即总能力恰好等于x的方案数 
		//f=false说明不能凑出来恰好等于x的方案 
		ans %= mod;
		std::cout << ans << '\n';
	}
}
signed main() {
	int T = 1;
	pre();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
