#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[1010][1010], m, ans, p[10];
int p2x, p4x, p3x;
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
void init() {
	for(int i = 0; i <= n + 1; i++) {
		for(int j = 0; j <= m + 1; j++) {
			a[i][j] = 0;
		}
	}
}
struct S {
	int a, id;
} s[10];
bool cmp(S x, S y) {
	return x.a > y.a;
}
int dx[10] = {0, 0, 0, 1, -1};
int dy[10] = {0, 1, -1, 0, 0};
bool check(int x, int y) {
	if(x > y) std::swap(x, y);
	if((x == 1 && y == 2) || (x == 3 && y == 4)) return true;
	return false;
}
void calc(int x, int y) {
	if(!a[x][y]) return;
	if(a[x][y] == 1) {
		int cnt = 0, p1 = 0, p2 = 0;
		for(int i = 1; i <= 4; i++) {
			int t = a[x + dx[i]][y + dy[i]];
			if(t) {
				if(!p1) p1 = i;
				else p2 = i;
				cnt++;
			}
		}
		if(cnt == 0) ans += 21;
		else if(cnt == 1) ans += 20;
		else if(cnt == 2) {
			if((p1 == 1 && p2 == 2) || (p1 == 3 && p2 == 4)) {
				ans += 14;
			}
			else ans += 18;
		}
		else {
			if(cnt == 3) ans += 13;
			else ans += 7;
		}
		return;
	}
	for(int i = 1; i <= 4; i++) {
		s[i].id = i;
		int t = a[x + dx[i]][y + dy[i]];
		if(t >= a[x][y]) s[i].a = a[x][y] - 2;
		else s[i].a = std::max(t - 1, 0ll);
	}
	std::sort(s + 1, s + 4 + 1, cmp);
	if(s[1].a < a[x][y] - 2) {
		ans += (a[x][y] - 2 - s[1].a) * 14;
	}
	for(int i = 1; i <= 4; i++) {
		int d = s[i].a - s[i + 1].a;
		if(i != 2) {
			if(i == 1) ans += d * 13;
			if(i == 3) ans += d * 6;
		}
		else {
			if(check(s[1].id, s[2].id)) ans += d * 7;
			else ans += d * 11;
		}
	}
	int p1 = 0, p2 = 0, cnt = 0;
	for(int i = 1; i <= 4; i++) {
		int t = a[x + dx[i]][y + dy[i]];
		if(t >= a[x][y]) {
			if(!p1) p1 = i;
			else p2 = i;
			cnt++;
		}
	}
	if(cnt == 1) ans += 18;
	else if(cnt == 2) {
		if((p1 == 1 && p2 == 2) || (p1 == 3 && p2 == 4)) {
			ans += 13;
		}
		else ans += 15;
	}
	else {
		if(cnt == 3) ans += 11;
		else ans += p[5 - cnt];
	}
	
	p1 = 0, p2 = 0; cnt = 0;
	for(int i = 1; i <= 4; i++) {
		int t = a[x + dx[i]][y + dy[i]];
		if(t) {
			if(!p1) p1 = i;
			else p2 = i;
			cnt++;
		}
	}
	if(cnt == 1) ans += 18;
	else if(cnt == 2) {
		if((p1 == 1 && p2 == 2) || (p1 == 3 && p2 == 4)) {
			ans += 13;
		}
		else ans += 15;
	}
	else {
		if(cnt == 3) ans += 11;
		else ans += p[5 - cnt];
	}
}
void solve() {
	std::cin >> n >> m;
	ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			calc(i, j);
		}
	}
	std::cout << ans << '\n';
}
signed main() {
	p[6] = 21;
	p[5] = 20;
	p[0] = 0;
	p[1] = 6;
	p[3] = 13;
	p3x = 15;
	p[4] = 14;
	p4x = 18;
	p[2] = 7;
	p2x = 11;
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
