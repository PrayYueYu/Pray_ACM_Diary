# [Mary 有棵有根树](https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1248)

## Description

（链接为中文题面）

![image](https://img2024.cnblogs.com/blog/2372298/202403/2372298-20240319155052529-918946289.png)

## Input

输入仅一行，包括两个由单个空格隔开的正整数 M，K，表示从一个结点上可以长出的子结点的数量，以及使用闪耀魔法的次数。保证 1≤M≤100，1≤K≤107。

## Output

输出一个数，表示 Mary 的有根树的结点深度和的期望。假设期望深度和化为最简分式后的形式为 p/q（即其中 p,q 互质），请输出非负整数 x 使得 qx≡p(mod1,000,000,009)，且 0≤x<1,000,000,009。可以证明，在本题数据范围下，x 存在且唯一。

## solution

经验题吧。注意到每个点被选择的概率相同，且每次能选的数量也相同，那么只需要知道平均深度就能求出来下一次被选择的深度。需要注意的是Mod=1e9+9不是1e9+7 emmm

## Code

```c++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 1e9 + 9;
ll m, k;
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

int main() {
    m = read(), k = read();
    ll num = 0, D = 0, aveD = 0, ans = 0;
    //num：可用点个数
    //D：总深度
    //ans：答案
    //aveD = D / num = D * Inv[num]：平均深度
    for(int i = 1; i <= k; i++) {
    	num = 1 + (i - 1) * (m - 1);
    	aveD = (D * ksm(num, M - 2)) % M;//快速幂求Inv[num]
    	ans = (ans + (aveD + 1) * m) % M;
    	D = D + (aveD + 1) * m; D %= M;
		D = (D - aveD + M) % M; //需要减去选择的点，深度为aveD
	}
	cout << ans;
    return 0;
}
```

