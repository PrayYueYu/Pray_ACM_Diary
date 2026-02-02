#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7, INF = 1e18;
int n, m;
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
	n = read();
	priority_queue<int> q1, q2;
	for(int i = 1; i <= n; i++) {
		int x = read();
		if(x & 1) q1.push(x);
		else q2.push(x);
	}
	if(q1.empty()) {
		for(int i = 1; i <= n; i++) cout << 0 << ' ';
		cout << endl;
		return;
	}
	int ans = q1.top(); q1.pop();
	cout << ans << ' ';
	int cnt = 0, mine = 0;
	for(int i = 2; i <= n; i++) {
		if(!q2.empty()) {
			mine = q2.top();
			ans += mine;
			q2.pop();
			cout << ans << ' ';
			continue;
		}
		else {
			cnt++;
			if(cnt & 1) {
				if(!mine || i == n) cout << 0 << ' ';
				else cout << ans - mine << ' ';
			}
			else cout << ans << ' ';
		}
	}
	cout << '\n';
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
*/
