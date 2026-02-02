#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e16; 
int n, m, a[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct S {
	int r, w;
} s[N];
bool cmp(S x, S y) {
	return x.r < y.r;
}
priority_queue<int> q;
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) {
		s[i].r = read();
		s[i].w = read();
	}
	sort(s + 1, s + m + 1, cmp);
	int now = 1;
	for(int i = 1; i <= n; i++) {
		q.push(-a[i]);
		while(true) {
			if(s[now].r > i || now > m) break;
			int x = -q.top();
			x -= s[now].w;
			q.pop();
			q.push(-x);
			now++;
		}
	}
	int sum = 0;
	while(!q.empty()) {
		sum -= q.top();
		cout << sum << " ";
		q.pop();
	}
	cout << endl;
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		solve();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
