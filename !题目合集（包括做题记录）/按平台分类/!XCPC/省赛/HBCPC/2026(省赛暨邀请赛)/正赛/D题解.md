# [简单字符串题](https://hydro.ac/d/HBCPC2026/p/HBCPC2026D)

tag：`KMP`+`DP`+`FFT/NTT`

## Solution

假设我们暴力的做，令 $F_{i,j}$ 表示 $s_{1...i}(1-base)$ 分配给 $A$，$s_{j+1...n}$ 分配给 $C$，剩下的分配给 $B$​

再令 $f_i$ 表示 $s_{1...i}$ 这个字符串可以分解成多少种字符串的幂，即 $s_{1...i}=t^{x}$ 中 $x$ 有多少种取值

同理令 $g_i$ 表示 $s_{j...n}$ 可以分解成多少种字符串的幂

那么 $F_{i,j}=f_{i}*g_{j+1}*C_{i-j-1}^{k-1}$

最后答案即为：$ANS=\sum \sum F_{i,j}$，显然时间复杂度为 $O(n^2)$ 是无法通过的

### 计算 $f$ 和 $g$

利用 $KMP$ 中的 $next$ 数组可以求出来 一个前缀子串的最大幂是多少

即 $s_{1...i}=t^x$中 $x$ 最大是多少，假设为$x_{max}$，而其他 $x$ 一定都是 $x_{max}$ 的因数，所以可以在 $O(n*\sqrt{n})$的时间复杂度内求出来 $f$ 和 $g$​

（若$i\ mod\ (i-next_i)=0)$，那么 $x_{max}=i/(i-next_i)$，具体证明可以问 $deepseek$）

### $NTT$加速优化

令 $F_j=\sum F_{i,j}$

即 $F_{i}=g_{i+1}*\sum_{j=1}^{i-k} C_{i-j-1}^{k-1}*f_j$​

（对于前 $i$ 个，枚举$AB$分界点 $j$ 计算方案数）

可以发现这个式子可以用 $NTT$​ 加速

令 $a_i=f_{i+1}$，$b_i=C_{i-2}^{k-1}$（不合法的情况 $b_i=0$）（注意 $ab$都是$0$-$base$）

那么 $F_i=g_{i+1}*\sum_{j=0} a_j* b_{i-j}$，后面这一部分 $\sum a_j*b_{i-j}$可以用 $NTT$ 在 $O(nlogn)$ 的时间复杂度内求出来

最后 $ANS=\sum_{i=1}^{n} F_i$

## Code

```c++
#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, fac[N], invfac[N], p1[N], p2[N], fx[N], gx[N];
int inv_w[100], wx[100], g = 3, k, a[N], b[N], Max, f[N];
int cnt;
std::string s, t;
const int D = pow(2, 15);
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
		if(y & 1) ans = ans * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ans;
}
 
void init() {
	fac[0] = 1;
	for(int i = 1; i <= 1000000; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	invfac[1000000] = ksm(fac[1000000], mod - 2);
	for(int i = 999999; i >= 0; i--) {
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	}
	
	for(int i = 1; i <= 40; i++) {
		wx[i] = ksm(g, (mod - 1) / (1 << i));
		inv_w[i] = ksm(wx[i], mod - 2);
	}
}
void getnext2() {
	p2[1] = 0;
	for(int i = 2; i <= n; i++) {
	    int j = p2[i - 1];
	    while(true) {
	        if(t[j + 1] == t[i] || !j) break;
	        j = p2[j];
	    }
	    if(t[j + 1] == t[i]) j++;
	    p2[i] = j;
	}	
	for(int i = 1; i <= n; i++) {
		int x = (i - p2[i]);
		int t = i / x;
		if(i % x == 0) {
			int cntx = 0;
			for(int j = 1; j <= sqrt(t); j++) {
				if(t % j == 0) {
					int y = j;
					if(y * y != t) cntx += 2;
					else cntx++;
				}
			}
			gx[n - i + 1] = cntx;
		}
		else gx[n - i + 1] = 1;
	}	
}
void getnext1() {
	p1[1] = 0;
	for(int i = 2; i <= n; i++) {
	    int j = p1[i - 1];
	    while(true) {
	        if(s[j + 1] == s[i] || !j) break;
	        j = p1[j];
	    }
	    if(s[j + 1] == s[i]) j++;
	    p1[i] = j;
	}	
	for(int i = 1; i <= n; i++) {
		int x = (i - p1[i]);
		int t = i / x;
		if(i % x == 0) {
			int cntx = 0;
			for(int j = 1; j <= sqrt(t); j++) {
				if(t % j == 0) {
					int y = j;
					if(y * y != t) cntx += 2;
					else cntx++;
				}
			}
			fx[i] = cntx;
		}
		else fx[i] = 1;
	}
}
void NTT(int *a, int type) {
	for (int i = 0; i < Max; ++i) {
	    if(i < f[i]) std::swap(a[i], a[f[i]]);
	}
    for(int mid = 1, tx = 1; mid < Max; mid <<= 1, tx++) { 
    	int W = 0;
    	if(type == 1) W = wx[tx];
    	else W = inv_w[tx];
    	int len = mid << 1;
    	for(int j = 0; j < Max; j += len) { 
    		int w = 1;
    		for(int k = 0; k < mid; k++) {
    			int u = a[j + k];
    			int v = (w * a[j + k + mid]) % mod;
    			a[j + k] = (u + v) % mod;
    			a[j + k + mid] = (u - v + mod) % mod;
    			w = (w * W) % mod;
			}
		}
	}
    if(type == -1) {
        int inv_n = ksm(Max, mod - 2);
        for(int i = 0; i <= n + m; i++) a[i] = (a[i] * inv_n) % mod;
    }
}
void solve() {
	n = read(), k = read();
	std::cin >> s;
	for(int i = n - 1; i >= 0; i--) t += s[i];
	s = " " + s;
	t = " " + t;
	getnext1(), getnext2();
	
	if(!k) {
		int ans = 0;
		for(int i = 1; i < n; i++) {
			ans = (ans + fx[i] * gx[i + 1]) % mod;
		}
		std::cout << ans << '\n';
		return;
	}
	
	for(int i = 0; i < n; i++) {
		a[i] = fx[i + 1];
	}
	for(int i = 0; i <= n + 2; i++) {
		if(i - 2 < k - 1) continue;
		b[i] = fac[i - 2] * invfac[k - 1] % mod;
		b[i] = b[i] * invfac[i - 1 - k] % mod;
	}
	m = n + 2;
	n = n - 1;
	Max = 1;
	while(Max <= (n + m)) Max <<= 1, cnt++;
	for(int i = 0; i < Max; i++)
		f[i] = (f[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
	NTT(a, 1); NTT(b, 1);
	for(int i = 0; i <= Max; i++) a[i] = a[i] * b[i] % mod;
	NTT(a, -1);
	int ans = 0;
	for(int i = 2; i <= n; i++) 
		ans = (ans + a[i] * gx[i + 1]) % mod;
	std::cout << ans << '\n';
}
signed main() {
	init();
	int T = 1;
	while(T--) {
		solve();
	}
	return 0;
}
```

