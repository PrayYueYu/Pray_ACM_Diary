#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 10, INF = 1e13 + 7, M = 998244353;
ll n, a[N], vis[N], r[N], num, ne[N], to[N], fi[N];
ll p[N], sum[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}

ll Solve(int u, int fa, int day) {
	vis[u] = true;
	ll sumx = r[u] * (n - day);
	sum[u] = r[u]; 
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		if(vis[v]) continue;
		sumx += Solve(v, u, day + 1);
		sum[u] += sum[v]; 
	}
	return sumx;
}

void dfs(int u, int fa) {
	vis[u] = true;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		if(vis[v]) continue;
		p[v] = p[u] - sum[1] + 2 * sum[v];
		dfs(v, u);
	}
}

int main() {
//	freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		n = read(); num = 0;
		for(int i = 1; i <= n; i++) {
			vis[i] = false;
			r[i] = p[i] = fi[i] = sum[i] = 0;
		}
		for(int i = 1; i < n; i++) {
			int u = read(), v = read();
			add(u, v); add(v, u);
			r[u]++, r[v]++;
		}
		p[1] = 1 + Solve(1, 1, 0);
		for(int i = 1; i <= n; i++) vis[i] = false;
		dfs(1, 1);
		ll Max = -1, anssum = 0;
		for(int i = 1; i <= n; i++) {
			if(Max < p[i]) {
				Max = p[i];
				anssum = 1;
			}
			else if(Max == p[i]) anssum++;
		}
		cout << anssum << endl;
		for(int i = 1; i <= n; i++) {
			if(p[i] == Max) cout << i << " ";
		}
		cout << endl;
		for(int i = 1; i <= num; i++) to[i] = ne[i] = false;
	}
	return 0;
}
/*

*/
