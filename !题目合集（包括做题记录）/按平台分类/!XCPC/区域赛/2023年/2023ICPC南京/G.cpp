#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 1e9 + 7, INF = 1e16; 
int n, W, k, f[5030][10050];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
priority_queue<int> q;
struct S {
	int w, v;
} s[N];
bool cmp(S x, S y) {
	return x.w < y.w;
}
signed main() {
	n = read(), W = read(), k = read();
	for(int i = 1; i <= n; i++) {
		s[i].w = read();
		s[i].v = read();
	}
	sort(s + 1, s + n + 1, cmp);
	for(int j = W; j >= 1; j--) {
		f[1][j] = -INF;
	}
	if(s[1].w <= W) f[1][s[1].w] = s[1].v;
	for(int i = 2; i <= n; i++) {
		for(int j = W; j >= 0; j--) {
			f[i][j] = f[i - 1][j];
			if(j - s[i].w >= 0) 
				f[i][j] = max(f[i][j], f[i - 1][j - s[i].w] + s[i].v);
		}
	}
	int ans = -INF, all = 0;
	for(int i = n; i >= 1; i--) {
		int sum = 0;
		for(int j = W; j >= 0; j--) {
			sum = max(sum, f[i][j]);
		}
		sum += all;
		ans = max(ans, sum);
		if(q.empty()) {
			if(k) {
				all += s[i].v;
				q.push(-s[i].v);
			}
			continue;
		}
		else {
			if(q.size() >= k) {
				all += q.top();
				q.pop();
				all += s[i].v;
				q.push(-s[i].v);
			}
			else {
				all += s[i].v;
				q.push(-s[i].v);
			}
		}
	}
	cout << ans;
	return 0;
}
/*

*/
