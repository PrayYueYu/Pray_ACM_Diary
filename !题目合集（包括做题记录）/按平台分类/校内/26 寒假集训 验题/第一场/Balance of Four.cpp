#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 5e6 + 10, mod = 1e9 + 7, INF = 1e18;
int n, a[200005], cnt[N];
std::vector<std::pair<int, int>> v[N];
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
struct S {
	int a, id;	
} s[200005];
bool cmp(S x, S y) {
	return x.a < y.a;
}
void solve() {
	n = read();
	int num = 0, f = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		s[i].a = a[i];
		s[i].id = i;
		cnt[a[i]]++;
		if(cnt[a[i]] == 2) {
			num++;
		}
		if(cnt[a[i]] == 4) f = a[i];
	}
	if(f) {
		std::cout << "YES\n";
		int cnt = 4;
		for(int i = 1; i <= n; i++) {
			if(a[i] == f && cnt) {
				std::cout << i << ' ';
				cnt--;
			}
		}
		return;
	}
	if(num >= 2) {
		std::cout << "YES\n";
		int p1 = 0, p2 = 0;
		for(int i = 1; i <= n; i++) {
			if(!p1 && cnt[a[i]] >= 2) p1 = a[i];
			else if(!p2 && cnt[a[i]] >= 2 && a[i] != p1)
				p2 = a[i];
		}
		int f11 = 0, f12 = 0, f21 = 0, f22 = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i] == p1) {
				if(!f11) f11 = i;
				else if(!f12) f12 = i;
			}
			if(a[i] == p2) {
				if(!f21) f21 = i;
				else if(!f22) f22 = i;
			}
		}
		std::cout << f11 << ' ' << f21 << ' ' << f12 << ' ' << f22;
		return;
	}
	std::sort(s + 1, s + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int d = s[j].a - s[i].a;
			if(v[d].size() >= 1) {
				for(auto x: v[d]) {
					if(x.first != j && x.first != i) {
						if(x.second != j && x.second != i) {
							std::cout << "YES\n";
							std::cout << s[i].id << ' ' << s[x.second].id << ' ' << s[j].id << ' ' << s[x.first].id;
							return;
						}
					}
				}
			}
			v[d].push_back({i, j});
		}
	}
	std::cout << "NO";
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
