#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N];
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
	int maxn = 0;
	for(int i = 1; i <= 4; i++) {
		a[i] = read();
		maxn = std::max(maxn, a[i]);
	}
	int minn = read(), d = read(), cnt = 0, id = 0;
	for(int i = 1; i <= 4; i++) {
		if(a[i] < minn || maxn - a[i] > d) cnt++, id = i;
	}
	if(!cnt) std::cout << "Normal";
	else if(cnt == 1) std::cout << "Warning: please check #" << id << "!";
	else std::cout << "Warning: please check all the tires!";
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

*/
