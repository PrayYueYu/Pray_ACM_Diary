#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 2e6 + 10, mod = 998244353;
int n, m, fa[3][N], num[N], cnt, a[N], ls[N], ed[N];
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
void init() {
	for(int i = 0; i <= n + 5; i++) {
		for(int j = 1; j <= 2; j++) {
			fa[j][i] = 0;
		}
		ls[i] = num[i] = 0;
	}
}
int getfa(int x, int t) {
	if(x == fa[t][x]) return x;
	return fa[t][x] = getfa(fa[t][x], t);
}
void merge(int x, int y) {
	int fax = getfa(x, 1), fay = getfa(y, 1);
	if(fax == fay) return;
	fa[1][fax] = fay;
}
void mergex(int x, int y) {
	int fax = getfa(x, 2), fay = getfa(y, 2);
	if(fax == fay) {
		ed[fax]++;
		return;
	}
	fa[2][fax] = fay;
	num[fay] += num[fax];
	ed[fay] += ed[fax] + 1;
}
int ksm(int x, int y) {
	int ans = 1ll;
	while(y) {
		if(y & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ans;
}
struct S {
	int x, y;
} s[N];
bool cmp(S x, S y) {
	if(x.x == y.x) return x.y < y.y;
	return x.x < y.x;
}
int calc(int x) {
	int ans = ksm(m - 1, x - 1);
	ans = (ans * m) % mod;
	return ans;
}
void solve() {
	cnt = 0;
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		for(int j = 1; j <= 2; j++) {
			fa[j][i] = i;
		}
		num[i] = 1;
		ed[i] = 0;
	}
	int F = true;
	queue<pair<int, int>> q;
	for(int i = 1; i <= n; i++) {
		if(a[i] >= i) {
			F = false;
			break;
		}
		if(i == 1) continue;
		int j = a[i - 1];
		while(true) {
			if(!j || j + 1 == a[i]) break;
			q.push({i, j + 1});//不等 
			j = a[j];
		}
		if(j + 1 == a[i]) j++;
		if(j != a[i]) {
			F = false;
			break;
		}
		if(j) merge(i, j);//相等
		if(!j && !a[i]) q.push({i, 1});
//		if(j) cout << i << ' ' << j << endl;
	}//cout << endl;
	for(int i = 1; i <= n; i++) {
		int fai = getfa(i, 1);
		if(i == fai) {
			ls[i] = ++cnt;
		}
	}
	int val = 0;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int fax = getfa(x, 1), fay = getfa(y, 1);
		if(fax == fay) {
			F = false;
			break;
		}
		s[++val].x = min(ls[fax], ls[fay]);
		s[val].y = max(ls[fax], ls[fay]);
	}
	sort(s + 1, s + val + 1, cmp);
	for(int i = 1; i <= val; i++) {
		if(i >= 2 && (s[i].x == s[i - 1].x && s[i].y == s[i - 1].y)) continue;
		mergex(s[i].x, s[i].y);
	}
	if(!F) {
		cout << 0 << '\n';
		return;
	}
	int ans = 0;
	for(int i = 1; i <= cnt; i++) {
		int fai = getfa(i, 2);
		if(i == fai) {
			ans += calc(num[i]);
			ans %= mod;
//			cout << ed[i] << ' ' << num[i] << endl;
			if(ed[i] != num[i] - 1) {
				ans = (ans * ksm(m - 1, mod - 2)) % mod;
				if(m <= 2) ans = 0;
				else ans = (ans * (m - 2)) % mod;
			}
		}
	}
	cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------

1
7 3
0 0 0 1 2 3 0
*/
