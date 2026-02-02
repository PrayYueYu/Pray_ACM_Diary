#include<bits/stdc++.h>
using namespace std;
const int N = 4e6 + 100;
int n, a[N], Max[N], c[N], ans, k, num[N], ansx[N];
int read() {
	int x;
	scanf("%d", &x);
	return x;
}
struct Ar {
	int b, id;
} s[N];
bool cmp(Ar x, Ar y) {
	return x.b > y.b;
}
void build(int p, int l, int r, int x) {
	if(x < l || x > r) return;
	if(l == r) {
		Max[p] = a[l];
		num[p] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(p * 2, l, mid, x);
	build(p * 2 + 1, mid + 1, r, x);
	Max[p] = max(Max[p * 2], Max[p * 2 + 1]);
	num[p] = num[p * 2] + num[p * 2 + 1];
}
void buildx(int p, int l, int r) {
	if(l == r) return;
	int mid = (l + r) >> 1;
	buildx(p * 2, l, mid);
	buildx(p * 2 + 1, mid + 1, r);
	c[p] = c[p * 2] + 1;
}
void query(int p, int l, int r, int x) {
	if(Max[p] == a[x]) {
		ans = max(ans, c[p]);
		return;
	}
	if(x < l || x > r) return;
	int mid = (l + r) >> 1;
	query(p * 2, l, mid, x);
	query(p * 2 + 1, mid + 1, r, x);
	if(num[p] - 1 <= k && a[x] >= r - l + 1) {
		ans = max(ans, c[p]);
	}
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	n = read(); k = read();
	n = 1ll << n;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		s[i].b = a[i];
		s[i].id = i;
	}
	sort(s + 1, s + n + 1, cmp);
	buildx(1, 1, n);
	for(int i = 1; i <= n; i++) {
		ans = 0;
		build(1, 1, n, s[i].id);
		query(1, 1, n, s[i].id);
		ansx[s[i].id] = ans;
	}
	for(int i = 1; i <= n; i++) cout << ansx[i] << ' '; 
	return 0;
}
/*
	
*/
