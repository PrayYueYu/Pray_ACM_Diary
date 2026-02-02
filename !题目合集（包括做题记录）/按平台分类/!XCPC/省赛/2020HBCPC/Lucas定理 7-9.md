# [7-9 Tang Hulu](https://pintia.cn/problem-sets/1917898115355783168/exam/problems/type/7?problemSetProblemId=1917898115422892040)

## 题目大意

一共$T(T\le10^6)$组

给你$1$~$n(n\le10^9)n$个数字，将它们分为$m(\sum m \le 10^6)$组，并打乱顺序，每一组需要满足以下条件：

1. 所包含的数组必须连续。比如$[1,2,4]$不符合条件，缺了$3$，而$[2,3,4]$符合条件
2. 假设某一组第$i$个数字为$a_i$，第$j$个数字为$a_j$（$1<i<j$），不能找到$k>j$，使得$min(a_i,a_j)<a_k<max(a_i,a_j)$。比如$[3,1,2]$不满足，因为$2$在$\{3,1\}$后面，并且$1<2<3$，而$[3,4,2,1]$则符合条件

问有多少种方案，$Mod=998244353$

## Solution

### $Step1:$

对于第一步，~~最简单的方法当然是打表~~

考虑$m=1$（只有一个部分）。

对于$1$~$n$，假设第一个数是$i$，那么可以发现后面的数字有如下规律：

1. 对于大于$i$的数字，必定单调递增

2. 对于小于$i$的数字，必定单调递减

比如$[3,4,5,2,1]$，对于$[2,1]$单调递减，对于$[4,5]$单调递增

这样一定能满足条件

假设不考虑单调顺序，以$i$开头的显然有$(n-1)!$种情况

如果考虑顺序，那么用简单高中数学知识可得一共有$(n-1)!/((n-i)!*(i-1)!)$

因为单调顺序确定，所以xxxxxx

可以观察到，上式恰好等于$C_{n-1}^{i-1}$

那么对于一个长$n$的部分，总个数即为：$\sum_{i=1}^{n}C_{n-1}^{i-1}=2^{n-1}$

### $Step2:$

考虑$m>=2$

不难发现对于某一种划分，总方案数为：$Ans=\prod_{i=1}^{m}ans_i$

$ans_i$为第$i$部分的方案数

假设第$i$部分长度为$L_i$，那么$Ans=2^{\sum {L_i-1}}=2^{(\sum L_i)-m}=2^{n-m}$

方案数总是固定

那么用**隔板法**，求出一共有$C_{n-1}^{m-1}$种分法（每部分至少一个数）

注意到题目说每部分顺序可打乱，所需最后答案还要乘上$m!$

所以最后$Ans=2^{n-m}*C_{n-1}^{m-1}*m!$

### $Step3:$

对于$2^{n-m}$可以用快速幂

对于$m!$可以预处理（$m$很小）

对于$C_{n-1}^{m-1}$显然不能用暴力求，显然也无法预处理保存，因为$n$很大

那么只能用一个小众（？）算法：大名鼎鼎的**$Lucas$定理**！

**p.s. $Lucas$的时间复杂度为$O(m*log n)$左右**

直接抄模板吧，，，

特别注意：当$m>n$的时候，答案为$0$，需要特判以免$TLE$，特判细节，唉唉

## Code

```c++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 10, M = 998244353;
ll n, m, a[N], ans, P[N], fac[N], inv[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
ll ksm(ll x, ll y) {//快速幂
	ll ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % M;
		x = (x * x) % M;
		y >>= 1;
	}
	return ans;
}

void init() {//初始化
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % M;
    }
    inv[N - 1] = ksm(fac[N - 1], M - 2);//逆元初始化
    for (int i = N - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % M;
    }
}

// 计算组合数 C(n, m) % Mod（n, m < Mod）
ll comb(ll x, ll y) {
    if (y < 0 || y > x) return 0;
    if (x < N) {  // 如果 n 在预处理范围内，直接查表
        return fac[x] * inv[y] % M * inv[x - y] % M;
    }
    // 否则暴力计算 C(n, m) = fac(n) / (fac(m) * fac(n - m))
    ll res = 1;
    for (ll i = x; i > x - y; i--) res = res * i % M;
    res = res * ksm(fac[y], M - 2) % M;
    return res;
}

// Lucas 定理计算 C(n, m) % Mod
ll Lucas(ll x, ll y) {
    if (y == 0) return 1;
    return comb(x % M, y % M) * Lucas(x / M, y / M) % M;
}
ll Factorial(ll x) { //求阶乘
	ll ans = 1;
	for(int i = 1; i <= x; i++) ans = (ans * i) % M;
	return ans;
}

int main() {
    int T = read(); init();//初始化
    while(T--) {
    	n = read(), m = read();
    	if(m > n) {//特判
    		cout << 0;
    		continue;
		}
    	ll ans1 = ksm(2, n - m);//2^{n-m}
    	ll ans2 = Lucas(n - 1, m - 1);//C_{n-1}^{m-1}
    	ll ans3 = Factorial(m);//m!
    	ll ans = (ans1 * ans2) % M;
    	ans = (ans * ans3) % M;
    	cout << ans << endl;
	}
    return 0;
}
```

