#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
int chu[N], ru[N], n, S, T, vis[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
vector<pair<int, int>> pa[N];
void dfs(int u, int s) {
	if(u == T) {
		if(vis[s]) {
			cout << s << endl;
			system("pause");
			return;
		}
		vis[s] = true;
		return;
	}
	for(auto v: pa[u]) {
		dfs(v.first, s * 2 + v.second);
	}
}
signed main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		int k = read();
		for(int j = 1; j <= k; j++) {
			int v = read(), w = read();
			pa[i].push_back({v, w});
			ru[v]++;
			chu[i]++;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!ru[i]) S = i;
		if(!chu[i]) T = i;
	}
	dfs(S, 0);
	int L = 0, R = 0;
	for(int i = 0; i <= N - 1; i++) {
		if(vis[i]) {
			L = i;
			break;
		}
	}
	for(int i = N - 1; i >= 0; i--) {
		if(vis[i]) {
			R = i;
			break;
		}
	}
	int sum = 0;
	for(int i = 0; i <= N - 1; i++) {
		if(vis[i]) sum++;
	}
	cout << L << " " << R << endl;
	cout << sum << " v.s " << R - L + 1;
	return 0;
}
