# **Flip to Gather**

题目链接：[**Flip to Gather**](https://atcoder.jp/contests/abc408/tasks/abc408_d)

## Solution

搞不懂，下午的时候随便调了一套题能做6道，结果一比赛只能做3道。。

这道虽然早就想到是DP，但是有点慌了没写出来

赛后想出来了

先把原字符串划分一下，每一段连续的0和1各分为一组，记录长度

记$intv[i]$为第$i$段的长度，显然$i$和$i - 2，i-4,...$都为0 or 1

当第$i$段为1的段的时候，设$f_{i,0/1}$表示以$i$结尾的，选取这个段为最后剩余的段和不选取情况下最少要花多少步才能满足条件（只剩一个连续为1的段）

对于选取，可以选择和前面一个为1的段连起来（连起来的话中间的0要全部变为1），也可以选择只保留自己（即前面的为1的段全改为0）

那么$f_{i,0}=min(f_{i-2,0}+intv[i-1],\ g_{i-2})$（$g_i$表示到$i$为止共有多少个1）

对于不选取，$f_{i,1}=min(f_{i-2,0},\ f_{i-2,1})+intv[i]$（自身的1全部变为0）

初始化需注意：对于第一个为1的段

$f_{i,0}=0,\ f_{i,1}=INF$（不可能一个段没有，所以为INF）

最后答案为最后一个为1的段的$min(f_0,\ f_1)$

## Code

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 100, M = 998244353, INF = 1e9 + 10;
int n, intv[N], vis[N], f[N][3], g[N];
string s;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int main() {
	int T = read();
	while(T--) {
		n = read();
		getline(cin, s);
		s = " " + s;
		int num = 0, cnt = 0, ansx = 0, num2 = 0;
		for(int i = 1; i <= n; i++) {
			f[i][0] = f[i][1] = g[i] = 0;
			if(s[i] == '1') {
				if(num2) {
					intv[++cnt] = num2;
					vis[cnt] = 0;
				}
				num++;
				num2 = 0;
			}
			else {
				if(num) {
					intv[++cnt] = num;
					vis[cnt] = 1;
				}
				num = 0;
				num2++;
			}
		}
		if(num) intv[++cnt] = num, vis[cnt] = 1;
		else if(num2) intv[++cnt] = num2, vis[cnt] = 0;//将0/1分组，分成一段一段的
        
		if(cnt <= 2) {
			cout << 0 << endl;
			continue;
		}//特判
		if(cnt == 3) {
			if(vis[1] == 0) {
				cout << 0 << endl;
				continue;
			}
		}//特判
        
		int F = false, Max = 0, sum = 0;
		for(int i = 1; i <= cnt; i++) {
			if(vis[i] == 0) continue;
			if(!F) {//初始化
				f[i][0] = 0;
				f[i][1] = INF;
				g[i] = intv[i];
				Max = intv[i]; 
				sum += intv[i];
				F = true;
			}
			else {
				f[i][0] = min(f[i - 2][0] + intv[i - 1], g[i - 2]);
				f[i][1] = min(f[i - 2][1], f[i - 2][0]) + intv[i];
				g[i] = g[i - 2] + intv[i];
			}
		}
		if(vis[cnt]) cout << min(f[cnt][0], f[cnt][1]) << endl;
		else cout << min(f[cnt - 1][0], f[cnt - 1][1]) << endl;
	}
	return 0;
}
```

