#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 100, INF = 1e18, M = 1e9 + 7;
int n, q, sk[N], sb[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
struct Fun {
	int k, b;
} tr[N];
void pushup(int p) {
	int s1 = p * 2, s2 = p * 2 + 1;
	tr[p].k = (tr[s1].k * tr[s2].k) % M;
	tr[p].b = (tr[s2].k * tr[s1].b + tr[s2].b) % M;
}
void build(int p, int l ,int r) {
	if(l == r) {
		tr[p] = {sk[l], sb[l]};
		return;
	}
	int mid = (l + r) >> 1, s1 = p * 2, s2 = p * 2 + 1;
	build(s1, l, mid);
	build(s2, mid + 1, r);
	pushup(p);
}
void update(int p, int l, int r, int x, int k, int b) {
	if(x < l || x > r) return;
	if(l == r) {
		tr[p] = {k, b};
		return;
	}
	int mid = (l + r) >> 1;
	update(p * 2, l, mid, x, k, b);
	update(p * 2 + 1, mid + 1, r, x, k, b);
	pushup(p);
}
Fun query(int p, int l, int r, int x, int y) {
	if(y < l || r < x) return {-1, -1};
	if(x <= l && r <= y) {
		return tr[p];
	}
	int mid = (l + r) >> 1;
	Fun s1 = query(p * 2, l, mid, x, y);
	Fun s2 = query(p * 2 + 1, mid + 1, r, x, y);
	if(s1.k == -1) return s2;
	if(s2.k == -1) return s1;
	int k = (s1.k * s2.k) % M;
	int b = (s2.k * s1.b + s2.b) % M;
	return {k, b};
}
signed main() {
	n = read(), q = read();
	for(int i = 1; i <= n; i++) {
		sk[i] = read();
	}
	for(int i = 1; i <= n; i++) {
		sb[i] = read();
	}
	build(1, 1, n);
	for(int i = 1; i <= q; i++) {
		int op = read();
		if(op == 1) {
			int x = read();
			int k = read(), b = read();
			update(1, 1, n, x, k, b);
		}
		else {
			int l = read(), r = read();
			Fun ans = query(1, 1, n, l, r);
			cout << (ans.k + ans.b) % M << '\n';
		}
	}
	return 0;
} 
/*
5 1
3 32 23 25 63
5 54 1 64 0
2 1 5
*/
