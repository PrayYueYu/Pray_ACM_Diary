#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int a[1200][1200], n, m, g[N], cnt[N];
double fA[N], fB[N];
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
int to(int x) {
	x = std::abs(x);
	if(x == 1 && g[1] == -1) std::cout << "-";
	if(g[x] == 1) return x - 1;
	return -(x - 1);
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		cnt[i] = read();
		for(int j = 1; j <= cnt[i]; j++) {
			std::string s;
			std::cin >> s;
			int x = 0;
			for(int k = 0;  k < s.size(); k++) {
				if(s[k] == '-') continue;
				x = x * 10 + s[k] - '0';
			}
			x = std::abs(x) + 1;
			if(s[0] == '-') g[x] = -1;
			else g[x] = 1;
			a[i][j] = x;
		}
	}
	int A = read(), B = read();
	if(A > 0) g[-B + 1] = -1;
	if(A < 0) g[B + 1] = 1;
	if(B > 0) g[-A + 1] = -1;
	if(B < 0) g[A + 1] = 1;
	A = std::abs(A) + 1, B = std::abs(B) + 1;
	for(int i = 1; i <= m; i++) {
		int f1 = 0, f2 = 0;
		for(int j = 1; j <= cnt[i]; j++) {
			if(a[i][j] == A) f1 = true;
			if(a[i][j] == B) f2 = true;
		}
		for(int j = 1; j <= cnt[i]; j++) {
			if(f1 && g[a[i][j]] != g[A]) {
				fA[a[i][j]] += 1.0 / (double)cnt[i];
			}
			if(f2 && g[a[i][j]] != g[B]) {
				fB[a[i][j]] += 1.0 / (double)cnt[i];
			}
		}
	}
	double maxnA = -1, maxnB = -1;
	for(int i = 1; i <= n; i++) {
		if(maxnA < fA[i] && g[i] != g[A]) {
			maxnA = fA[i];
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(maxnB < fB[i] && g[i] != g[B]) {
			maxnB = fB[i];
		}
	}
	if(maxnB == fB[A] && maxnA == fA[B]) {
		std::cout << to(A) << ' ' << to(B);
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(fA[i] == maxnA && g[i] != g[A]){
			std::cout << to(A) << ' ' << to(i) << '\n';
		}
	}
	for(int i = 1; i <= n; i++) {
		if(fB[i] == maxnB && g[i] != g[B]) {
			std::cout << to(B) << ' ' << to(i) << '\n';
		}
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
