# [有限小数](https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1361)

## Description

给定两个互质正整数 a,b，你需要求两个非负整数 c,d，满足以下两个条件：

- $\frac{a}{b}+\frac{c}{d}$ 为十进制下的整数或有限小数。
- 1≤d≤$10^9$。

在所有满足条件的非负整数对 (c,d) 中，请求出 c 最小的一对。

## Input

从标准输入读入数据。

第一行包含一个正整数 T (1≤T≤$10^4$)，表示数据组数。

每组数据包含一行两个正整数 a,b (1≤a≤b≤$10^6$)，含义如题目描述所示。保证 $gcd(a,b)=1$。

## Output

输出到标准输出。

对于每组数据，输出一行两个非负整数 c,d。如果有多组正确答案，输出任意一组即可。

## Solution

根据高中所学，一个分数$\frac{a}{b}$若能变成有限小数，那么必定它的分母$b=2^x*5^y$

那么把$b$写为$b=t_1*B$，其中$t1=2^{x_1}*5^{y_1}，B=b/t_1$

**猜一手$d=t_2*B$，其中$t_2=2^{x_2}*5^{y_2}$**（凭直觉emmm）

那么原式等于$\frac{a*t_2+c*t_1}{B*t_1*t_2}$

那么只需要保证$(a*t_2+c*t_1)\%B=0$即可，其中$a, t1$已知

由于$d\le10^9$，那么必定有$t_2\le10^9$

那么显然可以枚举$t_2$，枚举的时间与空间复杂度为$O(2log_n)$

假设$x=a*t_2$ ，$y=c$ ， $b1=t1$，  $Mod=B$（为了和代码同步这里用了$b$，注意和最开始的$b$区分开）

那么问题就变成了**找到最小的y使得$(x+y*b1) \equiv0(mod\ Mod)$**

那么可以写为：$y*b1 \equiv -x(mod\ Mod)$

两边同时乘以$b1^{-1}$可得：$y\equiv -x*b1^{-1}(mod\ Mod)$

所以$c=min(y)=min(((-x*b1^{-1})\%Mod+Mod)\%Mod)$

其中 $b1^{-1}$用$ExGCD$求（$b1$的逆元）

总时间复杂度：$O(T*2log_n*log_b)$

**注意范围：c和d>=1，除非$B=1$ ($B=1$时$c=0,d=1$)**

## Code

```c++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 10, M = 10, P = 1331;
ll vis[N], num;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
ll Split(ll x) {
	ll ans = 1;
	while(true) {
		if(x % 2 == 0) ans *= 2, x /= 2;
		else break;
	}
	while(true) {
		if(x % 5 == 0) ans *= 5, x /= 5;
		else break;
	}
	return ans;
}
void Pre() {
	for(int i = 0; i >= 0; i++) {
		if(pow(2, i) > 1e9) break;
		for(int j = 0; j >= 0; j++) {
			ll t1 = pow(2, i), t2 = pow(5, j);
			ll t = t1 * t2;
			if(t1 * t2 > 1e9) break;
			vis[++num] = t;
		}
	}
	sort(vis + 1, vis + num + 1);
}
void ExGcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    ll x1, y1;
    ExGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}
ll GetInv(ll a, ll b) {
	ll x, y;
	ExGcd(a, b, x, y);
	if(x < 0) x = x + b;
	return x; 
}
void Solve(ll a, ll b, ll Mod) {
	ll ansy = 1e9, ansx = 0;
	for(int i = 1; i <= num; i++) {//枚举t_2
		ll x = vis[i] * a, ck = vis[i] * Mod;
        //vis[i]为t_2，x=t_2*a
		if(ck > 1e9) break; //ck为d，d<=1e9
		ll Inv = GetInv(b, Mod); //求逆元
		ll y = ((-x * Inv) % Mod + Mod) % Mod;
		if(!y) continue;
		if(ansy > y) {//求最小的y
			ansy = y;
			ansx = ck;
		}
	}	
	cout << ansy << " " << ansx << endl;
}
int main() {
	int T = read();
	Pre(); //预处理t_2
	while(T--) {
		ll a = read(), b = read();
		ll t1 = Split(b), Mod = b / t1; //把b分为t1*B(B=Mod)
		if(Mod == 1) {//特判
			cout << "0 1\n";
			continue;
		}
		Solve(a, t1, Mod);//求答案
	}
    return 0;
}
```

