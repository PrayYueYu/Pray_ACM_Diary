## Description

给定正整数 n,k，求不定方程 $a^k−b^k=n$ 的正整数解数量。

## Input

输入第一行一个整数 T（$$1\le T\le 20$$） 表示询问数量。之后 T 行，每一行两个整数 n,k 表示一次询问。保证 $1\le n\le 10^{18}$，$3\le k\le 64$。

## Output

对于每一组询问，输出一行一个非负整数表示答案。



2023年复盘题

## Solution

乍一看不难，枚举一下$b$即可（$b\le \sqrt N$）

时间复杂度O($T * \sqrt N$)，显然不行

令$a=b+t$，那么原式=$(b+t)^k-b^k=\sum_{i=1}^{k}(C_k^i*b^{k-i}*t^i)=n$

显然有$n\%t=n\%(a-b)=0$

注意到$n=\sum_{i=1}^{k}(C_k^i*b^{k-i}*t^i)>t^k$，解得$t\le \sqrt[k]N$（最大为$10^6$）

同时注意到$n=\sum_{i=1}^{k}(C_k^i*b^{k-i}*t^i)>k*t*b^{k-1}$，解得$$b\le \sqrt[k-1]{\frac{N}{k \cdot t}} $$

那么枚举$t=a-b$，再二分一下$b$即可，时间复杂度$O(T*\sqrt[k]N*log(\sqrt[k-1]{\frac{N}{k \cdot t}}))$，最坏情况下依旧可行

**问题：**发现在二分的时候，使用$pow(R,k)$会出错，因为数据太大，而**pow返回类型为double，不能储存太大的数**，所以需要用到**__int128和快速幂**，由此问题解决

## Code

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 10, INF = 1e9 + 7;
ll n, k, ans;
double eps = 1e-9;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
__int128 ksm(__int128 x, __int128 y) {
	__int128 ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x);
		x = x * x;
		y >>= 1;
	}
	return ans;
}
int main() {
	int T = read();
	while(T--) {
		n = read(), k = read();
		ans = 0;
		for(int i = 1; i <= 1e6; i++) {
			if(n % i != 0) continue;
			ll l = 1, r = pow(n / k, 1.0 / (double)(k - 1)) + 3;
			while(l <= r) {
				ll mid = (l + r) >> 1;
				__int128 x = ksm(mid + i, k);
				__int128 y = ksm(mid, k);
				__int128 del = x - y;
				if(del == n) {
					ans++;
					break;
				}
				if(del < n) l = mid + 1;
				else r = mid - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
```

## Summery

对于求幂，最好都用快速幂代替，防止出错

对于二分，一定要找好范围