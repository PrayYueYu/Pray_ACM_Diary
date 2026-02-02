# P12846 [蓝桥杯 2025 国 A] 翻转硬币

**题目地址：**[P12846 [蓝桥杯 2025 国 A] 翻转硬币](https://www.luogu.com.cn/problem/P12846)

## Solution

经过推论/经验可以发现，对于不是整个区间操作，而是区间内固定的隔$X$个改变一个，可以进行如下操作：

假如有$k$条规则，第$i$条规则为：从$L$开始，每隔$a_i$个改变一个（$L,L+a_i,L+2*a_i...$）

那么：**将$i\%A$相同的划分为一组**，其中$A=lcm_{i=1}^{k}(a_i)$（$lcm$：最小公倍数）

在这道题，$A=6$，每次操作都需要根据下标$\%6$划分开

## Code

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e6 + 100, M = 998244352, M2 = 998244353;
int n, m, tr[N][6], s[N][6], a[N], tr_num[N][6];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void build(int l, int r, int p) {//建树
	if(l == r) {
		tr[p][l % 6] = a[l];
		tr_num[p][l % 6]++;//每个区间的长度
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, p * 2);
	build(mid + 1, r, p * 2 + 1);
	for(int i = 0; i <= 5; i++) {//每次修改6个区间都要改
		tr[p][i] = tr[p * 2][i] + tr[p * 2 + 1][i];
		tr_num[p][i] = tr_num[p * 2][i] + tr_num[p * 2 + 1][i];
	}
}
int getf(int t, int op, int L, int R) { //寻找指定区间内第一个可以修改的下标位置
	int f = L, fx = t % op;
	while(true) {
		if(f % op == fx) break;
		f++;
	}
	return f;
}
void Lazy(int l, int r, int i, int p, int c) {
	if(!c) return;
	tr[p][i] = tr_num[p][i] - tr[p][i];
	s[p][i] ^= c;
}
void pushdown(int l, int r, int p) {//pushdown对于0~5即所有区间都要修改！因为是向下传递，所有都要修改
	int mid = (l + r) >> 1;
	for(int i = 0; i <= 5; i++) {
		Lazy(l, mid, i, p * 2, s[p][i]);
		Lazy(mid + 1, r, i, p * 2 + 1, s[p][i]);
		s[p][i] = 0;
	}
}
void update(int l, int r, int lx, int rx, int op, int p) {
	if(rx < l || lx > r) return;
	if(lx <= l && r <= rx) {
		int f = getf(lx, op, l, r);
		for(int i = 1; i <= 6 / op; i++) {//修改的时候注意有多处需要修改，一一找出来并修改
			Lazy(l, r, f % 6, p, 1);
			f += op;
		}
		return;
	}
	pushdown(l, r, p);
	int mid = (l + r) >> 1;
	update(l, mid, lx, rx, op, p * 2);
	update(mid + 1, r, lx, rx, op, p * 2 + 1);
	for(int i = 0; i <= 5; i++) {
		tr[p][i] = tr[p * 2][i] + tr[p * 2 + 1][i];
	}
}
int query(int l, int r, int lx, int rx, int p) {
	if(rx < l || lx > r) return 0;
	if(lx <= l && r <= rx) {
		int sum = 0;
		for(int i = 0; i <= 5; i++) sum += tr[p][i];
		return sum;
	}
	pushdown(l, r, p);
	int ans = 0, mid = (l + r) >> 1;
	ans += query(l, mid, lx, rx, p * 2);
	ans += query(mid + 1, r, lx, rx, p * 2 + 1);
	return ans;
}
int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	build(1, n, 1);
	for(int i = 1; i <= m; i++) {
		int op = read(), l = read(), r = read();
		if(op == 1) update(1, n, l, r, 2, 1);
		if(op == 2) update(1, n, l, r, 3, 1);
		if(op == 3) update(1, n, l, r, 1, 1);
		if(op == 4) cout << query(1, n, l, r, 1) << endl;
	}
	return 0;
}
//月雩·薇嫭
```

