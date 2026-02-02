#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e5 + 100, M = 998244353, INF = 1e18; 
int b[N], a[N], m, n, ans[20][N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct Array {
	int a, id;
} s[N];
bool cmp(Array x, Array y) {
	return x.a < y.a;
}
void update(int t, int l, int r, int op) {
	if(l > r) return;
	if(!op) {
		for(int i = l; i <= r; i++) ans[t][i] = 0;
		return;
	}
	else {
		for(int i = l; i <= r; i++) {
			ans[t][i] = a[i];
			a[i] = 0;
		}
	}
	return;
} 
void init() {
	for(int i = 0; i <= 18; i++) {
		for(int j = 1; j <= n; j++) ans[i][j] = 0;
	}
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	int f = true, num = 0;
	int L = 1, R = n;
	while(true) {
		int cnt = 0, p = 0;
		num++;
		for(int i = 1; i <= n; i++) {
			if(!a[i]) cnt++;
			else b[++p] = a[i];
		}
		if(cnt == n) break;
		if(p == 1) {
			f = false;
			break;
		}
		if(p == 2) {
			if(b[1] != b[2]) {
				f = false;
				break;
			}
		}
		if(cnt == n) break;
		int Min = INF, mid = 0;
		int Ml = 0, Mr = 0;
		int suml = 0, sumr = 0;
		for(int i = R; i >= L; i--) sumr += a[i];
		for(int i = L; i < R; i++) {
			suml += a[i];
			sumr -= a[i];
			int sl = suml;//[L,i]
			int sr = sumr;//[i+1,R]
			if(abs(sr - sl) < Min) {
				Min = abs(sr - sl);
				mid = i;
				Ml = sl;
				Mr = sr;
			}
		}
		int sl = Ml;
		int sr = Mr;
		int res = 0, tot = 0;
		update(num, 1, L - 1, 0);
		update(num, R + 1, n, 0);
		if(sr == sl) {
			update(num, L, mid, 1);
			update(num, mid + 1, R, 1);
			break;
		}
		else if(sr > sl) {
			update(num, L, mid, 1);
			res = sl;
			for(int i = mid + 1; i <= R; i++) {
				s[++tot].a = a[i];
				s[tot].id = i;
			}
			L = mid + 1;
		}
		else {
			update(num, mid + 1, R, 1);
			res = sr;
			for(int i = L; i <= mid; i++) {
				s[++tot].a = a[i];
				s[tot].id = i;
			}
			R = mid;
		}
		if(tot == 1) {
			f = false;
			break;
		}
		sort(s + 1, s + tot + 1, cmp);
		int now = min(res, s[tot].a - s[tot - 1].a); 
		ans[num][s[tot].id] = now;
		res -= now;
		s[tot].a -= now;
		a[s[tot].id] -= now;
		for(int i = 1; i <= tot - 2; i++) {
			if(!res) break;
			now = min(res, s[i].a);
			ans[num][s[i].id] += now;
			res -= now;
			a[s[i].id] -= now;
		}
		if(!res) continue;
		int p1 = min(res / 2, s[tot - 1].a);
		int p2 = min(res / 2 + (res & 1), s[tot].a);
		ans[num][s[tot - 1].id] += p1;
		a[s[tot - 1].id] -= p1;
		ans[num][s[tot].id] += p2;
		a[s[tot].id] -= p2;
	}
	if(!f) {
		cout << -1 << endl;
		return;
	}
	cout << num << endl;
	for(int i = 1; i <= num; i++) {
		for(int j = 1; j <= n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*
1 1000000000yy
6
1 2 3 4 5 6
*/
