#include<bits/stdc++.h>
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7;
int n, a[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
map<int, int> mp;
void solve() {
	n = read();
	mp.clear();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for(int i = 2; i < n; i++) mp[a[i]]++;
	for(int i = 2; i <= n; i++) {
		int x = a[n] - a[i] + a[1];
		if(x < a[i]) continue;
		if(x == a[i] && mp[x] >= 2) {
			cout << "Yes\n";
			return;
		}
		if(x != a[i] && mp[x]) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}
signed main() {
	int T = read(), id = read();
	while(T--) solve();
	return 0;
}

/*

*/
