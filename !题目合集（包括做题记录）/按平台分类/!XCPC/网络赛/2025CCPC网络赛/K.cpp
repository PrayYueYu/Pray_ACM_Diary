#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7;
int n, fa[N], ans, a[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void merge(int x, int y) {
	int fax = getfa(x), fay = getfa(y);
	if(fax == fay) return;
	fa[fax] = fay;
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		int tot = 0 ;
		for(int j = i; j >= 1; j--) a[++tot] = j;
		for(int j = n; j > i; j--) a[++tot] = j;
		for(int j = 1; j <= n; j++) fa[j] = j;
		for(int j = 1; j <= n; j++) {
			merge(j, a[j]);
		}
		for(int j = 1; j <= n; j++) {
			int faj = getfa(j);
			if(j == faj) ans++;
		}
	}
	cout << ans << '\n';
	for(int i = n; i >= 1; i--) cout << i << ' ';
    return 0;
}
