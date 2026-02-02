#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e6 + 100;
int p = 1331, mod = 998244353;
int n, q, pre[N][3], las[N][3], P[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
map<pair<int, int>, int> mp;
int get_hash(string s, int l, int r) {
	int len = s.size(), ans = 0;
	if(l == -1) l = 0, r = len;
	for(int i = l; i < r; i++) {
		ans = (ans * p + s[i]);
		ans %= mod;
	}
	return ans;
}
int get_pre(int t, int l, int r) {
	int s1 = pre[r][t];
	int s2 = 0, len = r - l + 1;
	if(l >= 1) s2 = pre[l - 1][t] * P[len];
	else s2 = 0;
	return (s1 % mod - s2 % mod + mod) % mod;
}
int query(string s1, string s2) {
	int ans = 0;
	int len = s1.size();
	las[len][1] = las[len][2] = 0;
	for(int i = len - 1; i >= 0; i--) {
		las[i][1] = (las[i + 1][1] * p + s1[i]) % mod;
		las[i][2] = (las[i + 1][2] * p + s2[i]) % mod;
	}
	for(int i = 0; i < len; i++) {
		if(!i) {
			pre[i][1] = s1[i];
			pre[i][2] = s2[i];
		}
		else {
			pre[i][1] = (pre[i - 1][1] * p + s1[i]) % mod;
			pre[i][2] = (pre[i - 1][2] * p + s2[i]) % mod;
		}
	}
	for(int i = -1; i < len; i++) {
		if(i >= 0 && pre[i][1] != pre[i][2]) break;
		for(int j = len - 1; j > i; j--) {
			if(las[j + 1][1] != las[j + 1][2]) break;
			int u = get_pre(1, i + 1, j);
			int v = get_pre(2, i + 1, j);
//cout << i + 1 << " " << j << " ";
//cout << u << ' ' << v << ' ' << mp[{u, v}] << endl;
			ans += mp[{u, v}];
		}
	}
//cout << get_pre(1, 1, 3) << " " << get_pre(1, 2, 3) << endl;
	return ans;
}
signed main() {
//	freopen("1.in", "r", stdin);
	P[0] = 1;
	for(int i = 1; i <= N - 1; i++) P[i] = (P[i - 1] * p) % mod;
	n = read(), q = read();
	for(int i = 1; i <= n; i++) {
		string s1 = "", s2 = "";
		cin >> s1 >> s2;
		int t1 = get_hash(s1, -1, 0);
		int t2 = get_hash(s2, -1, 0);
//cout << t1 << " " << t2 << " | " << s1 << " " << s2 << endl;
		mp[{t1, t2}]++;
	}
	for(int i = 1; i <= q; i++) {
		string s1 = "", s2 = "";
		cin >> s1 >> s2;
		int len = s1.size();
		if(s2.size() != len) {
			cout << 0 << '\n';
			continue;
		}
		cout << query(s1, s2) << '\n';
	}
	return 0;
}
/*
16 14
b a
qqhb qqha
hbj haj
qxbj qxaj
b a
uxbqd uxaqd
by ay
b a
by ay
vlb vla
lb la
nhvlb nhvla
a b
a b
b a
bb ab
*/
