#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
bool frd[maxn];
int pre1[maxn];
map<pair<int, int>, int> M;
vector<int> ed[maxn];
void solve() {
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	M.clear();
	for (int i = 1; i <= k; i++) {
		pre1[i] = 0;
		frd[i] = 0;
		ed[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		frd[x] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (frd[u] && frd[v]) ans += 1;
		else if (!frd[u] && frd[v]) pre1[u]++;
		else if (!frd[v] && frd[u]) pre1[v]++;
		else if(u == v) pre1[u]++;
		else {
			ed[u].push_back(v);
			ed[v].push_back(u);
			M[{min(u, v), max(u, v)}]++;
		}
	}
	int max1 = 0, max2 = 0;
	for (int i = 1; i <= k; i++) {
		if (pre1[i] > max1) {
			max2 = max1;
			max1 = pre1[i];
		} else if (pre1[i] > max2) {
			max2 = pre1[i];
		}
	}
	int mans = max1 + max2;
	for (int i = 1; i <= k; i++) {
		if (frd[i])continue;
		for (int e : ed[i]) {
			if (frd[e]) {
				continue;
			}
			int now = pre1[e] + pre1[i];
			if (M.count({min(i, e), max(i, e)})) {
				now += M[{min(i, e), max(i, e)}];
			}
			mans = max(mans, now);
		}
	}
	cout << ans + mans << endl;
}

signed main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
