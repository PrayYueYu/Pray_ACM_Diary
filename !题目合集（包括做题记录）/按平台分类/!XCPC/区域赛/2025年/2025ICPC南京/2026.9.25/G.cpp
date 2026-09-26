#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int ans[N], n, v[N], l[N], q, vis[N];
struct T {
	int t, id;
} s[N];
bool cmp(T x, T y) {
	return x.t < y.t;
}

std::priority_queue<std::pair<int, int>> q1, q2;
std::priority_queue<std::pair<double, int>> q3;
int calc(int vx, int lx, int t) {
	if(vx - lx * t <= 0) return 0;
	return vx - lx * t;
}
int calcx(int t1, int t2, int i) {
	int vm = std::max(v[t1], v[t2]);
	int lm = std::min(l[t1], l[t2]);
	return calc(vm, lm, s[i].t) - calc(v[t1], l[t1], s[i].t) - calc(v[t2], l[t2], s[i].t);
}
void solve() {
	std::cin >> n;
	int cntv = 0, cntl = 0, now = n;
	for(int i = 1; i <= n; i++) {
		std::cin >> v[i];
		cntv += v[i];
	}
	for(int i = 1; i <= n; i++) {
		std::cin >> l[i];
		cntl += l[i];
		q1.push({-v[i], i});
		q2.push({l[i], i});
		if(l[i]) q3.push({-(double)v[i] / l[i], i});
		else q3.push({-(double)INF, i});
	}
	std::cin >> q;
	for(int i = 1; i <= q; i++) {
		std::cin >> s[i].t;
		s[i].id = i;
	}
	std::sort(s + 1, s + q + 1, cmp);
	for(int i = 1; i <= q; i++) {
		while(true) {
			while(!q1.empty()) {
				if(vis[q1.top().second]) {
					q1.pop();
				}
				else break;
			}
			while(!q2.empty()) {
				if(vis[q2.top().second]) {
					q2.pop();
				}
				else break;
			}
			
			if(q1.empty() || q2.empty()) break;
			int id1 = q1.top().second;
			int id2 = q2.top().second;
			int vm = std::max(v[id1], v[id2]);
			int lm = std::min(l[id1], l[id2]);
			if(l[id2] * s[i].t > v[id1]) {
				if(id1 == id2) {
					q1.pop(), q2.pop();
					vis[id1] = vis[id2] = true;
					cntv -= v[id1];
					cntl -= l[id1];
				}
				else {
					q1.pop(); q2.pop();
					vis[id1] = vis[id2] = true;
					q1.push({-vm, ++now});
					q2.push({lm, now});
					v[now] = vm, l[now] = lm;
					cntl = cntl - (l[id1] + l[id2]) + lm;
					cntv = cntv - (v[id1] + v[id2]) + vm;
					if(lm) q3.push({-(double)vm / lm, now});
					else q3.push({-(double)INF, now});
				}
			}
			else break;
			
		}
		while(!q3.empty()) {
			int id = q3.top().second;
			if(v[id] - l[id] * s[i].t > 0) break;
			q3.pop();
			if(vis[id]) continue;
			vis[id] = true;
			cntv -= v[id];
			cntl -= l[id];
		}
//		std::cout << cntv << ' ' << cntl << '\n';
		ans[s[i].id] = cntv - cntl * s[i].t;
	}
	for(int i = 1; i <= now; i++) vis[i] = false;
	for(int i = 1; i <= q; i++) std::cout << ans[i] << ' ';
	std::cout << '\n';
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
2
4
5 4 7 6
2 1 3 2
3
3 1 2
4
19 47 21 13
5 14 2 3
5
5 2 6 1 4
*/
