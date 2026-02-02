# gcd 与 lcm

题目地址：[gcd 与 lcm](https://www.luogu.com.cn/problem/P10580)

## Solution

假设$a_i=x*b_i$

那么必有$LCM(b_1, b_2,b_3,...,b_n)=y/x$（LCM是最小公倍数）

且$GCD(b_1,b_2,b_3,...,b_n)=1$（否则$\{a\}$的$gcd$不为$x$）

设$P=y/x$

假设$P=\prod_{i=1}^{k}p_i^{q_i}$，其中$p_i$为质数

那么$b_i=\prod_i^k p_i^{qb_i}$（$qb_i$可能为0）

那么对于第$i$个质因数$p_i$，只需要分配一下即可

假设毫无限制，那么对于第$i$个质因数，在序列$b$中共有$(q_i+1)^n$种情况

（$\{b\}$中任意一个$b_j$能取到$q_i^{0\sim p_i}$）

由于$lcm=y/x,\ gcd=1$

所以对于第$i$个质因数，$qb_i$中必定有一个为0，有一个为$q_i$

那么容斥一下，总情况数$-$没有0的情况数$-$没有$q_i$的情况数$+$既没有0又没有$q_i$的情况数即为第$i$个质因数的贡献

所以总答案$ans=\prod_{i=1}^k((q_i+1)^n-2*q_i^n+(q_i-1)^n)$

## Code

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 100, M = 998244353, INF = 1e13 + 10;
ll n, vis[N], p[N], num;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void Prime() {
	ll Max = 1e5;
	for(int i = 2; i <= Max; i++) {
		if(!vis[i]) p[++num] = i;
		for(int j = 1; j <= num ;j++) {
			if(i * p[j] > Max) break;
			vis[i * p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
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
ll Solve(ll x) {
	ll ans = 1;
	for(int i = 1; i <= num; i++) {
		ll cnt = 0, now = 0;
		while(true) {
			if(x % p[i] == 0) cnt++, x /= p[i];
			else break;
		}
		if(!cnt) continue;
		now = (now + ksm(cnt + 1, n)) % M;
		now = (now - (2 * ksm(cnt, n)) % M + M) % M;
		now = (now + ksm(cnt - 1, n)) % M;
		ans = (ans * now) % M; 
	}
	if(x == 1) return ans;
	for(int i = 2; i <= sqrt(x); i++) {
		if(x % i == 0) return ans;
	}
	ll cnt = 1, now = 0;
	now = (now + ksm(cnt + 1, n)) % M;
	now = (now - (2 * ksm(cnt, n)) % M + M) % M;
	now = (now + ksm(cnt - 1, n)) % M;
	ans = (ans * now) % M; 
	return ans;
}
int main() {
	int T = read();
	Prime();
	while(T--) {
		ll x = read(), y = read(), P; n = read();
		P = y / x;
		ll ans = Solve(P);
		cout << ans << endl;
	}
	return 0;
}
```

