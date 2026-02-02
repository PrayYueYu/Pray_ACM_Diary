#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e5 + 10, mod = 1e9 + 7, INF = 1e18;
int n, cnt1[N], cnt2[N], vis[1000];
std::string s[N];
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
int tot;
struct S {
	int c, cnt;
} sx[N];
bool cmp(S x, S y) {
	return x.cnt > y.cnt;
}
int calc(int t, int len) {
	int ans = 0;
	for(int i = 7 - len; i <= 6; i++) {
		ans = ans * 10 + s[t][i] - '0';
	}
	return ans;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		std::cin >> s[i];
		s[i] = " " + s[i];
		cnt1[calc(i, 2)]++;
		cnt2[calc(i, 4)]++;
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[calc(i, 2)]) {
			vis[calc(i, 2)] = true;
			sx[++tot].c = calc(i, 2);
			sx[tot].cnt = cnt1[calc(i, 2)];
		}
	}
	std::sort(sx + 1, sx + tot + 1, cmp);
	int ans = 300000;
	for(int i = 0; i <= 9999; i++) {
		int s1 = 0, s2 = 0, s3 = 0;
		int t = i % 100;
		if(t == sx[1].c) {
			s1 = sx[2].cnt;
			s2 = sx[3].cnt;
			s3 = sx[4].cnt;
		}
		else if(t == sx[2].c) {
			s1 = sx[1].cnt;
			s2 = sx[3].cnt;
			s3 = sx[4].cnt;
		}
		else if(t == sx[3].c) {
			s1 = sx[1].cnt;
			s2 = sx[2].cnt;
			s3 = sx[4].cnt;
		}
		else {
			s1 = sx[1].cnt;
			s2 = sx[2].cnt;
			s3 = sx[3].cnt;
		}
		int now = (s1 + s2 + s3) * 500 + cnt2[i] * 4000;
		if(s1 + s2 + s3 + cnt1[t] != n) {
			now += 300000;
		}
		else {
			int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
			t1 = t2 = t3 = t4 = 300000;
			if(s1) t1 += (s2 + s3) * 500 + cnt2[i] * 4000;
			if(s2) t2 += (s1 + s3) * 500 + cnt2[i] * 4000;
			if(s3) t3 += (s1 + s2) * 500 + cnt2[i] * 4000;
			if(cnt2[i]) t4 += (s1 + s2 + s3) * 500;
			now = std::max({now, t1, t2, t3, t4});
		}
		ans = std::max(ans, now);
	}
	std::cout << ans;
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
