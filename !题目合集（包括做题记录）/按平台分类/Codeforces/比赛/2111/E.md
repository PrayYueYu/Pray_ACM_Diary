# Changing the String

题目地址：[Changing the String](https://codeforces.com/contest/2111/problem/E)

## Solution

其实挺简单，理清逻辑就行

主要是比赛的时候时间太紧了，紧张。。

逻辑就不用讲了

主要有两个点

1. 若要实行$'b'->'c'$然后$'c'->'a'$要注意必须是第一步先出现然后出现第二步
2. $'c'->'b'$可以在最后单独使用
3. 用$set$好操作（不过也可以不同$set$）

## Code

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 3e5 + 100, M = 998244353, INF = 1e9 + 10;
int n, q;
string s;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int change(char x, char y) {
	if(x == 'b' && y == 'a') return 1;
	if(x == 'c' && y == 'a') return 2;
	if(x == 'b' && y == 'c') return 3;
	if(x == 'c' && y == 'b') return 4;
	return 0;
}
struct cmp {
	bool operator()(int x, int y) {
		return x < y; 
	}
};
set<int, cmp> p[6];
int main() {
	int T = read();
	while(T--) {
		n = read(); q = read();
		getline(cin, s);
		s = " " + s;
		for(int i = 1; i <= 4; i++) p[i].clear();
		for(int i = 1; i <= q; i++) {
			char x, y; cin >> x >> y;
			if(x == y) continue;
			if(x == 'a') continue;
			int t = change(x, y);
			p[t].insert(i);
		}
		
		for(int i = 1; i <= n; i++) {
			if(s[i] == 'a') continue;
			int t = change(s[i], 'a');
			if(p[t].size()) {
				p[t].erase(p[t].begin()); 
				s[i] = 'a';
				continue;
			}
			char x = s[i], y = 'b';
			if(x == 'b') y = 'c';
			int t1 = change(x, y); int t2 = change(y, 'a');
			if(p[t1].size() && p[t2].size()) {
				auto it1 = p[t1].begin();
				auto it2 = p[t2].upper_bound(*it1);
				if(it2 != p[t2].end()) {
					p[t2].erase(it2);
					p[t1].erase(it1);
					s[i] = 'a';
					continue;
				}
			}
			t = change(x, 'b');
			if(s[i] == 'c' && p[t].size()) {
				s[i] = 'b';
				p[t].erase(p[t].begin());
				continue;
			}
		}
		for(int i = 1; i <= n; i++) cout << s[i];
		cout << endl;
	}
	return 0;
}
```

