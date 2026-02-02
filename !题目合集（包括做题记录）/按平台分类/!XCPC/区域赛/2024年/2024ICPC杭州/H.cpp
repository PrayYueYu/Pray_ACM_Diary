#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 2e6 + 10, M = 1e9 + 7, INF = 1e18;
int n, k, fa[N], num[N], Max[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct He {
	int l, r, len;
} s[N];
bool cmp(He x, He y) {
	return x.len > y.len;
}

signed main() {
	int T = read();
	while(T--) {
		n = read(), k = read();
		for(int i = 1; i <= n; i++) {
			fa[i] = 0;
			num[i] = 0;
			Max[i] = 0;
		}
		int f = true;
		for(int i = 1; i <= k; i++) {
			s[i].l = read(), s[i].r = read();
			s[i].len = s[i].r - s[i].l + 1;
			for(int j = s[i].l; j <= s[i].r; j++) {
				if(j != s[i].l) fa[j] = j - 1;
			}
		}
		sort(s + 1, s + k + 1, cmp);
		if(n == 1) {
			cout << 0 << endl;
			continue;
		}
		int now = s[1].r, t = k;
		num[s[1].r] = 0;
		fa[s[1].l] = 0;
		while(true) {
			if(t == 1 || !now) break;
			while(true) {
				if(t == 1 || !now) break;
				if(s[t].len <= Max[now]) {
					fa[s[t].l] = now;
					num[now] += s[t].len;
					t--;
				}
				else {
					num[fa[now]] = num[now] + 1;
					Max[fa[now]] = num[now] + 1;
					now = fa[now];
					break;
				}
			}
		}
		int res = 0;
		for(int i = 1; i <= n; i++) {
			if(!fa[i]) res++;
		}
		if(res >= 2) cout << "IMPOSSIBLE\n";
		else {
			for(int i = 1; i <= n; i++) {
				cout << fa[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*
1
12 4
1 3
4 6
7 9
10 12

1
6 3
4 6
2 3
1 1

8999 3
1 3000
3001 6000
6001 8999
*/
