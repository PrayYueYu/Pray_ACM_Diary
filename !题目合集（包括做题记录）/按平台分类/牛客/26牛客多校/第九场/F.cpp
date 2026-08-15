#include<bits/stdc++.h>
#define int long long
#define y2 y222
#define y1 y111
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int maxn[N], n, p[N];
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
int cnt;
struct S {
	int x1, x2, y1, y2, t, t1, t2, t3, t4;
} s[N];
int fc(int t) {
	return s[t].x2 - s[t].x1;
}
bool check() {
	if(cnt <= 1) return false; 
	int x1 = s[cnt - 1].x2, x2 = s[cnt].x1;
	if(x1 + 1 != x2) return false;
	int y1 = s[cnt - 1].y1, y2 = s[cnt].y2;
	if(y1 - 1 == y2) return true;
	y1 = s[cnt - 1].y2, y2 = s[cnt].y1;
	if(y1 + 1 == y2) return true;
	return false;
}
void clea() {
	s[cnt].t = 0;
	s[cnt].t = s[cnt].t1 = s[cnt].t2 = s[cnt].t3 = s[cnt].t4 = 0;
	cnt--;
}
void insert(int x) {
	cnt++;
	s[cnt].x1 = s[cnt].x2 = x;
	s[cnt].y1 = s[cnt].y2 = p[x];
	s[cnt].t = s[cnt].t1 = s[cnt].t2 = s[cnt].t3 = s[cnt].t4 = 0;
}
void Print(int x) {
	std::cout << s[x].x1 << ' ' << s[x].y1 << ' ' << s[x].x2 << ' ' << s[x].y2 << ' ';
}
void merge() {
	int d2 = s[cnt].x2 - s[cnt].x1 + 1;
	int d1 = s[cnt - 1].x2 - s[cnt - 1].x1 + 1;
	int len = s[cnt].x2 - s[cnt - 1].x1;
	if(s[cnt].y1 > s[cnt - 1].y2) {
		int s1 = std::max(s[cnt - 1].t4, s[cnt].t1) + len;
		int s2 = s[cnt - 1].t3 + d2;
		int s3 = s[cnt].t3 + d1;
		s[cnt - 1].t3 = std::max({s1, s2, s3});
		s2 = s[cnt - 1].t2 + d2;
		s3 = s[cnt].t2 + d1;
		s[cnt - 1].t2 = std::max({s1, s2, s3});
		s[cnt - 1].t4 = s[cnt].t4;
	}
	else {
		int s1 = std::max(s[cnt - 1].t3, s[cnt].t2) + len;
		int s2 = s[cnt - 1].t1 + d2;
		int s3 = s[cnt].t1 + d1;
		s[cnt - 1].t1 = std::max({s1, s2, s3});
		s2 = s[cnt - 1].t4 + d2;
		s3 = s[cnt].t4 + d1;
		s[cnt - 1].t4 = std::max({s1, s2, s3});
		s[cnt - 1].t3 = s[cnt].t3;		
	}
	
	s[cnt - 1].t = std::max({s[cnt - 1].t1, s[cnt - 1].t2, s[cnt - 1].t3, s[cnt - 1].t4});
	s[cnt - 1].x1 = std::min(s[cnt - 1].x1, s[cnt].x1);
	s[cnt - 1].y1 = std::min(s[cnt - 1].y1, s[cnt].y1);
	s[cnt - 1].x2 = std::max(s[cnt - 1].x2, s[cnt].x2);
	s[cnt - 1].y2 = std::max(s[cnt - 1].y2, s[cnt].y2);
//	Print(cnt - 1); std::cout << " | ";
//	std::cout << s[cnt - 1].t1 << ' ' << s[cnt - 1].t2 << ' ' << s[cnt - 1].t3 << ' ' << s[cnt - 1].t4 << '\n';
	clea();
//	s[cnt].t = std::max({s[cnt].t1, s[cnt].t2, s[cnt].t3, s[cnt].t4});
//	s[cnt].t += fc(cnt);
	
}
bool dfs() {
	int now = 1;
	while(true) {
		if(now > n) break;
		insert(now); now++;
		while(true) {
			if(now > n) break;
			insert(now);
			if(check()) {
				merge();
				now++;
//				break;
			}
			else {
				clea();
				break;
			}
		}
		while(true) {
			if(check()) {
				merge();
			}
			else break;
		}
	}
	if(cnt == 1) return true;
	return false;
}
void solve() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}
	if(dfs()) {
//		int ans = 0;
//		for(int i = 1; i <= n; i++) {
////			std::cout << maxn[i] << '\n';
//			ans += maxn[i];
//		}
//		std::cout << ans;
		std::cout << s[1].t << '\n';
		return;
	}
	std::cout << -1;
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	int T = 1; 
//	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
8
4 5 3 6 2 7 1 8

10
2 4 3 1 5 6 8 9 10 7

4
1 3 2 4

6
6 1 5 3 4 2
----------------------
	Writer: ÔÂö§Ş±‹¬ | 
----------------------
*/
