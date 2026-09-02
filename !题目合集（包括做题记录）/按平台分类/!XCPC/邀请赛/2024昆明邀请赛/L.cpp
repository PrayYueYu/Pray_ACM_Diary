#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int cnt, tr[N], n, p, q, a[N], re[N], f[N];
struct S {
	int x, y;
} s[N];
bool cmp(S x, S y) {
	if(x.x == y.x) return x.y < y.y;
	return x.x < y.x;
}
int lowbit(int x) {return x & (-x);}
int query(int x) {
	int ans = 0;
	while(x) {
		ans = std::max(ans, tr[x]);
		x -= lowbit(x);
	}
	return ans;
}
void add(int x, int y) {
	while(x <= cnt) {
		tr[x] = std::max(tr[x], y);
		x += lowbit(x);
	}
}
std::map<int, int> mp;
std::vector<int> v[N];
int calc(int x1, int y1, int x2, int y2) {
	if(x1 > x2 || y1 > y2) return 0;
	return (x2 - x1 + 1) * (y2 - y1 + 1);
}
void solve() {
	mp.clear();
	std::cin >> n >> p >> q;
	int num = 0; cnt = 0;
	for(int i = 1; i <= n; i++) {
		std::cin >> s[i].x >> s[i].y;
		a[++num] = s[i].y;
	}
	std::sort(a + 1, a + num + 1);
	for(int i = 1; i <= num; i++) {
		if(!mp[a[i]]) {
			mp[a[i]] = ++cnt;
			re[cnt] = a[i];
		}
	}
	for(int i = 1; i <= cnt; i++) tr[i] = 0;//Çå¿Õ 
	for(int i = 1; i <= n; i++) {
	 	s[i].y = mp[s[i].y];
	}//ÀëÉ¢»¯ 
	std::sort(s + 1, s + n + 1, cmp);
	
	for(int i = 1; i <= n; i++) {
		int ed = i;
		while(true) {
			if(ed == n) break;
			if(s[ed + 1].x != s[i].x) break;
			ed++;
		}
		for(int j = i; j <= ed; j++) f[j] = query(s[j].y - 1) + 1;
		for(int j = i; j <= ed; j++) add(s[j].y, f[j]);
		i = ed;
	}
	for(int i = 1; i <= n; i++) {
		v[f[i]].push_back(i);
	}
	
	int ans = (p * (p + 1) / 2) * (q + 1) + (q * (q + 1) / 2) * (p + 1);
	for(int i = 1; i <= n; i++) {
		int minn = q;
		for(auto x: v[i]) {
			s[x].y = re[s[x].y];
			ans -= calc(s[x].x + 1, s[x].y + 1, p, minn);
			minn = std::min(minn, s[x].y);
		}
	}
	std::cout << ans << '\n';
	for(int i = 1; i <= n; i++) v[i].clear();
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
