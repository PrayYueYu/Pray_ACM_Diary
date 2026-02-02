#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e6 + 9;
int n;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void solve() {
	n = read();
	if(n & 1) cout << "No\n";
	else cout << "Yes\n" << n / 2 << ' ' << n / 2 << '\n';
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = read();
	while(T--) solve();
    return 0;
}
