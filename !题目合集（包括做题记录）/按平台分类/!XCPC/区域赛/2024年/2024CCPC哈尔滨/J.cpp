#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int w[N], x[N], t[N];
int n, m, now[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
priority_queue<pair<int, pair<int, int>>> q;
vector<int> v[N];
void init() {
	for(int i = 1; i <= n; i++) {
		now[i] = 0;
	}
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		w[i] = read();
		//s[i].id = i;
		v[i].clear();
	}
	
	for(int i = 1; i <= m; i++) {
		x[i] = read();
		t[i] = read();
		v[t[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++) {
		v[i].push_back(m + 1);
	}
	for(int i = 1; i <= n; i++) {
		q.push({-v[i][now[i]], {w[i], i}});
	}
	int ans = 0;
	int net = 1, st = 0;
	while(!q.empty()) {
		if(net > m) break;
		int u = q.top().second.second;
		int re = q.top().second.first;
		q.pop();
		if(!re) continue;//空油箱continue 
		if(x[net] - st <= re) {
			//当前油量能走到下一个加油站 
			re -= (x[net] - st);
			ans += x[net] - st; 
			st = x[net];
			now[t[net]]++;
			if(re && u != t[net]) 
				q.push({-v[u][now[u]], {re, u}});
			q.push({-v[t[net]][now[t[net]]], {w[t[net]], t[net]}});
			//t[net]充满油 
			net++;
			continue;
		}
		else {
			ans += re;
			st += re;
			re = 0;
		}
	}
	while(!q.empty()) {
		//走完所有还有剩余 
		ans += q.top().second.first;
		q.pop();
	}
	cout << ans << '\n';
}
signed main() {
	
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
