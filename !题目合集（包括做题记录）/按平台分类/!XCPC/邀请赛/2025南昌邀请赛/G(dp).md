# D. Exploration

**题目地址：**[Exploration](https://codeforces.com/gym/105911/problem/G)

## Solution

难度不大，挺模板的一道题

图上$DP$

首先如果询问的时候搜索无论怎样都会超时，所以一定是预处理

那么可以发现数据都很大，如果用一维数组$f_i$是肯定没办法储存所有答案

那么考虑二维数组$f_{i,j}$，假如$i,j$都很大那肯定存不下，所以现在应该想到$j$不会很大

这个时候再发现$d>=2$，那么$j$是什么显而易见了

$f_{i,j}$表示从$i$点出发，走$j$步能消耗的最大的体力

显然$j$不可能超过$log_2{10^9}$，约等于$30$

转移方程也很简单

假如有一条边是$u\to v$，这条边权值为$d$

那么就有$f_{u,i}=max(f_{u,i},(f_{v,i-1}+1)*d-1);$

（稍微推一下就出来了）

然后查询即可

## Code

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 100, M = 998244353, INF = 1e9 + 10;
ll n, m, q, num, fi[N], to[N], ne[N], f[N][33], w[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void add(ll u, ll v, ll d) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
	w[num] = d;
}
ll calc(ll v, ll t, ll d) {
	ll ans = (f[v][t] + 1) * d - 1;
	return ans;
}
int main() {
	n = read(), m = read(), q = read();
	for(int i = 1; i <= m; i++) {
		ll u = read(), v = read(), d = read();
		add(u, v, d);
	}
	for(int i = 1; i <= 31; i++) {
		for(int u = 1; u <= n; u++) {
			for(int j = fi[u]; j; j = ne[j]) {
				ll v = to[j], d = w[j];
				f[u][i] = max(f[u][i], calc(v, i - 1, d));
			}
		}
	}
	for(int i = 1; i <= q; i++) {
		int p = read(), x = read();
		ll ans = 0;
		for(int j = 0; j <= 31; j++) {
			if(f[p][j] >= x) { //找到最少的边，保存后退出
				ans = j;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
```

