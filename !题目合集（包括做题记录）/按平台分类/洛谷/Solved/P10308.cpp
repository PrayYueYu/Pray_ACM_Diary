#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e6 + 9;
int n, a[N], qx, ans[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
priority_queue<int> q;
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	n = read(), qx = read();
	ans[0] = 1;
	int ne = 0;
	for(int i = 1; i <= n; i++) {
		int x = log2(i);
		if((1 << x) == i) {
			ans[i] = i;
			ne = i * 2;
		}
		else ans[i] = ne;
	}
	int now = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(a[i]) q.push(-i);
	}
	q.push(-(n + 1));
	a[n + 1] = 1;
	for(int i = 1; i <= n + 1; i++) {
		if(a[i]) {
			now = i - 1;
			break;
		}
	}
	for(int i = 1; i <= qx; i++) {
		int x = read(), y = read();
		if(a[x] == y) {
			cout << ans[n - now] << '\n';
			continue;
		}
		a[x] = y;
		if(y) q.push(-x);
		while(!q.empty()) {
			int x = -q.top();
			q.pop();
			if(!a[x]) continue;
			now = x - 1;
			q.push(-x);
			break;
		}
		cout << ans[n - now] << '\n';
	}
    return 0;
}
