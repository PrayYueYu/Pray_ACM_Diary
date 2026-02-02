#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7;
int x[N], y[N], x0;
int n;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}

void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		x[i] = read(), y[i] = read();
	}
	int x0 = read(), minn = 2e12, id = 0;
	for(int i = 1; i <= n; i++) {
		int s1 = i, s2 = i % n + 1;
		if(min(x[s1], x[s2]) <= x0 && x0 <= max(x[s1], x[s2])) {
			if(min(y[s1], y[s2]) < minn) {
				minn = min(y[s1], y[s2]);
				id = i;
			}
		}
	}
	cout << id << ' ' << id % n + 1;
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
