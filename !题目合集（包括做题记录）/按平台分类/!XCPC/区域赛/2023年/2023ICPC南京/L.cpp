#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 1e9 + 7, INF = 1e16; 
int n, k;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct Bg {
	int c, w, f;
} s[N];
bool cmp(Bg x, Bg y) {
	if(x.f == y.f) {
		return x.w < y.w;
	}
	return x.f > y.f;
}
signed main() {
	int T = read();
	int t = T, tot = 0;
	while(T--) {
		tot++;
		n = read(); k = read();
		for(int i = 1; i <= n; i++) {
			s[i].c = read(), s[i].w = read(), s[i].f = read();
		}
		sort(s + 1, s + n + 1, cmp);
		int ans = 0, now = 0, res = 0;
		for(int i = 1; i <= n; i++) {
			if(s[i].w == 2) {
				if(res >= 2) {
					int sub = min(s[i].c, res / 2);
					s[i].c -= sub;
					res -= sub * 2;
				}
			}
			else {
				if(res >= 1) {
					int sub = min(s[i].c, res);
					s[i].c -= sub;
					res -= sub;
				}
			}
			int W = s[i].c * s[i].w;
			if(!W) continue;
			if(!now) ans += s[i].f;
			if(now + W > k) {
				if(s[i].w == 2) {
					int e = k - now;
					int Max = e / 2;
					int d = min(s[i].c, Max);
					s[i].c -= d;
					now += d * 2;
					if(k - now == 1) {
						res++;
						now = 0;
					}
					if(s[i].c) {
						if(k % 2 == 0) {
							int e = k / 2;
							int x = s[i].c / e;
							int y = s[i].c % e;
							if(s[i].c % e != 0) x++;
							ans += s[i].f * x;
							now = y * 2;
						}
						else {
							int e = k / 2;
							int x = s[i].c / e;
							int y = s[i].c % e;
							if(s[i].c % e != 0) x++;
							ans += s[i].f * x;
							now = y * 2;
							res += x;
						}
					}
				}
				else {
					W -= (k - now);
					int x = W / k;
					int y = W % k;
					if(W % k != 0) x++;
					ans += s[i].f * x;
					now = y;
				}
			}
			else if(now + W == k) now = 0;
			else now += W;
		}
		cout << ans << endl;
	}
	return 0;
}
