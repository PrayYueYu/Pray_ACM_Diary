#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, l, a[N];
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
std::multiset<int> ms;
void re_max() {
	if(ms.begin() == ms.end()) return;
	auto it = ms.end();
	it--;
	int x = (*it);
	ms.erase(it);
	ms.insert(0);
}
void erase_min() {
	if(ms.begin() == ms.end()) return;
	auto it = ms.begin();
	ms.erase(it);
}
void add_min() {
	if(ms.begin() == ms.end()) return;
	auto it = ms.begin();
	int x = (*it); x++;
	ms.erase(it);
	ms.insert(x);
}
int get_max() {
	if(ms.end() == ms.begin()) return -INF;
	auto it = ms.end();
	it--;
	return (*it);
}
void solve() {
	ms.clear();
	n = read(), m = read(), l = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	a[n + 1] = a[0] = 0;
	for(int i = 1; i <= m; i++) ms.insert(0);
	int re = n, nowt = 0;
	while(true) {
		if(re < m) {
			while(true) {
				if(ms.size() > re + 1) {
					erase_min();
				}
				else break;
			}
		}
		add_min();
		nowt++;
		if(nowt == a[n - re + 1]) {
			re--;
			re_max();
		}
		if(nowt == l) break;
	}
	std::cout << get_max() << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
