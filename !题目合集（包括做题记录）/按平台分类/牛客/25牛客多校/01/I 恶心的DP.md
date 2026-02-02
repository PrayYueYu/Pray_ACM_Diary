# Problem I. 铁棒切割

赛场上只有100队做出来，足以见证它的恶心程度

超恶心的$dp$

## Solution

首先题目一眼$dp$

像这种$dp$一般都是从小范围到大范围，即状态转移从小范围转到大范围

假设$f[l][r][m]$是切到$[l,r]$区域切割为$[l,m]\&[m+1,r]$之后切割完的最小代价

显然$f[l][r][m]=f[l][m]+f[m+1][r]+cost(l,r,m)$（$cost(l,r,m)$表示在$[l,m]$区间的$m$处切开的代价，$m\in [l,r)$）

**重点：必须满足平衡度条件，并且只要满足平衡度条件那最后一定能找到合适的切割顺序**

这样做时间复杂度是$O(n^4)$，显然不行

发现$f[l][r][m]$似乎可以预处理

$g[l][r][m].b$表示平衡度，$g[l][r][m].ct$表示$cost$

那么把$g[l][r]$按照$b$从小到大排序，之后$g[l][r][m].ct$表示$b$从小到大的时候$cost$的最小值（前缀最小值）

更新答案的时候，比如$g[l][r][m].ct$

那么只需要找到$g[l][m][l\to (m-1)].b<=g[l][r][m].b$中$g[l][m][l\to (m-1)].ct$最小的即可（**因为已经取了前缀最小值，所以最后一个$<=g[l][r][m].b$的$g[l][m][x].b$对应的$g[l][m][x].ct$一定是最小值**）

时间复杂度$O(n^3log(n))$，注意一下常数即可通过

## Code

```c++
#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 425, M = 998244353, INF = 1e14;
int sum[N], a[N];
int n, p2[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int solve(int x, int y, int z) {
	return abs(2 * sum[z] - sum[x - 1] - sum[y]);
}
int lgx(int x) {
	int s = log2(x);
	if(x == p2[s]) return s;
	return s + 1;
}
int calc(int x, int y, int z) {
	int s1 = sum[z] - sum[x - 1];
	int s2 = sum[y] - sum[z];
	int ans1 = min(s1, s2);
	int ans2 = lgx(s1 + s2);
	return ans1 * ans2;
}
struct P {
	int b, ct;
} g[N][N][N];
bool cmp (P x, P y) {
	return x.b < y.b;
}
void init() {
	sum[1] = a[1];
	for(int i = 2; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for(int i = 0; i <= 62; i++) {
		p2[i] = pow(2, i);
	}
}
int Find(int l, int r, int bc) {
	int s = INF;
	P *ft = g[l][r] + 1;
	P *lt = g[l][r] + (r - l) + 1;
	P now{bc, 0};
	P *it = upper_bound(ft, lt, now, cmp);
	if(it == ft) s = INF;
	else {
		--it;
		s = (*it).ct;
	}
	if(l == r) s = 0;		
	return s;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = read();
	while(T--) {
		n = read();
		for(int i = 1; i <= n; i++) a[i] = read();
		init();
		for(int d = 1; d <= n - 1; d++) {
			for(int l = 1; l <= n - 1; l++) {
				int r = l + d; 
				if(r > n) break;
				if(d == 1) {
					g[l][r][1].ct = calc(l, r, l);
					g[l][r][1].b = solve(l, r, l);
					continue;
				}
				int cnt = 0;
				for(int m = l; m < r; m++) {
					int bc = solve(l, r, m);
					g[l][r][++cnt].b = bc;
					int s1, s2;
					s1 = s2 = INF;
					
					s1 = Find(l, m, bc);
					s2 = Find(m + 1, r, bc);
					
					if(s1 == INF || s2 == INF) {
						g[l][r][cnt].ct = INF;
						continue;
					}
				//	cout << s1 << " " << s2 << " ";
				//	cout << l << " " << r << " " << m << endl;
					g[l][r][cnt].ct = calc(l, r, m) + s1 + s2;
				}
				if(l == 1 && r == n) break;
				sort(g[l][r] + 1, g[l][r] + cnt + 1, cmp);
				g[l][r][0].ct = INF;
				for(int p = 1; p <= cnt; p++) {
					int tx = g[l][r][p].ct;
					g[l][r][p].ct = min(tx, g[l][r][p - 1].ct);
				}
			}
		}
		for(int i = 1; i < n; i++) {
			if(g[1][n][i].ct == INF) cout << -1 << " ";
			else cout << g[1][n][i].ct << " ";
		}
		cout << "\n";
	}

	return 0;
}
//月雩·薇嫭 
```

