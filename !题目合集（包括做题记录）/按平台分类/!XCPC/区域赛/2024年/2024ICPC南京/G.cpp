#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100, INF = 1e16;
int n, ne[N], to[N], fi[N], num;
int idx, idu, f, sz[N], vis[N];
int asku, askv, resn;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void add(int u, int v) {
	num++;
	if(!u || !v) return;
	ne[num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void init(int u, int fa) {
	sz[u] = 1;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		if(vis[i]) continue;
		init(v, u);
		sz[u] += sz[v];
	}
}
void dfs(int u, int fa) {
	if(f) return;
	int cnt = 0, vx = 0;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(vis[i]) continue;
		cnt++; vx = v;
	}
	if(f) return;
	if(cnt == 1) {
		sz[u] -= sz[vx];
		sz[vx] += sz[u];
		dfs(vx, u);
		if(f) return;
		sz[vx] -= sz[u];
		sz[u] += sz[vx];
		return;
	}
	int Max = -INF;
	int idy = 0;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(vis[i]) continue;
		if(Max < sz[v]) {
			Max = sz[v];
			idy = v;
		}
	}
	if(Max <= resn / 2) {
		idu = u;
		int Minid = 0, Min = INF;
		for(int i = fi[u]; i; i = ne[i]) {
			int v = to[i];
			if(sz[v] < Min) {
				Min = sz[v];
				Minid = v;
			}
		}
		for(int i = fi[u]; i; i = ne[i]) {
			int v = to[i];
			if(vis[i]) continue;
			if(cnt == 3 && v == Minid) continue;
			f = true;
			if(!asku) asku = v;
			else if(!askv) askv = v;
		}
		if(cnt == 3) idx = Minid;
		return;
	}
	sz[u] -= sz[idy];
	sz[idy] += sz[u];
	dfs(idy, u);
	if(f) return;
	sz[idy] -= sz[u];
	sz[u] += sz[idy];
}
void Print(int t, int x, int y) {
	if(t == 1) cout << "? " << x << " " << y << '\n';
	else cout << "! " << x << '\n';
	cout.flush();
}
void solve() {
	n = read();
	num = 1;
	for(int i = 1; i <= n; i++) {
		int l = read(), r = read();
		add(i, l); add(l, i);
		add(i, r); add(r, i);
	}
	int p = 1;
	resn = n;
	while(true) {
		if(resn == 1) {
			cout << "! " << p << '\n';
			cout.flush();
			return;
		}
		if(resn == 2) {
			int vx = 0;
			for(int i = fi[p]; i; i = ne[i]) {
				int v = to[i];
				if(vis[i]) continue;
				vx = v;
			}
			Print(1, p, vx);
			int x = read();
			if(x == 0) Print(2, p, 0);
			else Print(2, vx, 0);
			return;
		}
		
		f = false; idx = 0; idu = 0;
		asku = askv = 0;
		init(p, 0);
		dfs(p, 0);
		Print(1, asku, askv);
		int x = read();
		if(!idx) {
			if(x == 1) {
				Print(2, idu, 0);
				return;
			}
			for(int i = fi[idu]; i; i = ne[i]) {
				int v = to[i];
				vis[i] = vis[i ^ 1] = true;
			}
			resn--;
			if(x == 0) {
				p = asku;
				init(askv, 0);
				resn -= sz[askv];
			}
			else {
				p = askv;
				init(asku, 0);
				resn -= sz[asku];
			}
		}
		else {
			for(int i = fi[idu]; i; i = ne[i]) {
				int v = to[i];
				if(v != idx) {
					vis[i] = vis[i ^ 1] = 1;
				}
			}
			if(!x) {
				p = asku;
				init(idu, 0);
				resn -= sz[idu];
				init(askv, 0);
				resn -= sz[askv];
			}
			else if(x == 1) {
				p = idu;
				init(asku, 0);
				resn -= sz[asku];
				init(askv, 0);
				resn -= sz[askv];
			}
			else {
				p = askv;
				init(idu, 0);
				resn -= sz[idu];
				init(asku, 0);
				resn -= sz[asku];
			}
		}
	}
}
signed main() { 
	int T = read();
	while(T--) {
		solve();
		for(int i = 0; i <= num + 5; i++) {
			ne[i] = to[i] = fi[i] = 0;
			vis[i] = 0;
			sz[i] = 0;
		}
		num = 0;
	}
	return 0;
}
/*
*/
