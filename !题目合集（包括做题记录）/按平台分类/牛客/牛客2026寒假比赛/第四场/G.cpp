#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int maxn[10] = {0, 60, 38, 26, 22};
int a[10] = {0, 2, 3, 5, 7};
int maxi, maxx = -INF;
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
int getcnt(int x) {
	int cnt = 0;
	while(true) {
		int sum = 1, px = x;
		while(true) {
			sum = sum * (x % 10);
			x /= 10;
			if(!x) break;
		}
		if(sum == px) break;
		cnt++;
		x = sum;
	}
	return cnt;
}
void dfs(int t, int now, int usen) {
	if(t == 5) {
		int cnt = getcnt(now);
		if(cnt > maxx && now != 937638166841712) {
			if(now == 4996238671872) return;
			maxx = cnt;
			maxi = now;
		}
		return;
	}
	int x = now;
	for(int i = 0; i <= std::min(maxn[t], 34ll); i++) {
		if(x > INF) break;
		dfs(t + 1, x, usen + i);
		x *= a[t];
	}
}
void solve() {
//	dfs(1, 1, 0);
//	std::cout << maxx << ' ' << maxi;
	std::cout << 44999999999977777 << ' ';
	std::cout << 84444444499777777;
}
//f(x)一定由2^{p1}*3^{p2}*5^{p3}*7^{p4}构成
//因为f(x)等于 位数的乘积 
//那么只需要枚举即可，再加上有位数限制，复杂度会比较低
//求出来两个最大的f(x) 
//就能逆推出来最大的那个是多少，注意8=2^3，9=3^2 
 
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
2^4 * 3^20 * 7^5
4^2 * 9^10 * 7^5
44999999999977777

2^1 * 4^9 * 9^2 * 7^6

*/
