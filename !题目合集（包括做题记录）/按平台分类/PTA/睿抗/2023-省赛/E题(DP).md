# **RC-u5 相对成功与相对失败**

**题目地址：**[**RC-u5 相对成功与相对失败**](https://pintia.cn/problem-sets/1680597991209951232/exam/problems/type/7?problemSetProblemId=1680598077168017412)

## Solution

挺有意思一道题

首先把所有人分类

“参加了&不玩手机”=第1等级

“参加了&玩手机 or 没参加&不玩手机”=第2等级

“没参加&玩手机”=第3等级

转换一下条件可知，题目要求的是：

按照给定的顺序，选手的等级应当递增

比如给定的选手排名顺序为$1\ 3\ 4\ 2$

那么按照这个顺序，选手对应的等级应当递增才行，比如为$1\ 1\ 2\ 3$

这样一来第3名选手等级就为1，以此类推

我们先按照题目给的等级放到这个排名中，如果满足升序则答案为零

如果不满足，那么把连续的一段相同等级合并，假设合并后一共$cnt$段

假设$f_{i,j=1/2/3}$表示第$i$段以等级$j$结尾，需要改变的最小人数

那么$f_{i,1}=f_{i-1,1}+check(i,1)$

$f_{i,2}=min(f_{i-1,1},f_{i-1,2})+check(i,2)$

$f_{i,3}=min(f_{i-1,1},f_{i-1,2},f_{i-1,3})+check(i,3)$

其中$check(i,j)$表示判断把第$i$段全部改成等级$j$需要改变多少人

## Code

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 100, M = 998244353, INF = 1e9 + 10, Nx = 1e5;
int n, w[N][3], a[N], b[N], vis[N], num[N], f[N][4];
string Str[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int check(int x, int y) {
	if(vis[x] == y) return 0;
	return num[x];
}
int main() {
	int T = read();
	while(T--) {
		n = read();
		for(int i = 1; i <= n; i++) {
			w[i][1] = read(), w[i][2] = read();
			w[i][2] = 1 - w[i][2];
			if(w[i][1] == 1 && w[i][2] == 1) b[i] = 1;
			else if(w[i][1] == 0 && w[i][2] == 0) b[i] = 3;
			else b[i] = 2;
		}
		for(int i = 1; i <= n; i++) {
			a[i] = read();
			a[i] = b[a[i]];
		}
		a[n + 1] = -1;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				f[i][j] = INF;
			}
			vis[i] = num[i] = 0;
		}
		int l = 1, r = 1, cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i] != a[i + 1]) {
				vis[++cnt] = a[l];
				num[cnt] = r - l + 1;
				l = r = i + 1;
			}
			else r = i + 1;
		}
		f[0][1] = f[0][2] = f[0][3] = 0;
		for(int i = 1; i <= cnt; i++) {
			for(int j = 1; j <= 3; j++) {
				for(int k = 1; k <= j; k++) {
					f[i][j] = min(f[i][j], f[i - 1][k] + check(i, j));
				}
			}
		}
		int ans = INF;
		for(int i = 1; i <= 3; i++) ans = min(ans, f[cnt][i]);
		cout << ans;
		if(T) cout << endl;
	}
	return 0;
}
```



