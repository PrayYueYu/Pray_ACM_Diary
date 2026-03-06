#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 1e9 + 7, INF = 1e18;
int n, s, ne[N], to[N], fi[N], num;
int cnt1, cnt2, cnt0, ALL, tr[N], fac[N];
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
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
int lowbit(int x) {
	return x & (-x);
}
void Insert(int x, int y) {
	while(x <= n) {
		tr[x] += y;
		x += lowbit(x);
	}
}
int query(int x) {
	int ans = 0;
	while(x) {
		ans += tr[x];
		x -= lowbit(x);
	}
	return ans;
}
void dfs(int u, int fa) {
	int cnt = 0;
	Insert(u, 1);
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		cnt++;
		dfs(v, u);
	}
	cnt1 += query(n) - query(u);
	cnt0 += query(u - 1);
	Insert(u, -1);
	ALL = (ALL * fac[cnt]) % mod;
}
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ans;
}
void solve() {
	n = read(), s = read();
	fac[0] = 1; ALL = 1;
	for(int i = 1; i <= n + 2; i++) 
		fac[i] = (fac[i - 1] * i) % mod;
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v); add(v, u);
	}
	//可以发现每一个数对(x,y)（x>y）对答案的影响只有三种值
	//ALL、ALL/2、0
	//其中 ALL是总的dfs序情况数
	//如果 x是y的祖先，贡献是ALL
	//如果 y是x的祖先，贡献是0
	//其他情况贡献则为ALL/2
	//因此只需要算出ALL和 0的情况即可
	//用树状数组存一下
	//记录每个点它的所有祖先节点有哪些，这样就能快速计算
	//注意，如果是记录它的所有子节点，这样是非常困难的
	//所以记录的是祖先节点，具体方法见dfs中 Insert的位置
	//这样Insert就能保证当前在树状数组中的有且仅有它的祖先 
	dfs(s, 0);
	cnt2 = ((n * (n - 1)) / 2) - cnt1 - cnt0;
	cnt2 %= mod;
	int inv2 = ksm(2, mod - 2);
	int ans = cnt1 * ALL % mod;
	ans += cnt2 * ALL % mod * inv2 % mod;
	ans %= mod;
	std::cout << ans;
}
signed main() {
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
