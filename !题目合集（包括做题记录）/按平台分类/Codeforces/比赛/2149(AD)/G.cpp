#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, q, a[N], b[N], to[N], vis[N];
vector<int> v[N];
map<int, int> mp;
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
	mp.clear();
	for(int i = 1; i <= n; i++) v[i].clear();
}
int RandLL(int L, int R) {
    static std::mt19937_64 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(L, R);
    return dist(rng);
}
bool check(int x, int l, int r) {
	int d = (r - l + 1) / 3 + 1;
	auto it1 = upper_bound(v[x].begin(), v[x].end(), r);
	auto it2 = lower_bound(v[x].begin(), v[x].end(), l);
	int sum = (it1 - it2);
	return sum >= d? true: false;
}
void solve() {
	n = read(), q = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(!mp[b[i]]) {
			mp[b[i]] = ++cnt;
			to[cnt] = b[i];
		}
	}
	for(int i = 1; i <= n; i++) {
		a[i] = mp[a[i]];
		v[a[i]].push_back(i);
	}
	for(int i = 1; i <= q; i++) {
		int l = read(), r = read();
		vector<int> ans;
		for(int j = 1; j <= 70; j++) {
			int x = RandLL(l, r);
			if(check(a[x], l, r) && !vis[a[x]]) {
				vis[a[x]] = true;
				ans.push_back(a[x]);
			}
		}
		if(ans.size() == 0) cout << -1;
		else {
			sort(ans.begin(), ans.end());
			for(int x: ans) {
				cout << to[x] << ' '; 
				vis[x] = false;
			}
		}
		cout << '\n';
	}
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
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
