#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 100, INF = 1e9;
int n, a[N], m;
int sum[N], vis[N], ans, mex, num, las[N];
int read() {
	int x;
	scanf("%d", &x);
	return x;
}
struct Mo {
	int l, r, k;
} s[N];
bool cmp1(Mo x, Mo y) {
	if(vis[x.l] == vis[y.l]) 
		return x.r < y.r;
	return vis[x.l] < vis[y.l];
}
void Solve(int x, int y) {
	if(y == 1) {
		if(!sum[a[x]]) num++;
		sum[a[x]]++;
	}
	else {
		sum[a[x]]--;
		if(!sum[a[x]]) num--;
	}
}
void solve() {
	n = read(), m = read();//m无用 
	m = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		int l = las[a[i]] + 1;
		int r = i - 1;
		if(las[a[i]] && l <= r) {
			s[++m].l = l;
			s[m].r = r;
			s[m].k = a[i];
		}
		las[a[i]] = i;
	}
	int Len = sqrt(n), L = 0, R = 0, t = 0;
	while(true) {
		t++;
		L = R + 1;
		R = min(L + Len - 1, n);
		for(int i = L; i <= R; i++) vis[i] = t;
		if(R == n) break;
	}
	sort(s + 1, s + m + 1, cmp1);//排序
	
	int l = 1, r = 0;
	ans = -1;
	mex = 1;
	num = 0;
	for(int i = 1; i <= m; i++) {
		while(l > s[i].l) Solve(--l, 1);
		while(l < s[i].l) Solve(l++, -1);
		while(r > s[i].r) Solve(r--, -1);
		while(r < s[i].r) Solve(++r, 1);
		ans = max(ans, num - s[i].k);
	}
	
	num = 0, mex = 1;
	for(int i = 1; i <= n; i++) {
		sum[a[i]] = 0;
	}
	for(int i = 1; i <= n; i++) {//从前往后扫 
		if(!sum[a[i]]) num++;
		sum[a[i]]++;
		while(true) {
			if(sum[mex]) mex++;
			else break;
		}
		ans = max(ans, num - mex);
	}
	
	num = 0, mex = 1;
	for(int i = 1; i <= n; i++) sum[a[i]] = 0;
	for(int i = n; i >= 1; i--) {//从后往前扫 
		if(!sum[a[i]]) num++;
		sum[a[i]]++;
		while(true) {
			if(sum[mex]) mex++;
			else break;
		}
		ans = max(ans, num - mex);
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++) {
		sum[a[i]] = 0;
		las[a[i]] = 0;
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = read();
	while(T--) {
		solve();
	}
	return 0;
} 
/*
*/
