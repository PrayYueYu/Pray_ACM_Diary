# Make a Palindrome

**题目地址：**[Make a Palindrome](https://codeforces.com/contest/2124/problem/D)

## Solution

发现$k-1$小的数必定全部会被留下

将原序列从小到大排序之后得到数列$b$

不妨猜测如果能找到一个回文串，那必定能找到一个长度$>=k-1$且只用$<=b[k-1]$（即前$k-1$小的数字）大小的数字构成

### Proof

假设经过若干次操作能得到一个长度为$Len>=k$的回文

那么必定能通过对称操作得到一个长度为$k$或者$k-1$的回文

（即选择全区间，那么必定能删除两个最大的数字，且能保证这两个数字中心对称，这样一来就能得到更小的回文）

$a.$ 如果长度为$k-1$，那已经满足条件了，这$k-1$个数字必定满足条件

$b.$ 如果长度为$k$

$I.$ 假如最大的那个数字是单个，那这个数字必定在中心点，选择全区间就能直接删除

$II.$假如最大的那个数字个数$>=2$，那已经满足条件了（这$k$个数字必定都$<=b[k-1]$，因为最大那个占了两个）



那么接下来只需要找到这些数字能否构成回文即可

对于$<b[k-1]$的数字必须两两配对，对于$=b[k-1]$的可以选择性的不匹配，但必须保证最后总数$>=k-1$

如果$<b[k-1]$的有不匹配的，那就不存在

考虑用双指针匹配

## Code

```c++
#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 2e5 + 100, mod = 998244353, INF = 1e14;
int n, a[N], b[N], c[N], k;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
signed main() {
	int T = read();
	while(T--) {
		n = read(); k = read(); int cnt = 0;
		for(int i = 1; i <= n; i++) {
			a[i] = read();
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1);
		for(int i = 1; i <= n; i++) {
			if(a[i] <= b[k - 1]) c[++cnt] = a[i];
		}
		int l = 1, r = cnt, F = true, num = 0;
		while(true) {
			if(l >= r) break;
			if(c[l] == c[r]) {
				l++, r--;
				continue;
			}
			if(c[l] != b[k - 1] && c[r] != b[k - 1]) {
				F = false;
				break;
			}
			if(c[l] == b[k - 1]) {
				l++;
				num++; 
			}
			else {
				r--;
				num++;
			}
		}
		if(!F) {
			cout << "NO\n";
			continue;
		}
		if(cnt - num >= k - 1) {
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	} 
	return 0;
}
//月雩·薇嫭 
```

