#include<bits/stdc++.h>
#define int long long
const int N = 2e4 + 10, mod = 998244353, INF = 1e18;

int read() {
//	int x = 0, f = 1;
//	char ch = getchar();
//	while(ch < '0' || ch > '9') {
//		if(ch == '-') f = -1;
//		ch = getchar();
//	}
//	while(ch >= '0' && ch <= '9') {
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//	return x * f;
	int x;
	std::cin >> x;
	return x;
}
int n, vis[N], f[N], cnt;
int nex(int x) {
	int ans = 0;
	while(true) {
		if(!x) break;
		int t = x % 10;
		ans += t * t;
		x /= 10;
	}
	return ans;
}
void get_vis(int x) {
	int X = x;
	cnt++;
	while(true) {
		if(vis[x] || x == 1) break;
		vis[x] = cnt;
		x = nex(x);
	}
	if(x == 1 || (vis[x] != cnt && f[vis[x]])) {
		vis[X] = false;
		f[cnt] = true;
	}
}
int get_cnt(int x) {
	int ans = 0;
	while(true) {
		if(x == 1) break;
		ans++;
		x = nex(x);
	}
	return ans;
}
bool Prime(int x) {
	if(x == 1) return false;
	for(int i = 2; i <= sqrt(x); i++) {
		if(x % i == 0) return false;
	}
	return true;
}
void solve() {
	int L = read(), R = read(), Flag = false;
	for(int i = L; i <= R; i++) {
		if(vis[i]) continue;
		get_vis(i);
	}
	for(int i = L; i <= R; i++) {
		if(vis[i]) continue;
		int a = 1, b = 0;
		if(Prime(i)) a = 2;
		b = get_cnt(i);
		std::cout << i << ' ' << a * b << '\n';
		Flag = true;
	}
	if(!Flag) std::cout << "SAD";
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
