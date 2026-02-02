#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 2e6 + 10, M = 1e9 + 7, INF = 1e18;
int n, f, ans[N], vis[N], L[N], R[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct fl {
	int l, r, id;
} s[N];
bool cmp(fl x, fl y) {
	if(x.l == y.l) return x.r > y.r;
	return x.l < y.l;
} 
bool cmp2(fl x, fl y) {
	return x.r > y.r;
}
signed main() {
	int T = read();
	while(T--) {
		n = read(), f = read();
		int sum = 0, cnt = 0, r = f, idx = 0;
		R[0] = f;
		for(int i = 1; i <= n; i++) {
			s[i].l = read();
			s[i].r = read();
			L[i] = s[i].l;
			R[i] = s[i].r;
			s[i].id = i;
			sum += s[i].r - s[i].l;
			vis[i] = false;
		}
		sort(s + 1, s + n + 1, cmp);
		for(int i = 1; i <= n; i++) {
			if(s[i].r > r) {
				sum += max(s[i].l - r, 0ll);
				r = s[i].r;
				vis[s[i].id] = true;
				ans[++cnt] = s[i].id;
			}
		}
		sort(s + 1, s + n + 1, cmp2);
		for(int i = 1; i <= n; i++) {
			if(vis[s[i].id]) continue;
			ans[++cnt] = s[i].id;
		}
		cout << sum << endl;
		for(int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	//	cout << check() << endl;
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*
1
19 52
51 98
2 83
40 58
96 99
39 55
72 94
15 17
4 15
48 99
2 99
77 78
35 77
44 62
79 81
30 31
1 48
48 76
68 99
60 66
*/
