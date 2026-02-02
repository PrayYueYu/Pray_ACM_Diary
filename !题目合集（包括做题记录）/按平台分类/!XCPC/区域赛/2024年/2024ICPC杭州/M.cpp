#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 2e6 + 10, M = 1e9 + 7, INF = 1e18;
int n, k, a[N], d[N], ans, sum, f[N], g[N], p[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void solve(int x, int y) {
	if(y <= x) return;
	if((y - x) > k) return;
	sum++;
	ans += y - x;
}
multiset<int> ms;
signed main() {
	int T = read();
	int Tx = T, ppt = 0, fft = 0;
	while(T--) {
		ppt++;
		n = read(), k = read();
		int Min = INF, Max = -INF;
		for(int i = 1; i <= n; i++) {
			a[i] = read();
			d[i] = abs(a[i] - a[i - 1]);
			f[i] = 0;
			g[i] = 0;
			Min = min(Min, a[i]);
			Max = max(Max, a[i]);
			if(Tx == 500 && ppt == 178 && fft) {
				cout << a[i] << " ";
			}
		}
		if(Tx == 500 && ppt == 178 && fft) {
			cout << endl;
		}
		ans = 0;
		sum = 0;
		if(n == 1 || Max == Min) {
			ans = k * (k + 1) / 2;
			cout << k << " " << ans << endl;
			continue;
		}
		int gd = d[2], cnt = 0;
		for(int i = 3; i <= n; i++) {
			gd = __gcd(gd, d[i]);
		}
		for(int i = 1; i <= sqrt(gd); i++) {
			if(gd % i == 0) {
				int t = i - Min;
				if(t >= 1 && t <= k) p[++cnt] = i - Min;
				t = gd / i - Min;
				if(i * i != gd) {
					if(t >= 1 && t <= k) {
						p[++cnt] = gd / i - Min;
					}
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			if(ms.empty()) {
				ms.insert(a[i]);
				f[i] = 0;
				continue;
			}
			auto it = ms.upper_bound(a[i]);
			if(it == ms.end()) f[i] = 0;
			else f[i] = (*it);
			while(true) {
				if(ms.empty()) break;
				it = ms.end(); it--;
				if((*it) >= a[i]) ms.erase(it);
				else break;
			}
			ms.insert(a[i]);
		}
		ms.clear();
		for(int i = n; i >= 1; i--) {
			if(ms.empty()) {
				g[i] = 0;
				ms.insert(a[i]);
				continue;
			}
			auto it = ms.upper_bound(a[i]);
			if(it == ms.end()) g[i] = 0;
			else g[i] = (*it);
			while(true) {
				if(ms.empty()) break;
				it = ms.end(); it--;
				if((*it) >= a[i]) ms.erase(it);
				else break;
			}
			ms.insert(a[i]);
		}
		ms.clear();
		for(int i = 1; i <= cnt; i++) {
			int F = true;
			for(int j = 1; j <= n; j++) {
				if(f[j]) {
					if((f[j] + p[i]) % (a[j] + p[i]) != 0) {
						F = false;
						break;
					}
				}
				if(g[j]) {
					if((g[j] + p[i]) % (a[j] + p[i]) != 0) {
						F = false;
						break;
					}
				}
			}
			if(F) sum++, ans += p[i];
		}
		cout << sum << " " << ans << endl;
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*
1
4 1000000000
1 7 23 5 

1
4 1000000000
25 1 11 19 

1
4 1000000000
18 2 22 10 
*/
