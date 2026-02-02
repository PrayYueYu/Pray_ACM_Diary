# Dating Day

**题目地址**：[Dating Day](https://codeforces.com/gym/105911/problem/I)

## Solution

一眼数论

不过我思路似乎和正解不太一样

假设现在有一段$01$字符串$01010010$，其中$k=2$

那么这一段的答案是多少呢？

首先，显然把这个字符串分成两个部分

$010100$和$010010$（前两个和后两个）

先分别求解答案

对于第一个，假设其中交换了 $i$ 对$(0,1)$的顺序

那么$ans = C_4^i * C_2^i$（即分别从$0,1$中选取 $i$ 个进行交换）

那么对于第一个$01$串的答案为$\sum_{i=0}^{min(k,x)}C_k^i * C_x^i$（假设$0$的个数为$x$）

那么对于其它串的答案亦为上述答案

这样写上去发现。。**$Wrong\ On\ Test\ 1$！！**

为什么呢，因为在第一个串和第二个串中间有交集，需要减去

交集的答案为$\sum_{i=0}^{min(k-1,x-y)}C_{k-1}^i * C_{x-y}^i$，其中$y$为第二个串最后一个$1$到下一个$1$之间有多少零

具体来说，假设第$i$到第$i+1$个$1$中间有$num_i$个$0$（第$1$个$1$之前的算$num_0$），再假设$num0$为第$i-k+1$个$1$到第$i$个$1$之间有多少个$0$，对于第$num1$（$num1>=k$）个$1$，它的答案为

假设$x=num0+num_{num1}$（此为$0$的总个数）

$A.$ 假设$i=k$，那么不需要容斥，

$ans=\sum_{i=0}^{min(k,x)}C_k^i * C_x^i$

$B.$ 假设$i>k$，那么需要容斥

$ans1=\sum_{i=0}^{min(k,x)}C_k^i * C_x^i$

再令$x=x-num_{num1}$（中间共有的$0$的个数）

$$ans2=\sum_{i=0}^{min(k-1,x)}C_{k-1}^i * C_x^i$$

最后$ans=ans1-ans2$

需要注意的是$num0$的变换

## Code

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 100, M = 998244353, INF = 1e9 + 10;
ll n, m, k, frac[N], inv_frac[N], num[N];
string s;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
ll ksm(ll x, ll y) {
	ll ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % M;
		x = (x * x) % M;
		y >>= 1;
	}
	return ans;
}
void Init() {
	frac[0] = 1;
	for(int i = 1; i <= 1e5; i++) frac[i] = (frac[i - 1] * i) % M;
	inv_frac[100000] = ksm(frac[100000], M - 2);
	for(int i = 1e5 - 1; i >= 0; i--) 
		inv_frac[i] = (inv_frac[i + 1] * (i + 1)) % M;
}
ll C(ll x, ll y) {
	ll ans = 1;
	ans = (ans * frac[x]) % M;
	ans = (ans * inv_frac[y]) % M;
	ans = (ans * inv_frac[x - y]) % M;
	return ans;
}
ll Solve(ll t, ll x, int op) {
	ll ans = 0, kx = k;
	x += num[t];
	for(int i = 0; i <= min(kx, x); i++) 
		ans = (ans + C(x, i) * C(kx, i) % M) % M;
	if(!op) return ans;
	x -= num[t]; kx--; ll ans2 = 0;
	for(int i = 0; i <= min(kx, x); i++) 
		ans2 = (ans2 + C(x, i) * C(kx, i) % M) % M;
	return (ans - ans2 + M) % M;
}
int main() {
	Init();
	int T = read();
	while(T--) {
		n = read(); k = read();
		getline(cin, s);
		s = " " + s;
		ll t = 0;
		for(int i = 1; i <= n; i++) {
			if(s[i] == '1') t++;
			else num[t]++;
		}
		ll num1 = 0, num0 = 0, ans = 0;
		for(int i = 1; i <= n; i++) {
			if(s[i] == '1') num1++;
			else num0++;
			if(num1 >= k && s[i] == '1') {
				if(num1 > k) {
					num0 -= num[num1 - k - 1];
					ans = (ans + Solve(num1, num0, 1)) % M;
				}
				else ans = (ans + Solve(num1, num0, 0)) % M;
			}
		}
		for(int i = 0; i <= n; i++) num[i] = 0;
		cout << ans << endl;
	}
	return 0;
}
```

