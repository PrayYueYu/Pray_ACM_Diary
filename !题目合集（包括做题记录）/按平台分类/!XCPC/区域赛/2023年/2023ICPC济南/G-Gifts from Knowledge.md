# Gifts from Knowledge

**题目地址：**[Gifts from Knowledge](https://codeforces.com/gym/104901/problem/G)

## Solution

见$各类算法\to巧思\&方法\&特殊题目\to 01染色问题$

## Code

```c++
#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 2e6 + 10, M = 1e9 + 7, INF = 1e18;
int fa[N], n, num[N], m, p[N][3];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void init() {
	for(int i = 0; i <= max(n, m) * 2 + 5; i++) {
		fa[i] = i;
		num[i] = 0;
		p[i][1] = p[i][2] = 0;
	}
}
int GetFa(int x) {
	return x == fa[x]? x: fa[x] = GetFa(fa[x]);
}
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % M;
		x = (x * x) % M;
		y >>= 1;
	}
	return ans;
}
void merge(int x, int y) {
	int fax = GetFa(x), fay = GetFa(y);
	if(fax != fay) {
		fa[fax] = fay;
	}
}
signed main() {
	int T = read();
	while(T--) {
		n = read(), m = read();
		init();
		int f = true;
		for(int i = 1; i <= n; i++) {
			string s = "";
			cin >> s;
			s = " " + s;
			for(int j = 1; j <= m; j++) {
				if(s[j] == '0') continue;
				int x = j, y = m + 1 - j;
				if(num[x] + num[y] == 2) {
					f = false;
					break;
				}
				p[x][++num[x]] = i;
			}
		}
		for(int i = 1; i <= m; i++) {
			int x = i, y = m + 1 - i;
			if(x > y) break;
			if(x == y) {
				if(num[x] >= 2) {
					f = false;
					break;
				}
				continue;
			}
			if(num[x] + num[y] != 2) continue;
			if(num[x] == num[y]) {
				int u = p[x][1];
				int v = p[y][1];
				merge(u, v);
				merge(u + n, v + n);
			}
			else {
				int u = 0, v = 0;
				if(num[x]) {
					u = p[x][1];
					v = p[x][2];
				}
				else {
					u = p[y][1];
					v = p[y][2];
				}
				merge(u, v + n);
				merge(u + n, v);
			}
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			int f1 = GetFa(i), f2 = GetFa(i + n);
			if(f1 == f2) f = false;
			if(f1 == i) cnt++;
			if(f2 == i + n) cnt++;
		}
		if(!f) {
			cout << 0 << endl;
			continue;
		}
		cout << ksm(2, cnt / 2) << endl;
	}
	return 0;
}
//月雩·薇嫭 
/*

*/
```

