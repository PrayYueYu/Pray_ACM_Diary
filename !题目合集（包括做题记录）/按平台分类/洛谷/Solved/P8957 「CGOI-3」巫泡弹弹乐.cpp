#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
int n, f[N], id[N], ansu[N], ansv[N];
int read() {
	int x;
	cin >> x;
	return x;
}
struct Dot {
	int a, b, id;
} s[N];
bool cmp(Dot x, Dot y) {
	return x.a < y.a;
}
signed main() {
	n = read();
	for(int i = 1; i <= n; i++) s[i].a = read();
	for(int i = 1; i <= n; i++) {
		s[i].b = read();
		s[i].id = i;
	}
	sort(s + 1, s + n + 1, cmp);
	f[1] = s[1].b;
	id[1] = 1;
	for(int i = 2; i <= n; i++) {
		f[i] = f[i - 1];
		id[i] = id[i - 1];
		if(f[i] > s[i].b) {
			f[i] = s[i].b;
			id[i] = i;
		}
	}
	int ans = 0;
	for(int i = n; i >= 2; i--) {
		ansu[i - 1] = i;
		ansv[i - 1] = id[i - 1];
		ans += s[i].a + max(s[i].b, f[i - 1]);
	}
	cout << ans << '\n';
	for(int i = 1; i < n; i++) {
		cout << s[ansu[i]].id << ' ' << s[ansv[i]].id << '\n';
	}
	return 0;
}
/*
10
23 52 634 6 34 63 234 5324 6 24
23 5 65 65 23 42 64 65 7 5
*/
