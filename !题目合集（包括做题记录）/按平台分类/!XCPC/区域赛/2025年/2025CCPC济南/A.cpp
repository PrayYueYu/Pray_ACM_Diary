#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7;
int n, p[100];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int getctz(int x) {
	return __builtin_ctzll(x);
}
void solve() {
	int a, b;
	cin >> a >> b;
	if(b == 1) {
		cout << 0 << '\n';
		return;
	}
	if(!a) {
		if(!b) cout << 1 << '\n';
		else cout << "broken message\n";
		return;
	}
	if(!(a & 1)) {
		int now = 1;
		for(int i = 0; i <= 64; i++) {
			if(now == b) {
				cout << i << '\n';
				return;
			}
			now *= a;
		}
		cout << "broken message\n";
		return;
	}
	int x = 0, now = a, nowx = 1;
	for(int i = 0; i <= 63; i++) {
		int ctz = getctz(now - 1);
		if(now == 1) {
			if(nowx == b) {
				cout << x << '\n';
				return;
			}
			cout << "broken message\n";
			return;
		}
		if((nowx >> ctz & 1) != (b >> ctz & 1)) {
			x += p[i];
			nowx = nowx * now;
		}
		now = now * now;
	}
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	p[0] = 1;
	for(int i = 1; i <= 63; i++) p[i] = p[i - 1] * 2ull;
	int T = read();
	while(T--) solve();
    return 0;
}
