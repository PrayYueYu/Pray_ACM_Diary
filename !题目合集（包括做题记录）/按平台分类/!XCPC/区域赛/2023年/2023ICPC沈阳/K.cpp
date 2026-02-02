#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 3e6 + 200, INF = 1e9;
int n, tr[N], a[N], b[N], v[N], to[N];
int val[N], cnt, m, id[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
map<int, int> mp;
void add(int p, int l, int r, int x, int ad) {
	if(r < x || x < l) return;
	if(l == r) {
		tr[p] += ad;
		if(ad > 0) val[p]++;
		else if(ad < 0) val[p]--;
		return;
	}
	int mid = (l + r) >> 1;
	add(p * 2, l, mid, x, ad);
	add(p * 2 + 1, mid + 1, r, x, ad);
	tr[p] = tr[p * 2] + tr[p * 2 + 1];
	val[p] = val[p * 2] + val[p * 2 + 1];
}
int query(int p, int l, int r, int x, int y) {
	if(x > y) return 0;
	if(y < l || r < x) return 0;
	if(x <= l && r <= y) return tr[p];
	int mid = (l + r) >> 1;
	int ans = query(p * 2, l, mid, x, y);
	ans += query(p * 2 + 1, mid + 1, r, x, y);
	return ans;
}
int query2(int p, int l, int r, int x, int y) {
	if(x > y) return 0;
	if(y < l || r < x) return 0;
	if(x <= l && r <= y) return val[p];
	int mid = (l + r) >> 1;
	int ans = query2(p * 2, l, mid, x, y);
	ans += query2(p * 2 + 1, mid + 1, r, x, y);
	return ans;
}
int solve(int sum, int all) {
	int l = 1, r = cnt;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(query(1, 1, cnt, 1, mid) - sum > 0) r = mid;
		else l = mid + 1;
	}
	if(query(1, 1, cnt, 1, l) <= sum) return 0;
	int d = sum - query(1, 1, cnt, 1, l - 1), s = 0;
	s = d / to[l] + 1;
	int num = query2(1, 1, cnt, 1, l - 1) + s;
	num = all - num + 1;
	return num;
}
signed main() {
    n = read(), m = read();
    int tot = 0, num = 0, sum = 0;
    for(int i = 1; i <= n; i++) {
    	a[i] = read();
    	if(a[i] > 0) b[++cnt] = a[i];
	}
	for(int i = 1; i <= m; i++) {
		id[i] = read(), v[i] = read();
		if(v[i] > 0) b[++cnt] = v[i];
	}
	sort(b + 1, b + cnt + 1);
	for(int i = 1; i <= cnt; i++) {
		if(!mp[b[i]]) {
			mp[b[i]] = ++tot;
			to[tot] = b[i];
		}
	}
	cnt = tot;
	//cntÊÇÖµÓò 
	for(int i = 1; i <= n; i++) {
		if(a[i] >= 0) {
			num++;
			a[i] = mp[a[i]];
			add(1, 1, cnt, a[i], to[a[i]]);
		}
		else {
			sum += a[i];
		}
	}
	for(int i = 1; i <= m; i++) {
		if(a[id[i]] > 0) {
			num--;
			add(1, 1, cnt, a[id[i]], -to[a[id[i]]]);
		}
		else sum -= a[id[i]];
		if(v[i] > 0) v[i] = mp[v[i]];
		a[id[i]] = v[i];
		if(v[i] > 0) {
			add(1, 1, cnt, v[i], to[v[i]]);
			num++;
		}
		else sum += v[i];
		int L = solve(-sum, num), R = num;
		cout << R - L + 1 << endl;
	}
    return 0;
}
/*

*/
