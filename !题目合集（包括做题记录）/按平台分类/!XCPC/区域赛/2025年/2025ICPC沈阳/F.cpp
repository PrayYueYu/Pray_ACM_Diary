#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 400, INF = 1e9;
int n, m, sx, sy;
int fax[N], d[N], fa[N], dx[N];
int Min = INF, s1, s2, sp;
int fx[N][N], f[N][N], vis[N];
vector<int> p[N];
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void init() {
	Min = INF, s1 = s2 = sp = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			fx[i][j] = f[i][j] = 0;
		}
		vis[i] = fa[i] = dx[i] = 0;
		p[i].clear();
	}
}
queue<int> q;
void bfs(int s) {
	while(!q.empty()) q.pop();
	q.push(s);
	for(int i = 1; i <= n; i++) {
		fax[i] = 0;
		d[i] = 0;
	}
	d[s] = 1;
	int minn = INF, t1 = 0, t2 = 0, tp = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v: p[u]) {
			if(v == fax[u]) continue;
			if(d[v]) {
				int len = d[u] + d[v] - 1;
				if(len <= 2) continue;
				if(len < minn) {
					minn = len;
					t1 = u, t2 = v, tp = s;
				}
				continue;
			}
			fax[v] = u;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	if(minn == INF) return;
	if(minn < Min) {
		Min = minn;
		s1 = t1, s2 = t2, sp = tp;
		for(int i = 1; i <= n; i++) {
			fa[i] = fax[i];
			dx[i] = d[i];
		}
	}
}
int ts = 0;
void solve(int T) {
	n = read(), m = read();
	sx = read(), sy = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		p[u].push_back(v);
		p[v].push_back(u);
		f[u][v] = f[v][u] = 1;
	}
//	if(ts == 1000) {
//		if(T != 5) return;
//		else {
//		cout << n << " " << m << " " << sx << " " << sy << endl;
//			for(int i = 1; i <= n; i++) {
//				for(auto v:p[i]) {
//					if(i < v) 
//						cout << i << " " << v << endl;
//				}
//			}
//		}
//	}
	if(!f[sx][sy]) {
		cout << "Yes\n";
		for(int u = 1; u <= n; u++) {
			for(auto v: p[u]) {
				if(v > u) continue;
				if(v == sx || v == sy) {
					cout << u << " " << v << '\n';
					continue;
				}
				cout << v << " " << u << '\n';
			}
		}
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(f[sx][i] && f[sy][i]) {
			cout << "Yes\n";
			vis[sx] = vis[sy] = vis[i] = 1;
			for(int u = 1; u <= n; u++) {
				for(auto v: p[u]) {
					if(v > u) continue;
					if(vis[v] && vis[u]) continue;
					if(vis[v]) cout << u << ' ' << v << '\n';
					else cout << v << ' ' << u << '\n';
				}
			}
			cout << sx << ' ' << sy << '\n';
			cout << sy << ' ' << i << '\n';
			cout << i << ' ' << sx << '\n';
			return;
		}
	}
	bfs(sx); 
	bfs(sy);
	//先找经过sx，sy的环 
	if(!s1 || !s2) {
		for(int i = 1; i <= n; i++) bfs(i);
	}
	cout << s1 << ' ' << s2 << ' ' << sp << endl;
	if(!s1 || !s2) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
	int now1 = s1, now2 = s2;
	fx[s1][s2] = 1;
	vis[s1] = vis[s2] = true;
	while(true) {
		if(dx[now1] > dx[now2]) {
			fx[fa[now1]][now1] = 1;
			now1 = fa[now1];
			vis[now1] = true;
		}
		else if(dx[now1] < dx[now2]) {
			fx[now2][fa[now2]] = 1;
			now2 = fa[now2];
			vis[now2] = true;
		}
		else {
			if(now1 == now2) {
				if(now1 == sp) break;
				fx[fa[now1]][now1] = 1;
				now1 = fa[now1];
				now2 = fa[now2];
				vis[now1] = 1;
			}
			else {
				fx[fa[now1]][now1] = 1;
				fx[now2][fa[now2]] = 1;
				now1 = fa[now1];
				now2 = fa[now2];
				vis[now1] = vis[now2] = 1;
			}
		}
	}
	
	if(vis[sx] || vis[sy]) {
		if(vis[sx] && vis[sy]) {}
		else if(vis[sx]) {
			fx[sy][sx] = true;
			vis[sy] = 2;
		}
		else if(vis[sy]) {
			fx[sx][sy] = true;
			vis[sx] = 2;
		}
	}
	else {
		int now = sx;
		while(true) {
			if(vis[now] == 1) break;
			vis[now] = 2;
			fx[now][fa[now]] = 1;
			now = fa[now];
		}
		if(!vis[sy]) {
			fx[sy][sx] = 1;
		}
		vis[sx] = vis[sy] = 2;
	}
	
	for(int u = 1; u <= n; u++) {
		for(auto v: p[u]) {
			if(v > u) continue;
			if(fx[v][u] || fx[u][v]) {
				if(fx[v][u]) cout << v << ' ' << u << '\n';
				else cout << u << ' ' << v << '\n';
				continue;
			}
			if(!vis[u] || !vis[v]) {
				if(!vis[u]) cout << u << ' ' << v << '\n';
				else cout << v << ' ' << u << '\n';
				continue;
			}
			if(vis[u] == 1 && vis[v] == 2) {
				cout << v << ' ' << u << '\n';
			}
			else cout << u << ' ' << v << '\n';
		}
	}
}
signed main() {
	int T = read();
	ts = T;
	int tot = 0;
	while(T--) {
		tot++;
		solve(tot);
		init();
	}
	return 0;
}
/*
1
5 7 1 2
1 4
5 4
1 3
1 2
1 5
2 3
2 4

*/
