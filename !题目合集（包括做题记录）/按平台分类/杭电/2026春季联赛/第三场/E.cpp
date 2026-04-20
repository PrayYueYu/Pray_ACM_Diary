#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int vis[100], num[100], p[100], n, q, a[N];
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void init() {
	for(int i = 0; i <= 37; i++) {
		vis[i] = num[i] = 0;
	}
}
inline int Bit(int x,int t){
	return (x / p[t]) % 3;
}
int Xor(int x, int y) {
	int ans = 0;
	for(int i = 0; i <= 37; i++) {
		ans += p[i] * ((x + y) % 3);
		x /= 3;
		y /= 3;
		if(!x && !y) break;
	}
	return ans;
}
void insert(int x){
	for(int i = 37; i >= 0; i--) {
		int v = Bit(x, i);
		if(!v) continue;
		if(!vis[i]){
			vis[i] = 1;
			if(v == 2) x = Xor(x,x);
			num[i] = x;
			return;
		}
		if(v == 1) x = Xor(x,x);
		x = Xor(x, num[i]);
	}
	return;
}
bool query(int x){
	for(int i = 37; i >= 0; i--) {
		if(!Bit(x, i)) continue;
		if(!vis[i]) return false;
		while(Bit(x, i)) x = Xor(x, num[i]);
	}
	if(!x) return true;
	return false;
}
void solve() {
	n = read(), q = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		insert(a[i]);
	}
	for(int i = 1; i <= q; i++) {
		int s = read();
		if(query(s)) printf("Yes\n");
		else printf("No\n");
	}
}
signed main() {
	p[0] = 1;
	for(int i = 1; i <= 38; i++) p[i] = p[i - 1] * 3;
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
