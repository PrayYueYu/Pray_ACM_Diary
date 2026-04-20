#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, mod = 1000000007, INF = 1e18;
std::pair<int, int> eg[N];
int n, rank[N], vis[N], cnt[N];
int vis1[N], vis2[N];
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
int getr(int u, int s) {
	int x = eg[u].first;
	int y = eg[u].second;
	if(x == s) return y;
	return x;
}
std::set<int> to[N];
void solve() {
	n = read();
	std::queue<int> q;
	
	for(int i = 1; i <= n; i++) {
		eg[i] = {0, 0};
		char c; std::cin >> c;
		if(c == 'T') {
			int x = read();
			rank[i] = x;
			if(vis[x]) {
				std::cout << "NIE\n0";
				return;
			}
			to[x].insert(i);
			cnt[i] = 1;
			vis[x] = i;
			q.push(i);
		}
		else {
			int x = read(), y = read();
			cnt[i] = 2;
			eg[i] = {x, y};
			to[x].insert(i);
			to[y].insert(i);
		}
	}
	while(!q.empty()) {
		int x = q.front(); q.pop();
		std::vector<int> v;
		for(auto t: to[rank[x]]) {
			if(t == x) continue;
			cnt[t]--;
			if(!cnt[t]) {
				std::cout << "NIE\n0";
				return;
			}
			else {
				rank[t] = getr(t, rank[x]);
				q.push(t);
				v.push_back(t);
				vis[rank[t]] = t;
			}
		}
		for(auto t: v) {
			auto it = to[rank[x]].find(t);
			to[rank[x]].erase(it);
		}
	}
	int f = true;
	for(int i = 1; i <= n; i++) {
		if(!rank[i]) {
			f = false;
			break;
		}
	}
	if(f) {
		std::cout << "TAK\n";
		for(int i = 1; i <= n; i++) {
			std::cout << rank[i] << '\n';
		}
	}
	else {
		std::cout << "NIE\n";
		int ans = 1;
		for(int i = 1; i <= n; i++) {
			if(vis2[i]) continue;
			if(vis[i]) continue;
			vis2[i] = true;
			ans = ans * 2ll % mod;
			q.push(i);
			int cnt1 = 0, cnt2 = 1;
			while(!q.empty()) {
				int x = q.front();
				q.pop();
				for(auto t: to[x]) {
					if(vis1[t]) continue;
					vis1[t] = true;
					cnt1++;
					int u = eg[t].first, v = eg[t].second;
					if(!vis2[u]) {
						q.push(u);
						vis2[u] = true;
						cnt2++;
					}
					if(!vis2[v]) {
						q.push(v);
						vis2[v] = true;
						cnt2++;
					}
				}
			}
			if(cnt1 != cnt2) ans = 0;
		}
		std::cout << ans;
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
