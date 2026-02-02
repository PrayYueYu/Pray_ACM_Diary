#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, M = 1e6 + 9;
int n, fa[N][5000], qx, vis[5000], px[20];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
vector<int> p[5000];
queue<int> q;
int getfa(int x, int w) {
	if(fa[x][w] == x) return x;
	return fa[x][w] = getfa(fa[x][w], w);
}
bool merge(int u, int v, int w) {
	int fau = getfa(u, w), fav = getfa(v, w);
	if(fau == fav) return true;
	fa[fau][w] = fav;
	return false;
}
void solve() {
	n = read(), qx = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < (1 << 12); j++) {
			fa[i][j] = i;
		}
	}
	for(int i = 0; i < (1 << 12); i++) vis[i] = false;
	long long ans = 0;
	for(int i = 1; i <= qx; i++) {
		char c; cin >> c;
		if(c == '+') {
			int u = read(), v = read(), w = read();
			if(merge(u, v, w)) continue;
			for(auto x: p[w]) q.push(x);
			while(!q.empty()) {
				int x = q.front(); q.pop();
				vis[x] = i;
				if(merge(u, v, x)) continue;
				for(auto y: p[x]) {
					if(vis[y] == i) continue;
					q.push(y);
				}
			}
			//每个答案开一个并查集
			//每次更新即可
			//假设w=10110(2)
			//那么显然对于10010、10100、10000等也需要更新
			//（去掉一些1） 
			//每次更新最多2^12-1次
			//剪枝：如果merge=1，说明已经在一个并查集，continue 
		}
		else {
			int u = read(), v = read();
			int fau0 = getfa(u, 0), fav0 = getfa(v, 0);
			if(fau0 != fav0) {
				ans--;
				continue;
			}
			int now = 0;
			for(int i = 11; i >= 0; i--) {
				int fau = getfa(u, now + px[i]);
				int fav = getfa(v, now + px[i]);
				if(fau == fav) now += px[i];
			}
			//贪心的找
			//如果答案now=\sum_{i=1}^{n} 2^pi (p1>p2>...>pn)
			//那么对于前缀\sum_{i=1}^{k<=n} 一定也在一个并查集 
			ans += now;
		}
	}
	cout << ans << '\n';
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	for(int i = 0; i < 12; i++) px[i] = (1 << i);
	for(int i = 0; i < (1 << 12); i++) {
		for(int j = 0; j <= 12; j++) {
			if((i >> j & 1)) {
				p[i].push_back(i - (1 << j));
			}
		}
	}
	int T = read();
	while(T--) solve();
    return 0;
}
/*
2
4 11
+ 1 3 6
+ 3 4 2
? 1 4
+ 1 4 3
? 4 1
+ 4 3 4
? 1 4
+ 3 2 3
? 1 2
+ 1 1 4
? 1 3
4 4
+ 1 2 64
+ 3 4 32
? 1 2
? 3 1
*/
