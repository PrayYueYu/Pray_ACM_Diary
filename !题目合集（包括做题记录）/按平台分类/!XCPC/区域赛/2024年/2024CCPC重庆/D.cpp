#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 1e2 + 10, M = 1e6 + 9, INF = 1e18;
int a, b;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

void ExGcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    ll x1, y1;
    ExGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}
ll GetInv(ll a, ll Mod) {
    ll x, y;
    ExGcd(a, Mod, x, y);
    if(x < 0) x += Mod;
    return x;
}
void solve() {
	a = read(), b = read();
	int B = 1;
	while(true) {
		if(b % 2 == 0 && b) {
			b /= 2;
			B *= 2;
		}
		else break;
	}
	while(true) {
		if(b % 5 == 0 && b) {
			b /= 5;
			B *= 5;
		}
		else break;
	}
	int P = b;
	int Inv = 0, ansc = INF, ansd = 0;
	if(P >= 2) Inv = GetInv(B, P);
	else Inv = 0;
	for(int i = 0; i <= 30; i++) {
		int D = (1ll << i);
		for(int j = 0; ; j++) {
			if(D * P > 1e9) break;
			int now = ((-D * a) % P + P) % P;
			now = ((now * Inv) % P + P) % P;
			int g = __gcd(now, D * P);
			now /= g;
			if(now < ansc) {
				ansc = now;
				ansd = D * P / g;
			}
			D = D * 5ll;
		}
	}
	cout << ansc << ' ' << ansd << '\n';
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = read();
	while(T--) solve();
    return 0;
}
