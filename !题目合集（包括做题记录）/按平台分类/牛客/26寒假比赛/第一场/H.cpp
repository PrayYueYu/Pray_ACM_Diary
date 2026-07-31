#include<bits/stdc++.h>
#define int long long
const int N = 3e5 + 10, mod = 998244353, INF = 1e18;
int n, a[N], f[N], pre[N], nex[N];
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
void init() {
	for(int i = 0; i <= n + 5; i++) {
		pre[i] = 0;
		f[i] = 0;
	}
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	int las = n + 1;
	for(int i = n; i >= 1; i--) {
		nex[i] = las;
		if(a[i]) las = i;
	}
	for(int i = 1; i <= n; i++) {
		int ad = 0, xr = 0, now = i;
		while(true) {
			ad += a[now];
			xr |= a[now];
			if(ad != xr) {
				break;
			}
			now = nex[now];
			if(now > n) break;
		}
		pre[i] = now - 1;
	}
	int ans = 1, sum = 0;
	for(int i = n - 1; i >= 1; i--) {
		if(!a[i] && !a[i + 1]) {
			f[i] = f[i + 1] + sum + 1;
			f[i] %= mod;
			sum += f[i + 1]; sum %= mod;
			ans += f[i]; ans %= mod;
			continue;
		}
		f[i] = ((sum + 1ll) * (pre[i] - i)) % mod;
		int t = 1;
		for(int j = pre[i]; j >= i + 2; j--) {
			f[i] = (f[i] - f[j] * t % mod) % mod;
			f[i] = (f[i] % mod + mod) % mod;
			t++;
		}
		f[i] = (f[i] % mod + mod) % mod;
		sum += f[i + 1]; sum %= mod;
		ans += f[i]; ans %= mod;
	}
	/*
	pre[i]代表最大的 t满足OR_{j=i}^t a[j]= \sum_{j=i}^t a[j]
	
	f[i]代表从a[i]和a[i+1]之间的符号必定改成'|'
	且a[1]~a[i]之间的符号都是'+' 的方案数 
	
	f[i]=\sum_{j=i+1}^{pre[i]}(1+\sum_{k=j+1}^n f[j])
	即从a[i]到j之间的符号都改成'|'
	且下一个'|'在k~k+1之间的方案数 之和 
	
	注意，如果有一大段连续的0，那么pre会很大，需要用nex加速一下
	（显然对于不是0的段最多跳31次）
	同时，对于一大段的0，它们的pre都相同，所以可以加速计算
	 
	 时间复杂度证明：
	 比如 i=3, pre[i]=200
	 显然中间至少有100多个0，最多有31个非0
	 那么对于[3,200]这个区间最多会被重复计算31次
	 因为最多只有31个非0，每个非0才会贡献一次循环
	 所以延伸到整个序列，[1,n]最多也只会被计算31次
	 时间复杂度为 O(31n) 
	*/
	std::cout << ans << '\n';
}
signed main() {
//	freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
