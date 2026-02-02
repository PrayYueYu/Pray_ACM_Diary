#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], m, k, vis[N];
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
struct fre {
	int x, y, z, f;
} s[N];
bool cmp1(fre x, fre y) {
	return x.x < y.x;
}
bool cmp2(fre x, fre y) {
	return (x.z - x.y) < (y.z - y.y);
}
void solve() {
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		s[i].x = read(), s[i].y = read(), s[i].z = read();
		k -= s[i].y;
		vis[i] = false;
		s[i].f = false;
	}
	sort(s + 1, s + n + 1, cmp1);
	sort(a + 1, a + m + 1);
	int now = 1, ans = 0;
	priority_queue<pair<int, int>> q;
	for(int i = 1; i <= m; i++) {
		int f = 0;
		for(int j = now; j <= n; j++) {
			if(s[j].x <= a[i]) {
				q.push({s[j].z - s[j].y, j});
			}
			else {
				now = j;
				f = true;
				break;
			}
		}
		if(!f) now = n + 1;
		if(!q.empty()) {
			int x = q.top().second;
			s[x].f = true;
			q.pop();
			ans++;
		}
	}
	sort(s + 1, s + n + 1, cmp2);
	for(int i = 1; i <= n; i++) {
		if(!s[i].f) {
			if(k >= s[i].z - s[i].y) {
				k -= (s[i].z - s[i].y);
				ans++;
			}
		}
	}
	cout << ans << '\n';
}
signed main() {
	int T = read();
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
