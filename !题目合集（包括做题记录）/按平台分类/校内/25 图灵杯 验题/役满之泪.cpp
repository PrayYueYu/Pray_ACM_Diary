#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7, INF = 1e18;
int a[100];
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
	for(int i = 1; i <= 13; i++) a[i] = read();
	int ans = 0;
	while(true) {
		int f1 = 0, f2 = 0, fx = 0;
		for(int i = 1; i <= 13; i++) {
			if(a[i] == 2) f2++;
			if(a[i] == 1) f1++;
			else fx++;
		}
		if((f1 == 11 && f2 == 1) || f1 == 13) {
			ans++;
			break;
		}
		ans++;
		int minn = INF, minid = 0, maxn = -1, maxid = 0, num = 0;
		for(int i = 1; i <= 13; i++) {
			num += a[i];
			if(minn > a[i]) {
				minn = a[i];
				minid = i;
			}
			if(maxn < a[i]) {
				maxn = a[i];
				maxid = i;
			}
		}
		if(num >= 13) a[maxid]--;
		a[minid]++;
	}
	cout << ans;
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
-------------------------------
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
-------------------------------
*/
