#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int n, vis[N], ans[N];
struct S {
	int x, y, z, id;
} s[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
priority_queue<pair<int, pair<int, int>>> q;
map<int, int> mp[4];
void init() {
	while(!q.empty()) q.pop();
	for(int i = 1; i <= 3; i++) {
		mp[i].clear();
	}
	for(int i = 1; i <= n; i++) {
		vis[i] = false;
	}
}
void solve() {
	n = read();
	vector<vector<int>> v[4];
	for(int i = 1; i <= 3; i++) {
		v[i].resize(n + 3);
	}
	int cnt[4] = {0, 0, 0, 0};
	for(int i = 1; i <= n; i++) {
		s[i].x = read();
		s[i].y = read();
		s[i].z = read();
		s[i].id = i;
		int s1 = 0, s2 = 0, s3 = 0;
		if(!mp[1][s[i].x]) mp[1][s[i].x] = ++cnt[1];
		if(!mp[2][s[i].y]) mp[2][s[i].y] = ++cnt[2];
		if(!mp[3][s[i].z]) mp[3][s[i].z] = ++cnt[3];
		s1 = mp[1][s[i].x];
		s2 = mp[2][s[i].y];
		s3 = mp[3][s[i].z];
		v[1][s1].push_back(i);
		v[2][s2].push_back(i);
		v[3][s3].push_back(i);
	}
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= cnt[i]; j++) {
			q.push({v[i][j].size(), {i, j}});
		}
	}
	int val = 0;
	for(int i = n; i >= 1; i--) {
		while(!q.empty()) {
			int num = q.top().first;
			if(num < i) break;
			int x = q.top().second.first;
			int y = q.top().second.second;
			q.pop();
			for(auto u: v[x][y]) {
				if(vis[u]) continue;
				vis[u] = true;
				val++;
			}
		}
		ans[i] = n - val;
	}
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
