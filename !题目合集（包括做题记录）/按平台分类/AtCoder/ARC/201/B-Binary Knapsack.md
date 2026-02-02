# **B - Binary Knapsack**

**题目地址：**[**Binary Knapsack**](https://atcoder.jp/contests/arc201/tasks/arc201_b)

第一次打$ARC$，自闭了。

首先想一个问题，假设能取满$W$，那一定取满价值才最大吗？

显然不对

那我们怎么优化这个思路？

$i$从$0\to 59$，假设$!(W>>i)\&1$（$W$在这一位上为$0$），那么我们该不该选择重量为$2^i$中价值最大的这个数$v_i$呢？

这个时候我们发现，假如重量为$2^i$的物品不止一个，那么我们显然可以把这两个物品合并成一个，变成一个重量为$2^{i+1}$，价值为$v_i+v_j$的物品。假设$(W>>(i+1))\&1$（$W$在$i+1$位上为$1$），那么可以发现，如果在$i$位取了$v_i$，显然$i+1$位就不能取别的，因为肯定会超过$W$。由此可以推到整个过程

只在$(W>>i)\&1$的地方取物品。没有被取的物品就和别的物品合并

最后能保证最后总重量一定小于等于$W$，且能使得价值最大

## Code

**注意$vector$的用法**

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 100, M = 1e9 + 7, CN = 1e6 + 10;
ll n;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
vector<vector<ll>> s;
int main() {
	int T = read();
	while(T--) {
		s.resize(70);
		n = read(); ll w = read();
		for(int i = 0; i <= 59; i++) {
			if(s[i].size()) s[i].clear();
		}
		for(int i = 1; i <= n; i++) {
			ll x = read(), y = read();
			s[x].push_back(y);
		}
		ll ans = 0;
		for(int i = 0; i <= 59; i++) {
			if(!s[i].size()) continue;
			sort(s[i].begin(), s[i].end());
			int st = s[i].size() - 1;
			if((w >> i) & 1) {
				ans += s[i][st];
				st--;
			}
			for(int j = st; j >= 0; j -= 2) {
				ll num = s[i][j];
				if(j != 0) num += s[i][j - 1];
				s[i + 1].push_back(num);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
//月雩·薇嫭 
```

