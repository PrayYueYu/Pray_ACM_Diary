#include<bits/stdc++.h>
#define int long long
#define double long double
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
double pi = acosl(-1.0L);
int n, f[N][22], cnt, k;
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
struct Dot {
	int x, y;
	double tan;
} s[N];
double getr(double x, double y) {
	return sqrt(x * x + y * y);
}
bool cmp(Dot x, Dot y) {
	if(x.tan == y.tan) {
		double r1 = getr(x.x, x.y);
		double r2 = getr(y.x, y.y);
		return r1 < r2;
	}
	return x.tan < y.tan;
}
std::vector<int> v[N];
int getmax(int x, int y) {
	double r1 = getr(s[x].x, s[x].y);
	double r2 = getr(s[y].x, s[y].y);
	if(r1 >= r2) return x;
	return y;
}
void init() {
	for(int i = 1; i <= cnt; i++) {
		f[i][0] = v[i][v[i].size() - 1];
	}
	for(int j = 1; j <= 20; j++) {
		for(int i = 1; i <= cnt; i++) {
			if(i + (1 << (j - 1)) > cnt) continue;
			f[i][j] = getmax(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int ST(int l, int r) {
	if(l > r) return 0;
	int p2 = log2(r - l + 1);
	return getmax(f[l][p2], f[r - (1 << p2) + 1][p2]);;
}
void solve() {
	n = read(), k = read();
	cnt = 0;
	for(int i = 1; i <= n; i++) {
		s[i].x = read(), s[i].y = read();
		s[i].tan = atan2((double)s[i].y, (double)s[i].x);
	}
	std::sort(s + 1, s + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		s[i + n].x = s[i].x;
		s[i + n].y = s[i].y;
		s[i + n].tan = s[i].tan + 2 * pi;
	}
	int lasx = 0, lasy = 0;
	for(int i = 1; i <= 2 * n; i++) {
		if(!lasx && !lasy) {
			int g = std::abs(std::__gcd(s[i].x, s[i].y));
			lasx = s[i].x / g, lasy = s[i].y / g;
			v[++cnt].push_back(i);
		}
		else {
			int g = std::abs(std::__gcd(s[i].x, s[i].y));
			if(lasx == (s[i].x / g) && lasy == (s[i].y / g));
			else cnt++;
			v[cnt].push_back(i);
			lasx = s[i].x / g, lasy = s[i].y / g;
		}
	}
	
	double ans = 100000000000000.0L;
	int l = 1, r = 2, lid = 0, rid = 0, num = 2;
	for(int i = 1; i <= cnt; i++) {
//		std::cout << v[i].size() << ": ";
//		for(auto x: v[i]) std::cout << s[x].x<<' ' << s[x].y << " | ";
//		std::cout << '\n';
		if(v[i].size() >= k) ans = 0;
	}
	double eps = 1e-13;
	if(ans == 0.0) {
		for(int i = 1; i <= cnt; i++) v[i].clear();
		printf("%.12Lf\n", ans + eps);
		return;
	}
	init();//³õÊ¼»¯st±í 
	
	while(true) {
		if(r > cnt || l > cnt) break;
		while(true) {
			if(num >= k || r > cnt) break;
			rid++, num++;
			if(rid == v[r].size()) {
				rid = 0;
				r++;
			}
		}
		while(true) {
			if(num <= k || r > cnt) break;
			rid--, num--;
			if(rid < 0) {
				r--;
				rid = v[r].size() - 1;
			}
		}
		if(r > cnt || l > cnt) break;
		int maxr = ST(l + 1, r - 1);
		maxr = getmax(getmax(v[l][lid], v[r][rid]), maxr);
//		std::cout << l << ' ' << lid << ' ';
//		std::cout << r << ' ' << rid << ' ';
//		printf("%d\n", s[maxr].x * s[maxr].x + s[maxr].y * s[maxr].y);
		double ar = s[v[r][rid]].tan - s[v[l][lid]].tan;
		double S = ar * (s[maxr].x * s[maxr].x + s[maxr].y * s[maxr].y) / 2.0;
		ans = std::min(ans, S);
		lid++;
		if(lid == v[l].size()) {
			num -= v[l].size();
			lid = 0;
			l++;
			if(l == r) {
				num -= (rid + 1);
				r++;
				rid = 0;
			}
			else {
				num -= v[l].size();
				num++;
			}
		}
		else num++;
	}
	printf("%.12Lf\n", ans);
	for(int i = 1; i <= cnt; i++) v[i].clear();
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
2
3 3
1 1
1 1
1 1

3 3
1 1
2 2
0 2

1
3 3
1 1
2 2
0 2

*/
