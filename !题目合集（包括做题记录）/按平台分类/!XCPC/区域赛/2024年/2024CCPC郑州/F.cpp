#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const int N = 1e5 + 100;
int n, k, q, sum[N], a[N], b[N], num[N];
struct ANS {
	int d, h;
} ans[6][N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void solve(int id, int d, int h) {
	if(h == 1) {
		h = k;
		d = d - 1;
	}
	else h--;
	ans[num[id]][id].d = d;
	ans[num[id]][id].h = h;
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("2.out","w",stdout);
	n = read(), k = read(), q = read();
	int sumx = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		b[i] = read();
		sum[i] = sum[i - 1] + b[i];
		sumx += b[i];
	}
	int d = 1, h = 1, f = 0, Len = 0;
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= n; j++) {
			if(d < i) {
				d = i, h = 0;
				f = 1;
			}
			if(d == i) {
				
				if(h < a[j] && i == 2) f = 1;
				h = max(h, a[j]);
			}
			h += b[j];
			if(h > k) {
				h -= k;
				d++;
			}
			if(i == 2) Len = d - ans[i - 1][j].d;
			if(h == 1) {
				ans[i][j].d = d - 1;
				ans[i][j].h = k;
			}
			else {
				ans[i][j].d = d;
				ans[i][j].h = h - 1;
			}
		}
	}
	for(int i = 1; i <= q; i++) {
		int x = read(), y = read();
		if(x <= 2) {
			cout << ans[x][y].d << ' ' << ans[x][y].h << endl;
			continue;
		}
		if(!f) {
			int ansd = ans[1][n].d;
			int ansh = ans[1][n].h + sum[y] + (x - 2) * sumx;
			if(ansh % k == 0) {
				ansd += ansh / k - 1;
				ansh = k;
			}
			else {
				ansd += ansh / k;
				ansh %= k;
			}
			cout << ansd << " " << ansh << endl; 
			continue;
		}
		cout << ans[1][y].d + Len * (x - 1) << " ";
		cout << ans[2][y].h << endl;
	}
	return 0;
}
