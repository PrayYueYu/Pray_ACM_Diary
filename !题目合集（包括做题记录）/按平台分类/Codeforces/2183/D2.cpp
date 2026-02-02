#include<bits/stdc++.h>
//#define getchar getchar_unlocked
const int N = 5e5 + 10, mod = 998244353, INF = 	1e9;
int n, ne[N], to[N], fi[N], num, cnt[N], d[N];
int fat[N], sonx[N];
using namespace std;
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
std::vector<std::pair<int, int>> vx[N];
std::queue<int> q[N];
std::priority_queue<pair<int, int>> qx[N];
void init() {
	for(int i = 0; i <= num + 5; i++) {
		to[i] = ne[i] = fi[i] = 0;
	}
	num = 0;
	for(int i = 0; i <= n + 5; i++) {
		cnt[i]= d[i] = 0;
		fat[i] = sonx[i]  = 0;
		while(!q[i].empty()) q[i].pop();
		while(!qx[i].empty()) qx[i].pop();
		vx[i].clear();
	}
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}

void dfs(int u, int fa) {
	d[u] = d[fa] + 1;
	cnt[d[u]]++;
	fat[u] = fa;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fat[u]) continue;
		dfs(v, u);
		q[u].push(v);
	}
}
int Tx, test;
void solve() {
	test++;
	n = read();
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v);
		add(v, u);
	}

	d[0] = 0;
	dfs(1, 0);
	int maxn = -1, ans = 0, L = n;
	for(int i = 1; i <= n; i++) {
		if(maxn < cnt[i]) {
			maxn = cnt[i];
		}
		if(cnt[i] == 0) {
			L = i - 1;
			break;
		}
	}
	ans = maxn;
	for(int i = 1; i <= n; i++) {
		int val = -1;
		if(i == 1) val = 0;
		for(int j = fi[i]; j; j = ne[j]) {
			val++;
		}
		sonx[i] = val;
		if(val == cnt[d[i] + 1] && val == maxn) {
			ans = maxn + 1;
		}
	}
	std::cout << ans << '\n';
	std::set<int> s;

	for(int i = 1; i <= n; i++) {
		s.insert(i);
		if(sonx[i]) qx[d[i]].push({sonx[i], i});
	}
	fat[1] = 0;
	sonx[0] = 1;
	cnt[0] = 1;
	qx[0].push({sonx[0], 0});
	q[0].push(1);
	for(int i = 1; i <= ans; i++) {
		std::vector<int> del, pr;
		int las = -1;
		for(auto c: s) {
			if(qx[c - 1].empty()) {
				del.push_back(c);
				continue;
			}
			int x = qx[c - 1].top().second;
			qx[c - 1].pop();
			if(las == x) {
				if(qx[c - 1].empty()) {
					qx[c - 1].push({sonx[x], x});
					continue;
				}
				int y = qx[c - 1].top().second;
				qx[c - 1].pop();
				sonx[y]--;
				if(sonx[y]) qx[c - 1].push({sonx[y], y});
				int z = q[y].front();
				q[y].pop();
				las = z;
				pr.push_back(z);
				
				qx[c - 1].push({sonx[x], x});
				continue;
			}
			sonx[x]--;
			if(sonx[x]) qx[c - 1].push({sonx[x], x});
			int z = q[x].front();
			q[x].pop();
			las = z;
			pr.push_back(z);
		}
		for(auto x: del) {
			s.erase(s.find(x));
		}
		if(pr.size() != 0) {
			std::cout << pr.size() << ' ';
			for(auto x: pr) std::cout << x << ' ';
			std::cout << '\n';
		}
	}
}
signed main() {
	int T = read();
	Tx = T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:
2
8
1 4
1 3
1 2
2 6
2 5
3 8
3 7
8
1 2
1 3
1 4
2 5
2 6
3 7
3 8
*/
