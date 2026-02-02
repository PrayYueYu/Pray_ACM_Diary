#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int n, vis[N], pcnt, p2[N], cnt, p[N], num[N], ans;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void pre() {
	int Nx = 1e5 + 3;
	vis[1] = true;
	for(int i = 2; i <= Nx; i++) {
		if(!vis[i]) {
			p[++pcnt] = i;
		}
		for(int j = 1; ; j++) {
			if(i * p[j] > Nx) break;
			vis[i * p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
}
bool check(int x) {
	if(x == 1) return false;
	for(register int i = 2; i <= sqrt(x); i++) {
		if(x % i == 0) return false;
	}
	return true;
}
inline void dfs(int t, int s, int v) {
	if(t == cnt + 1) {
	//	cout << s << " " << v << endl;
		if(v) ans += s * p2[v - 1];
		return;
	}
	dfs(t + 1, s, v);
	dfs(t + 1, s * num[t], v + 1);
}
void solve() {
	n = read();
	int x = n;
	cnt = 0; ans = 0;
	for(register int t = 1; t <= pcnt; t++) {
		int i = p[t];
		if(i > n) break;
		if(n % i != 0) continue;
		if(!vis[i]) {
			++cnt;
			num[cnt] = 0;
			while(true) {
				if(x % i != 0) break;
				x /= i;
				num[cnt]++;
			}
		//	cout << i << ' ' << num[cnt] << endl;
		}
	}
	if(check(x)) {
		++cnt;
		num[cnt] = 1;
	}
	dfs(1, 1, 0);
	cout << ans + 1 << '\n';
}
signed main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	p2[0] = 1;
	for(int i = 1; i <= 12; i++) {
		p2[i] = (p2[i - 1] * 2);
	}
	pre();
	int T = read();
	while(T--) solve();
	return 0;
} 
/*
6469693230
*/
