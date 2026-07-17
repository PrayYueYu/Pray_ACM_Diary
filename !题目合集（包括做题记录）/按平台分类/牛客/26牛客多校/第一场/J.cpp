#include<bits/stdc++.h>
#define y2 yyyy
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int t1[1000], t2[1000], n, vis[1000], win[3][100];
int cc1[10], cc2[10];
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
struct P {
	int a;
	int b;
} p1[10], p2[10], p3[10], p4[10];
int sti(std::string s) {
	return (t1[s[1]] - 1) * 13 + t2[s[0]];
}
bool cmp(P x, P y) {
	return x.b < y.b;
}
void init() {
	for(int i = 1; i <= 52; i++) {
		win[1][i] = win[2][i] = 0;
		vis[i] = false;
	}
}
int Type1() {
	int tonghua = true;
	int shunzi = true;
	for(int i = 2; i <= 5; i++) {
		if(p1[i].a != p1[i - 1].a) {
			tonghua = false;
			break;
		}
	}
	for(int i = 2; i <= 5; i++) {
		if(p1[i].b != p1[i - 1].b + 1) {
			shunzi = false;
			break;
		}
	}
	if(p1[5].b == 13) {
		int now = true;
		for(int i = 1; i <= 4; i++) {
			if(p1[i].b != i) {
				now = false;
				break;
			}
		}
		if(now) shunzi = 2;
	}
	if(shunzi && tonghua) {
		if(p1[1].b == 9) return 12;
		if(shunzi == 1) return 11;
		return 10;
	}
	if(p1[1].b == p1[4].b || p1[2].b == p1[5].b) {
		return 9;
	}
	if(p1[1].b == p1[3].b && p1[4].b == p1[5].b) {
		return 8;
	}
	if(p1[1].b == p1[2].b && p1[3].b == p1[5].b) {
		return 8;
	}
	if(tonghua) return 7;
	if(shunzi) {
		if(shunzi == 1) return 6;
		return 5;
	}
	if(p1[1].b == p1[3].b || p1[2].b == p1[4].b || p1[3].b == p1[5].b) {
		return 4;
	}
	int num = 0;
	for(int i = 2; i <= 5; i++) {
		if(p1[i].b == p1[i - 1].b) num++;
	}
	if(num == 2) return 3;
	if(num == 1) return 2;
	return 1;
}
int Type2() {
	int tonghua = true;
	int shunzi = true;
	for(int i = 2; i <= 5; i++) {
		if(p2[i].a != p2[i - 1].a) {
			tonghua = false;
			break;
		}
	}
	for(int i = 2; i <= 5; i++) {
		if(p2[i].b != p2[i - 1].b + 1) {
			shunzi = false;
			break;
		}
	}
	if(p2[5].b == 13) {
		int now = true;
		for(int i = 1; i <= 4; i++) {
			if(p2[i].b != i) {
				now = false;
				break;
			}
		}
		if(now) shunzi = 2;
	}
	if(shunzi && tonghua) {
		if(p2[1].b == 9) return 12;
		if(shunzi == 1) return 11;
		return 10;
	}
	if(p2[1].b == p2[4].b || p2[2].b == p2[5].b) {
		return 9;
	}
	if(p2[1].b == p2[3].b && p2[4].b == p2[5].b) {
		return 8;
	}
	if(p2[1].b == p2[2].b && p2[3].b == p2[5].b) {
		return 8;
	}
	if(tonghua) return 7;
	if(shunzi) {
		if(shunzi == 1) return 6;
		return 5;
	}
	if(p2[1].b == p2[3].b || p2[2].b == p2[4].b || p2[3].b == p2[5].b) {
		return 4;
	}
	int num = 0;
	for(int i = 2; i <= 5; i++) {
		if(p2[i].b == p2[i - 1].b) num++;
	}
	if(num == 2) return 3;
	if(num == 1) return 2;
	return 1;
}
int check(int a1, int b1, int a2, int b2) {
	p1[5].a = a1; p1[5].b = b1;
	p2[5].a = a2; p2[5].b = b2;
	std::sort(p1 + 1, p1 + 5 + 1, cmp);
	std::sort(p2 + 1, p2 + 5 + 1, cmp);
	int f1 = Type1(), f2 = Type2();
//	if(b2 == 7) {
//		std::cout << p1[1].b << ' ' << p1[2].b << ' ' << p1[3].b << ' ' << p1[4].b << '\n';
//		std::cout << a1 << ' ' << b1 << '\n';
//		std::cout << f2 << ' ' << f1 << '\n';
//	}
	if(f1 > f2) return 1;
	if(f2 > f1) return 2;
	if(f1 == 1) {
		for(int i = 5; i >= 1; i--) {
			if(p1[i].b > p2[i].b) return 1;
			else if(p1[i].b < p2[i].b) return 2;
		}
		return 3;
	}
	if(f1 == 2) {
		int x1 = 0, x2 = 0;
		for(int i = 2; i <= 5; i++) {
			if(p1[i].b == p1[i - 1].b) x1 = p1[i].b;
			if(p2[i].b == p2[i - 1].b) x2 = p2[i].b;
		}
		if(x1 > x2) return 1;
		if(x2 > x1) return 2;
		int cnt1 = 0, cnt2 = 0;
		for(int i = 1; i <= 5; i++) {
			if(p1[i].b != x1) cc1[++cnt1] = p1[i].b;
			if(p2[i].b != x2) cc2[++cnt2] = p2[i].b;
		}
		for(int i = 3; i >= 1; i--) {
			if(cc1[i] > cc2[i]) return 1;
			if(cc2[i] > cc1[i]) return 2;
		}
		return 3;
	}
	if(f1 == 3) {
		int x1 = 0, y1 = 0;
		int x2 = 0, y2 = 0;
		for(int i = 2; i <= 5; i++) {
			if(p1[i].b == p1[i - 1].b) {
				if(!x1) x1 = p1[i].b;
				else y1 = p1[i].b;
			}
			if(p2[i].b == p2[i - 1].b) {
				if(!x2) x2 = p2[i].b;
				else y2 = p2[i].b;
			}
		}
		if(y1 > y2) return 1;
		if(y2 > y1) return 2;
		if(x1 > x2) return 1;
		if(x2 > x1) return 2;
		int e1 = 0, e2 = 0;
		for(int i = 1; i <= 5; i++) {
			if(p1[i].b == x1 || p1[i].b == y1) continue;
			e1 = p1[i].b;
		}
		for(int i = 1; i <= 5; i++) {
			if(p2[i].b == x2 || p2[i].b == y2) continue;
			e2 = p2[i].b;
		}
		if(e1 > e2) return 1;
		if(e2 > e1) return 2;
		return 3;
	}
	if(f1 == 4) {
		int x1 = 0;
		int x2 = 0;
		x1 = p1[3].b;
		x2 = p2[3].b;
		if(x1 > x2) return 1;
		if(x2 > x1) return 2;
		int cnt1 = 0, cnt2 = 0;
		for(int i = 1; i <= 5; i++) {
			if(x1 == p1[i].b) continue;
			cc1[++cnt1] = p1[i].b;
		}
		for(int i = 1; i <= 5; i++) {
			if(x2 == p2[i].b) continue;
			cc2[++cnt2] = p2[i].b;
		}
		for(int i = 2; i >= 1; i--) {
			if(cc1[i] > cc2[i]) return 1;
			if(cc2[i] > cc1[i]) return 2;
		}
		return 3;
	}
	if(f1 == 5) return 3;
	if(f1 == 6) {
		if(p1[1].b > p2[1].b) return 1;
		if(p2[1].b > p1[1].b) return 2;
		return 3;
	}
	if(f1 == 7) {
		for(int i = 5; i >= 1; i--) {
			if(p1[i].b > p2[i].b) return 1;
			if(p2[i].b > p1[i].b) return 2;
		}
		return 3;
	}
	if(f1 == 8) {
		int x1 = p1[3].b, y1 = 0;
		int x2 = p2[3].b, y2 = 0;
		if(x1 == p1[1].b) y1 = p1[5].b;
		else y1 = p1[1].b;
		if(x2 == p2[1].b) y2 = p2[5].b;
		else y2 = p2[1].b;
		if(x1 > x2) return 1;
		if(x2 > x1) return 2;
		if(y1 > y2) return 1;
		if(y2 > y1) return 2;
		return 3;
	}
	if(f1 == 9) {
		int x1 = p1[3].b, y1 = 0;
		int x2 = p2[3].b, y2 = 0;
		if(x1 == p1[1].b) y1 = p1[5].b;
		else y1 = p1[1].b;
		if(x2 == p2[1].b) y2 = p2[5].b;
		else y2 = p2[1].b;
		if(x1 > x2) return 1;
		if(x2 > x1) return 2;
		if(y1 > y2) return 1;
		if(y2 > y1) return 2;
		return 3;
	}
	if(f1 == 10 || f1 == 12) return 3;

		if(p1[1].b > p2[1].b) return 1;
		if(p2[1].b > p1[1].b) return 2;
		return 3;
	
}
void solve() {
	std::string s;
	for(int i = 1; i <= 4; i++) {
		std::cin >> s;
		p1[i].b = t2[s[0]];
		p1[i].a = t1[s[1]];
		vis[sti(s)] = true;
	}
	for(int i = 1; i <= 4; i++) {
		std::cin >> s;
		p2[i].b = t2[s[0]];
		p2[i].a = t1[s[1]];
		vis[sti(s)] = true;
	}
//	std::cout << vis[34] << '\n';
	for(int a1 = 1; a1 <= 4; a1++) {
		for(int b1 = 1; b1 <= 13; b1++) {
//std::cout << p1[1].b << ' ' << p1[2].b << '\n';
			for(int a2 = 1; a2 <= 4; a2++) {
				for(int b2 = 1; b2 <= 13; b2++) {
					for(int i = 1; i <= 4; i++) {
						p4[i].a = p2[i].a;
						p4[i].b = p2[i].b;
						p3[i].a = p1[i].a;
						p3[i].b = p1[i].b;
					}
					int w1 = (a1 - 1) * 13 + b1;
					int w2 = (a2 - 1) * 13 + b2;
					if(vis[w1] || vis[w2] || w1 == w2) continue;
					int f = check(a1, b1, a2, b2);
					if(f == 1) win[1][w1]++;
					else if(f == 2) win[2][w2]++;
					for(int i = 1; i <= 4; i++) {
						p2[i].a = p4[i].a;
						p2[i].b = p4[i].b;
						p1[i].a = p3[i].a;
						p1[i].b = p3[i].b;
					}
					
				}
			}
		}
	}
	for(int i = 1; i <= 52; i++) {
		if(win[2][i] == 43) {
//			std::cout << i << '\n';
			std::cout << "GeiWoCaPiXie\n";
			return;
		}
	}
	int val = 0;
	for(int i = 1; i <= 52; i++) {
		if(win[1][i] == 43) {
			val++;
		}
	}
	if(val >= 2) std::cout << "WoYaoYanPai\n";
	else std::cout << "PaiMeiYouWenTi\n";
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	t1['C'] = 1; t1['D'] = 2;
	t1['S'] = 3; t1['H'] = 4;
	int cnt = 0;
	for(char i = '2'; i <= '9'; i++) {
		t2[i] = ++cnt;
	}
	t2['T'] = ++cnt; t2['J'] = ++cnt;
	t2['Q'] = ++cnt; t2['K'] = ++cnt;
	t2['A'] = ++cnt; 
	
	int T = 1; 
	std::cin >> T;
	getchar();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
3
AS KH KD AC AH KS KC AD
2D 3C 3D 2C AH QH JH 2H
4C 6H KH 9H 5H 6C 7H 9S
	Writer: ÔÂö§Þ±‹¬ 
*/
