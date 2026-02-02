#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10, mod = 1e9 + 7;
int n, v[N], l[N], ans[N], vis[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct Query {
	int t, id;
} qu[N];
bool cmpq(Query x, Query y) {
	return x.t < y.t;
}
void solve() {
	n = read();
	priority_queue<pair<int, int>> q1, q2;
	priority_queue<pair<double, int>> q3;
	int sumv = 0, suml = 0, tot = n;
	double INF = 5e13;
	for(int i = 1; i <= n; i++) v[i] = read();
	for(int i = 1; i <= n; i++) l[i] = read();
	for(int i = 1; i <= n; i++) {
		q1.push({l[i], i});
		q2.push({-v[i], i});
		if(!l[i]) q3.push({-INF, i});
		else q3.push({-(double)(v[i] / l[i]), i});
		sumv += v[i];
		suml += l[i];
	}
	for(int i = 1; i <= 5 * n; i++) {
		vis[i] = false;
	}
	int qs = read();
	for(int i = 1; i <= qs; i++) {
		qu[i].id = i;
		qu[i].t = read();
	}
	sort(qu + 1, qu + qs + 1, cmpq);
	
	for(int i = 1; i <= qs; i++) {
		while(true) {
			int t1 = 0, t2 = 0;
			while(!q1.empty()) {
				t1 = q1.top().second;
				if(vis[t1]) {
					t1 = 0;
					q1.pop();
					continue;
				}
				break;
			}
			while(!q2.empty()) {
				t2 = q2.top().second;
				if(vis[t2]) {
					t2 = 0;
					q2.pop();
					continue;
				}
				break;
			}
			if(!t1 || !t2) break;
			if(l[t1] * qu[i].t > v[t2]) {
				if(t1 == t2) {
					vis[t1] = true;
					q1.pop(); q2.pop();
					suml -= l[t1];
					sumv -= v[t1];
				}
				else {
					q1.pop(), q2.pop();
					vis[t1] = vis[t2] = true;
					sumv = sumv - (v[t1] + v[t2]);
					suml = suml - (l[t1] + l[t2]);
					int vx = max(v[t1], v[t2]);
					int lx = min(l[t1], l[t2]);
					sumv += vx;
					suml += lx;
					v[++tot] = vx;
					l[tot] = lx;
					q1.push({l[tot], tot});
					q2.push({-v[tot], tot});
					if(!lx) q3.push({-INF, tot});
					else q3.push({-(double)(vx / lx), tot});
				}
			}
			else break;
		}
		while(!q3.empty()) {
			int x = q3.top().second;
			if(vis[x]) {
				q3.pop();
				continue;
			}
			if(v[x] <= qu[i].t * l[x]) {
				vis[x] = true;
				q3.pop();
				sumv -= v[x];
				suml -= l[x];
				continue;
			}
			break;
		}
		ans[qu[i].id] = sumv - qu[i].t * suml;
	}
	for(int i = 1; i <= qs; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = read();
	while(T--) solve();
    return 0;
}
/*

*/
