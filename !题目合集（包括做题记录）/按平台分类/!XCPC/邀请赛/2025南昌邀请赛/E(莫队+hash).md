# God's String on This Wonderful World

**题目地址：**[God's String on This Wonderful World](https://codeforces.com/gym/105911/problem/E)

## Solution

发现是区间题，并且难以想到$dp$方法

考虑用莫队

考虑转移方程

首先改变一下题目条件

显然如果$S_{L,R}=t^k$那么$S_{L,R}$中所有字母出现的次数必定是$k$的倍数

即：$(ar[R][a$ ~$z]$-$ar[L-1][a$ ~$z])\%k=0$

即：$ar[R] \equiv ar[L - 1] (mod k)$

（**假设我们把$ar[i][a-z]$压缩为一个$Hash$，那么就变为$ar[i]$**）

（用$map$储存每一种$ Hash$，并编号，令$a[i]=mp[ar[i]]$，即$1-i$字符串经过处理的$hash$编号）

（**注意储存数量的时候每次都$\ \%k$，这样就能使得条件变为$a[R]=a[L-1]$**）

那么题目即变为寻找在区间$[L,R]$中有多少对$[l,r]$满足$a[r]=a[l-1]$

对每一个不同的$Hash$进行编号即可优化，进一步变为寻找区间$[L,R]$内相同的数的数量

假设从$[l,r]$变到$[l,r+1]$，假设$num[r+1][s[r+1]]=x$，原本$x$出现了$cnt$次，那么新增答案数为$cnt$（因为$[t,r+1]$可以有$cnt$对）

其他变换都差不多

需要注意的是**初始化**

因为是求的是$l-1$而不是$l$，所以$i=0$的地方也要注意

$i=0$的时候令$a[0]=1,\ mp[ar]=1$（注意此时$ar$是空的，即全为零）

## Code

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 3e5 + 100, M = 998244353, INF = 1e9 + 10;
ll cnt, n, q, k, a[N], vis[N], ansx, num[N], ans[N];
string s;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct Mo {
	ll l, r, id;
} w[N];
array<ll, 30> ar;
map<array<ll, 30>, ll> mp;
bool cmp(Mo x, Mo y) {
	if(vis[x.l] == vis[y.l])
		return vis[x.r] < vis[y.r];
	return vis[x.l] < vis[y.l];
}
void add(ll x) {
	ansx += num[a[x]];
	num[a[x]]++;
}
void sub(ll x) {
	num[a[x]]--;
	ansx -= num[a[x]];
}
int main() {
	n = read(); k = read(), q = read();
	getline(cin, s);
	s = " " + s;
	mp[ar] = ++cnt;
	ll Len = sqrt(min(n, q)), L = 0, R = 0, t = 0;
	while(true) {
		t++;
		L = R + 1;
		R = min(L + Len - 1, n);
		for(int i = L; i <= R; i++) vis[i] = t;
		if(R == n) break;
	}
	
	for(int i = 1; i <= n; i++) {
		ar[s[i] - 'a']++;
		ar[s[i] - 'a'] %= k;
		if(!mp[ar]) mp[ar] = ++cnt;
		a[i] = mp[ar];
	}
	a[0] = 1;
	for(int i = 1; i <= q; i++) {
		w[i].l = read();
		w[i].r = read();
		w[i].id = i;
	}
	sort(w + 1, w + q + 1, cmp);
	ll l = 1, r = 0;
	for(int i = 1; i <= q; i++) {
		w[i].l--;//注意减1
		while(l < w[i].l) sub(l++);
		while(l > w[i].l) add(--l);
		while(r < w[i].r) add(++r);
		while(r > w[i].r) sub(r--);
		ans[w[i].id] = ansx;
	}
	for(int i = 1; i <= q; i++) cout << ans[i] << endl;
	return 0;
}
```

## 小结

预估这道题难道在2600-2800，算是准金牌题难度了

难度主要在转移上，后面可以多练习这类题