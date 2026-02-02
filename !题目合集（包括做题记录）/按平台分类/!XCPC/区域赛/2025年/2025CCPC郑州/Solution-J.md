# 25$CCPC$郑州 J. 子矩形计数

## Solution

可以发现$x$一定是偶数，因为$x\oplus (x+1)\oplus (x+2)\oplus (x+3)=0$

那么很显然有$x\oplus (x+1)=1$，所以$b_j\oplus b_{j+1}=1$

那么我们可以先找到满足条件的$j$

假设现在有一个满足条件的$i$，假设$x=a_i\oplus b_j$

那么可以发现，有以下结论：$a_i\oplus a_{i+1}=(x+2)\oplus x$

可以发现对于任意偶数$e$，$(e+2)\oplus e$的值只会有不超过$30$个

具体来说，假设$e=...01110_2$，从第一位开始的连续的$1$长度为$3$，那么$(e+2)\oplus e=2^{5}-2$

推广来说，假设$e=...01...10_2$，从第一位开始连续的$1$长度为$len$，那么$(e+2)\oplus e=2^{len+2}-2$



假设当前找到了一个满足条件的$b_j$，那么该怎么做呢？一个很显然的做法就是枚举$x$二进制下的后缀

假设$x$二进制下的后缀是$...01...10_2$，连续$1$长度为$len$，并且令$s=(x+2)\oplus x=2^{len+2}-2$

那么令$now=x\oplus b_j$，取其二进制下从$0$到$len+1$位，找到数组$a$中，满足以下条件$i$的数量：

1. $a_i\oplus a_{i+1}=s$
2. $a_i$二进制下从$0$到$len+1$位和$now$二进制下从$0$到$len+1$​位相同

答案加上这个数量即可

## Code

```c++
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], b[N], bn[100], p[100], px[100];
int read() {
	int x;
	cin >> x;
	return x;
}
map<int, int> mp[40], vis;
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) b[i] = read();
	
	for(int i = 0; i <= 30; i++) mp[i].clear();
	for(int i = 1; i < n; i++) {
		int t = a[i] ^ a[i + 1], id = vis[t];
		if(!id) continue; 
		id--;
		int now = a[i] & px[id];//取0~len+1位 
		mp[id][now]++;
	}
	int ans = 0;
	for(int i = 1; i < m; i++) {
		if((b[i] ^ b[i + 1]) == 1) {
			for(int j = 0; j <= 30; j++) {//枚举len 
				int x = b[i] ^ bn[j];//枚举后缀，并异或
				int now = x & px[j];//只需要0~len+1，取0~len+1位 
				ans += mp[j][now];//加上答案
			}
		}
	}
	cout << ans << '\n';
}
signed main() {
	bn[0] = 0; int r = 2; p[0] = 1;
	vis[2] = 1; px[0] = 3;
	for(int i = 1; i <= 30; i++) {
		bn[i] = bn[i - 1] + (1ll << i);
		r = r * 2 + 2;
		p[i] = p[i - 1] * 2;
		vis[r] = i + 1;
		px[i] = px[i - 1] + (1ll << (i + 1));
	}
    //bn：枚举的x后缀
    //r: 记录 2^{len+2}-2
    //vis：标记 r 以及对应的 len
    //px：用&操作加速，x&px[i]代表只取其0~i+1位
    int T = read();
    while(T--) solve();
    return 0;
}
/*

*/
```



