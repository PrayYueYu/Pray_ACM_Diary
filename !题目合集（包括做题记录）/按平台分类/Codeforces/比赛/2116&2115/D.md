# Gellyfish and Camellia Japonica

题目地址：[Gellyfish and Camellia Japonica](https://codeforces.com/contest/2116/problem/D)

## Solution

千万不要想复杂了！

显然能想到一步一步推回去

如何推？

令$a[i]$为第$i$个数最小为多少

对于某一步，假设完成转移后的状态为$a[x]<=a[z]$

那么转移前$a[x]=a[z]$，因为$a[z]=min(a[x],a[y])<=a[x]$

所以$a[x]$最小为$a[z]$（$a[y]$同理）

若转移后$a[x]>a[z]$则不需要改变（同时也不需要判断是否$a[x]$和$a[y]$是否满足条件，后续会检验）

同时$a[z]$赋值为多少都行，所以赋值为最小的$0$，以免造成影响

### 注意

$a[z]=0$要放在$a[x]$和$a[y]$赋值前面，因为有可能$z==x||z==y$，这个时候就需要考虑顺序问题

最后检验一下是否满足条件即可

## Code

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 3e5 + 100, M = 998244353, INF = 1e9 + 10;
int n, a[N], ans[N], b[N], q, r[N][5];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int main() {
	int T = read();
	while(T--) {
		n = read(), q = read();
		for(int i = 1; i <= n; i++) a[i] = b[i] = read();
		for(int i = 1; i <= q; i++) 
			for(int j = 1; j <= 3; j++) r[i][j] = read();
		bool F = true;
		for(int i = q; i >= 1; i--) {
			int x = r[i][1], y = r[i][2], z = r[i][3];
			int t = a[z];
			a[z] = 0;
			a[x] = max(a[x], t);
			a[y] = max(a[y], t);
		}
		for(int i = 1; i <= n; i++) ans[i] = a[i];
		for(int i = 1; i <= q; i++) {
			int x = r[i][1], y = r[i][2], z = r[i][3];
			a[z] = min(a[x], a[y]);
		}
		for(int i = 1; i <= n; i++) {
			if(a[i] != b[i]) {
				F = false;
				break;
			}
		}
		if(F) {
			for(int i = 1; i <= n; i++) cout << ans[i] << " ";
			cout << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}
```

