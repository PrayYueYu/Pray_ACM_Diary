#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7, INF = 1e18;
int n, a[N], b[N], ax[N], bx[N];
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
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) b[i] = read();
	int cnt = 0, numa = 0, numb = 0;
	a[n + 1] = b[n + 1] = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] + 1 == a[i + 1]) cnt++, i++;
		else ax[++numa] = a[i] - 2 * cnt;
	}
	cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(b[i] + 1 == b[i + 1]) cnt++, i++;
		else bx[++numb] = b[i] - 2 * cnt;
	}
	if(numa != numb) cout << "NO\n";
	else {
		int f = true;
		for(int i = 1; i <= numa; i++) {
			if(ax[i] != bx[i]) {
				f = false;
				break;
			}
		}
		if(f) cout << "YES\n";
		else cout << "NO\n";
	}
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
/*
-------------------------------
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
-------------------------------
*/
