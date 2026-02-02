#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define pii pair<int,int>
using namespace std;
int n;
//bool ok = 0;
vector<int> ed[300005];
vector<pii> ans;
int root;
int ys[300005];
void dfs(int x, int f) {
	for (int e : ed[x]) {
		if (e == f)continue;
		dfs(e, x);
	}
	int cez = ed[x].size() - 1;
	if (x == root)cez++;
	if (cez == 0)return;
	if (cez % 2 == 0) {
		int x1 = 0;
		for (int e : ed[x]) {
			if (e == f)continue;
			if (x1 == 0) {
				x1 = e;
			} else {
				ans.pb({ys[x1], ys[e]});
				x1 = 0;
			}
		}
	} else {
		int x1 = 0;
		for (int e : ed[x]) {
			if (e == f)continue;
//			if (!x2 && ys[e] != e) {
//				x2 = e;
//				continue;
//			}
			if (x1 == 0) {
				x1 = e;
			} else {
				ans.pb({ys[x1], ys[e]});
				x1 = 0;
			}
		}
//		if (x2) {
//			ys[x] = x2;
//		} else {
		ys[x] = ys[x1];
//			if (x == root) {
//				ok = 0;
//			}
//		}
	}
}

void sovle() {
	ans.clear();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ed[i].clear();
		ys[i] = i;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		ed[u].pb(v);
		ed[v].pb(u);
	}
	root = -1;
	for (int i = 1; i <= n; i++) {
		if (ed[i].size() % 2 == 0) {
			root = i;
			break;
		}
	}
	if (root == -1) {
		cout << "-1\n";
		return;
	}
	dfs(root, -1);
	cout << ans.size() << endl;
	for (auto&[u, v] : ans) {
		cout << u << " " << v << endl;
	}
}

signed main() {
	int T;
	cin >> T;
	while (T--) {
		sovle();
	}
}
