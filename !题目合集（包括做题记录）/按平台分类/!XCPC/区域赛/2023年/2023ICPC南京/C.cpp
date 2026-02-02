#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e6 + 100, M = 1e9 + 7, INF = 1e9; 
int n, m, P, p[100], sum[100];
int t, tot;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int check(int x) {
	if(x >= 0) return sum[x];
	return 0;
}
int calc(int L, int R) {
	int s1 = 0, s2 = 0;
	if(!L) s1 = 0;
	else {
		if((L - 1) % P == 0) s1 = (L - 1) / P;
		else s1 = (L - 1) / P + 1;
	}
	if(!R) s2 = -1;
	else s2 = (R - 1) / P;
	return s2 - s1 + 1;
}
void solve() {
	P = read(), m = read();

	int now = 0, ans = 0;
	for(int i = 62; i >= 0; i--) {
		int t1 = ((P - 1) >> i) & 1;
		int t2 = (m >> i) & 1;
		if(!t2) {
			if(t1) now += p[i];
			else now += 0;
			continue;
		}
		int L = 0, R = 0;
		if(t1) {
			int w = now + p[i];
			L = w, R = w + check(i - 1);
			ans += calc(L, R);
			now += 0;
		}
		else {
			int w = now;
			L = w, R = w + check(i - 1);
			ans += calc(L, R);
			now += p[i];
		}
	}
	if((now - 1) % P == 0) ans++;
	cout << ans << endl;
}
signed main() {
//	freopen("1.in", "r", stdin);
	p[0] = 1; sum[0] = 1;
	for(int i = 1; i <= 62; i++) {
		p[i] = p[i - 1] * 2ll;
		sum[i] = sum[i - 1] + p[i];
	}
	int T = read();
	t = T;
	while(T--) solve();
	return 0;
}
