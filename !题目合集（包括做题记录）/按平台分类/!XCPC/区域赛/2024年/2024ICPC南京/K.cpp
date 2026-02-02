#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 2e5 + 100, M = 1e9 + 7, INF = 1e18;
int n, a[N], b[N], m, k, w;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
priority_queue<pair<int, int>> q;
void solve() {
	n = read(), m = read(), k = read(), w = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();//红格子 
		q.push({-a[i], 1});
	} 
	for(int i = 1; i <= m; i++) {
		b[i] = read();//黑格子
		q.push({-b[i], 2}); 
	}
	q.push({-(w + 1), 2});//最后一个标记为黑的 
	int lasb = 0, f = true;
	vector<int> v, ans;
	while(!q.empty()) {
		int co = q.top().second;
		int x = -q.top().first;
		q.pop();
		if(!v.size()) {
			if(co == 2) {
				lasb = x;
				continue;
			}
			v.push_back(x);
			continue;
		}
		int r = v[v.size() - 1] + k - 1;
		if(co == 2) {
			if(r < x) {
				lasb = x;
				for(auto u: v) ans.push_back(u);
				v.clear();
				continue;
			}
			int d = r - x + 1;
			for(int i = v.size() - 1; i >= 0; i--) {
				v[i] -= d;
				if(!i) {
					if(v[i] <= lasb) {
						f = false;
						break;
					}
				}
				else {
					int rx = v[i - 1] + k - 1;
					d = max(0ll, rx - v[i] + 1ll);
					if(!d) break;
				}
			}
			for(auto u: v) ans.push_back(u);
			v.clear();
			lasb = x;
		}
		else {
			if(r >= x) continue;
			v.push_back(x);
		}
	}
	if(!f) {
		cout << -1 << endl;
		return;
	}
	cout << ans.size() << endl;
	for(auto u: ans) cout << u << " ";
	cout << endl;
}
signed main() {
	int T = read();
	while(T--) {
		solve();
	}
    return 0;
}
/*

*/
