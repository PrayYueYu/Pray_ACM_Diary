#include<bits/stdc++.h>
const int N = 6e5 + 10, mod = 998244353, INF = 1e9;
int a[500005], b[500005], maxn[500005], n;
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
std::set<int> s, sd;
struct S {
	int a, id;
} shabi_tts[500005];
bool cmp(S x, S y) {
	if(x.a == y.a) return x.id < y.id;
	return x.a < y.a;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		s.insert(a[i]);
		shabi_tts[i].a = a[i];
		shabi_tts[i].id = i;
	}
	std::sort(shabi_tts + 1, shabi_tts + n + 1, cmp);
	for(int i = 1; i <= n; i++) b[i] = read();
	int lasl = 0, nowr = 0;
	for(auto x: s) {
		for(int i = lasl + 1; ; i++) {
			if(shabi_tts[i].a != shabi_tts[lasl + 1].a) {
				nowr = i - 1;
				break;
			}
		}
		for(int i = lasl + 1; i <= nowr; i++) {
			int y = shabi_tts[i].id;
			auto itl = sd.lower_bound(y);
			auto itr = itl;
			int l = 0, r = 0;
			if(itl == sd.begin()) l = 0;
			else {
				itl--;
				l = (*itl);
			}
			if(itr == sd.end()) r = n + 1;
			else r = (*itr);
			int len = r - l - 1;
			maxn[len] = std::max(maxn[len], x);
		}
		for(int i = lasl + 1; i <= nowr; i++) {
			int y = shabi_tts[i].id;
			sd.insert(y);
		}
		lasl = nowr;
	}
	for(int i = n - 1; i >= 1; i--) {
		maxn[i] = std::max(maxn[i], maxn[i + 1]);
	}
	for(int i = 1; i <= n; i++) {
		if(maxn[i] >= b[i]) std::cout << 1;
		else std::cout << 0;
	}
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
