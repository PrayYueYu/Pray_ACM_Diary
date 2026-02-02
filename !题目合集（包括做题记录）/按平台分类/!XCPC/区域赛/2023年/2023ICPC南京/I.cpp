#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e6 + 100, M = 1e9 + 7, INF = 1e9; 
int n, m;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct ope {
	int a, b;
} s[N];
bool cmp(ope x, ope y) {
	return x.a < y.a;
}
signed main() {
	int T = read();
	while(T--) {
		n = read(), m = read();
		for(int i = 1; i <= m; i++) {
			s[i].a = read();
			s[i].b = read();
		}
		sort(s + 1, s + m + 1, cmp);
		int now = 0, st = 0, F = true;
		for(int i = 1; i <= m; i++) {
			int dst = s[i].a - st;
			int x = dst - s[i].b;
			if(x > 0) {
				now = s[i].b;
				st = s[i].a;
				continue;
			}
			if(s[i].b - now == dst) {
				now = s[i].b;
				st = s[i].a;
				continue;
			}
			F = false;
			break;
		}
		if(!F) cout << "No\n";
		else cout << "Yes\n"; 
	} 
	return 0;
} 
