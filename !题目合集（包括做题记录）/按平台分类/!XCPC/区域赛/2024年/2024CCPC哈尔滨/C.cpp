#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int n, ans2[N];
char ans1[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
char calc(char x, char y) {
	if(x == 'S') {
		if(y == 'E') return 'L';
		return 'R';
	}
	if(x == 'E') {
		if(y == 'N') return 'L';
		return 'R';
	}
	if(x == 'N') {
		if(y == 'W') return 'L';
		return 'R';
	}
	if(y == 'S') return 'L';
	return 'R';
}
void solve() {
	n = read();
	int num = 0, nd = 0;
	char fi = ' ', now = ' ';
	for(int i = 1; i <= n; i++) {
		char ch; cin >> ch;
		int f = read();
		if(i == 1) {
			fi = ch;
			now = ch;
			nd = f;
			continue;
		}
		ans1[++num] = 'Z';
		ans2[num] = nd;
		nd = f;
		if(now != ch) ans1[++num] = calc(now, ch);
		now = ch;
	}
	ans1[++num] = 'Z';
	ans2[num] = nd;
	cout << num << " " << fi << '\n';
	for(int i = 1; i <= num; i++) {
		cout << ans1[i];
		if(ans2[i]) cout << " " << ans2[i];
		cout << '\n';
	}
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
