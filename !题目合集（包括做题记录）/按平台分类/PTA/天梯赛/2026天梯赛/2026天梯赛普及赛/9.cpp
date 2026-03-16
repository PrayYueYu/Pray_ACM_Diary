#include<bits/stdc++.h>
#define int long long
const int N = 2e4 + 100;
int n, m, fa1[N], fa2[N], a[202][1005], cnt[N];
std::vector<std::vector<int>> v;
int getfa1(int x) {
	if(x == fa1[x]) return x;
	return fa1[x] = getfa1(fa1[x]);
}
int getfa2(int x) {
	if(x == fa2[x]) return x;
	return fa2[x] = getfa2(fa2[x]);
}
void solve() {
	scanf("%d%d", &n, &m);
	v.resize(m + 10);
	for(int i = 1; i <= n; i++) fa1[i] = i;
	for(int i = 1; i <= m; i++) fa2[i] = i;
	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &cnt[i]);
		for(int j = 1; j <= cnt[i]; j++) {
			scanf("%d", &a[i][j]);
			v[a[i][j]].push_back(i);
		} 
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j < v[i].size(); j++) {
			int fax = getfa1(v[i][0]);
			int fay = getfa1(v[i][j]);
			if(fax == fay) continue;
			if(fax < fay) fa1[fay] = fax;
			else fa1[fax] = fay;
		}
	}
	for(int i = 1; i <= n; i++) {
		int fai = getfa1(i);
		for(int j = 1; j <= cnt[i]; j++) {
			int fax = getfa2(a[fai][1]);
			int fay = getfa2(a[i][j]);
			if(fax == fay) continue;
			if(fax < fay) fa2[fay] = fax;
			else fa2[fax] = fay;
		}
	}
	std::vector<int> ans;
	for(int i = 1; i <= m; i++) {
		int fai = getfa2(i);
		if(i == fai) ans.push_back(i);
	}
	for(int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i]);
		if(i != ans.size() - 1) std::cout << ' ';
	}
}
signed main() {
	solve();
	return 0;
} 
