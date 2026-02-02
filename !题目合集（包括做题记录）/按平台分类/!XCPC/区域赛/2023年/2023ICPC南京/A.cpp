#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e5 + 100, M = 1e9 + 7, INF = 1e9; 
int dx[10] = {0, 1, -1, 0, 0};
int dy[10] = {0, 0, 0, 1, -1};
int n, m;
queue<pair<int, int>> q;
vector<vector<int>> a, vis;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void init() {
	while(!q.empty()) q.pop();
	a.clear();
	vis.clear();
}
bool check(int x, int y) {
	if(x < 1 || y < 1) return false;
	if(x > n || y > m) return false;
	if(vis[x][y]) return false;
	if(!a[x][y]) return false;
	return true;
}
bool checkx(vector<pair<int, int>> & v, int cnt) {
	for(int i = 1; i <= n; i++) { 
		for(int j = 1; j <= m; j++) {
			if(!a[i][j] || vis[i][j] == cnt) continue;
			int f = false;
			for(int k = 0; k < v.size(); k++) {
				int sx = i + v[k].first;
				int sy = j + v[k].second;
				if(sx < 1 || sy < 1 || sx > n || sy > m || !a[sx][sy]) {
					f = true;
					break;
				}
			}
			if(!f) return false;
		}
	}
	return true;
}
void solve() {
	n = read(), m = read();
	a.resize(n + 5, vector<int>(m + 5, 0));
	vis.resize(n + 5, vector<int>(m + 5, 0));
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		s = " " + s;
		for(int j = 1; j <= m; j++) {
			if(s[j] == '.') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	int cnt = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(vis[i][j] || !a[i][j]) continue;
			vector<pair<int, int>> v;
			q.push({i, j});
			cnt++;
			vis[i][j] = cnt;
			v.push_back({0, 0});
			int sum = 1;
			while(!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for(int k = 1; k <= 4; k++) {
					int sx = x + dx[k];
					int sy = y + dy[k];
					if(!check(sx, sy)) continue;
					vis[sx][sy] = cnt;
					sum++;
				
					v.push_back({sx - i, sy - j});
					q.push({sx, sy});
				}
			}

			if(checkx(v, cnt)) ans += sum;
		}
	}
	cout << ans << endl;
}
signed main(){
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
