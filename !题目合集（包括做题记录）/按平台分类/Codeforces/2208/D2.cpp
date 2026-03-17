#include<bits/stdc++.h>
#define int long long
const int N = 1e4 + 10, mod = 998244353, INF = 1e18;
int n, fa[N];
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

int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void merge(int x, int y) {
	int fax = getfa(x), fay = getfa(y);
	if(fax == fay) return;
	fa[fax] = fay;
}
bool check(std::vector<std::pair<int, int>> d) {
	
}
void solve() {
	n = read();
	int flag = true;
	std::queue<int> q;
	for(int i = 1; i <=n; i++) {
		fa[i] = i;
		std::cin >> s[i];
		s[i] = " " + s[i];
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(s[i][j] == '0') {
				if(j == i) {
					flag = false;
				}
			}
			else cnt++;
		}
		if(cnt == 1) {
			q.push(i);
		}
	}
	if(!flag) {
		std::cout << "No\n";
		return;
	}
	std::vector<std::pair<int, int>> ans;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int i = 1; i <= n; i++) {
			if(s[i][x] == '1') {
				s[i][x] = '0';
				int f = true;
				for(int j = 0; j < p[i].size(); j++) {
					int y = p[i][j];
					if(s[x][y] == '1') {
						p[i][j] = x;
						f = false;
						break;
					}
				}
				if(f) p[i].push_back(x);
			}
		}
	}
	flag = true;
	if(ans.size() != n - 1) flag = false;
	int fa1 = getfa(1);
	for(int i = 1; i <= n; i++) {
		int fai = getfa(i);
		if(fai != fa1) {
			flag = false;
			break;
		}
	}
	if(!check(ans)) flag = false;
	if(!flag) {
		std::cout << "No\n";
		return;
	}
	std::cout << "Yes\n";
	for(auto x: ans) {
		std::cout << x.first << ' ' << x.second << '\n';
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
1
4
1000
0110
1010
1111
*/
