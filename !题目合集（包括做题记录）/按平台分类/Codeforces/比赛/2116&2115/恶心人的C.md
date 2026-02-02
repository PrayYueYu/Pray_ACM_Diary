# Gellyfish and Flaming Peony

题目地址：[Gellyfish and Flaming Peony](https://codeforces.com/contest/2116/problem/C)

## Solution

想了两个小时无语

首先想到纯暴力做法

以为最高就$n+1$次

最后看例子才找到反例

说实话被我蠢到了。。。

正解明显是DP，哎

### 反例

$a*b*c,\ \ \ a*b*d,\ \ \ b*e*c,\ \ \ a*f*c$

这四个数至少要$6$次

$dp$其实很简单

假设$f_{i,j}$表示把数组从$1\sim i$的某一个数变为$j$的最小步数

那么枚举$j$，加入第$a_i$的时候

$f_{i,gcd(a[i],j)}=min(f_{i-1,gcd(a[i],j)},f_{i-1,j}+1)$

意思是把假如数组$a_1\sim a_{i-1}$中某一个数变为$j$花了$f_{i-1,j}$步

那么把它从$j$变为$gcd(a[i],j)$则需要多花一步

注意初始化和特判（一开始就有全局gcd）

## Code

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 100, M = 998244353, INF = 1e9 + 10;
int n, a[N], f[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int main() {
	int T = read();
	while(T--) {
		n = read();
		int g = 0;
		for(int i = 1; i <= n; i++) {
			a[i] = read();
			if(!g) g = a[i];
			else g = __gcd(g, a[i]);
		}
		if(n == 1) {
			cout << 0 << endl;
			continue;
		}
		for(int i = 1; i <= n; i++) a[i] /= g;
		int sum = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i] == 1) sum++;
		}
		if(sum) {
			cout << n - sum << endl;
			continue;
		}
		for(int i = 0; i <= 5000; i++) f[i] = INF;
		for(int i = 1; i <= n; i++) {
			f[a[i]] = 0;
			for(int j = 1; j <= 5000; j++) {
				int x = __gcd(a[i], j);
				f[x] = min(f[x], f[j] + 1);
			}
		}
		cout << f[1] + n - 1 << endl;
	}
	return 0;
}
```

