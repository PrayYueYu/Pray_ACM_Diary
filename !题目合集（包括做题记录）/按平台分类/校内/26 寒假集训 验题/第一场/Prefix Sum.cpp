#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 1e9 + 7, INF = 1e18;
int n, a[N][3], ans;
std::string s;
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

void solve() {
	double n, p, l, r;
	std::cin >> n >> p >> l >> r;
	printf("%.8lf", (r - l + 1) * p);
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:
f_{i,j}=C_{j-1}^{i-1}*p^{i}*(1-p)^{j-i}
(因为无论序列怎么变每个序列的概率都一样，一共C_{j-1}^{i-1}种不同序列)
即对于1~i的序列，其和为j的概率是多少
那么需要求的就是所有j在[l,r]内的f的和
那么令g_x=\sum f_{i,x}
可以发现g_x=p*(\sum p^{i}*(1-p)^{x-1-i}*C_{x-1}^{i})
由于\sum p^i*(1-p)^{n-i}*C_n^i=(p+1-p)^n=1
所以g_x=1
所以答案为g_l+g_{l+1}+...+g_r=(r-l+1)*p 
*/
