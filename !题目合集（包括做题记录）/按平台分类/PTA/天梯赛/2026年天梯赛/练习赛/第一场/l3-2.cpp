#include<bits/stdc++.h>
#define int long long
#define double long double
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int n, fi[N], to[N], ne[N], num, ed[N];
int vis[N], w[N], fg[N], END;
double a[N];
int read() {
	int x;
	std::cin >> x;
	return x;
}
void add(int u, int v, int t) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
	w[num] = t;
}
double get_ans() {
	std::queue<int> q;
	for(int i = 1; i <= n; i++) {
		if(vis[i]) {
			a[i] = 0L;
			if(vis[i] <= 3) ed[i] = 2;
			else ed[i] = 1;
			continue;
		}
		q.push(i);
	}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = fi[u]; i; i = ne[i]) {
			int v = to[i];
			int t = w[i];
			if(t == 1) a[v] += a[u];
			if(t == 2) a[v] -= a[u];
			if(t == 3) {
				if(ed[v] == 2) a[v] = a[u];
				else a[v] *= a[u];
			}
			if(t == 4) a[v] = (double)exp(a[u]);
			if(t == 5) a[v] = (double)log(a[u]);
			if(t == 6) a[v] = (double)sin(a[u]);
			ed[v]--;
			if(!ed[v]) q.push(v);
		}
	}
	return a[END];
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) fg[i] = true;
	for(int i = 1; i <= n; i++) {
		int op = read();
		if(op == 0) {
			std::cin >> a[i];
		}
		else if(op == 1 || op == 3) {
			int x = read() + 1, y = read() + 1;
			add(x, i, op);
			add(y, i, op);
			fg[x] = fg[y] = false;
		}
		else if(op == 2) {
			int x = read() + 1, y = read() + 1;
			add(x, i, 1);
			add(y, i, 2);
			fg[x] = fg[y] = false;
		}
		else {
			int x = read() + 1;
			add(x, i, op);
			fg[x] = false;
		}
		vis[i] = op;
	}
	for(int i = 1; i <= n; i++) {
		if(fg[i]) END = i;
	}
	double ans = get_ans();
	double ex = 1e-10L;
	std::vector<double> v;
	printf("%.3Lf\n", ans);
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		a[i] += ex;
		double now1 = get_ans();
		a[i] -= 2.0L * ex;
		double now2 = get_ans();
		now1 = (now1- now2) / (2.0L * ex);
		v.push_back(now1);
		a[i] += ex;
	}
	double eps = 1e-4;
	for(int i = 0; i < v.size(); i++) {
		v[i] += eps;
		printf("%.3Lf", v[i]);
		if(i != v.size() - 1) std::cout << ' ';
	}
}
signed main() {
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
