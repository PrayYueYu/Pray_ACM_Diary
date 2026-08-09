#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
std::string s[100], ans[100];
int n;
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
std::map<std::string, std::vector<std::pair<int, int>>> mp, nx;
std::pair<int, int> pr[100];
std::string calc(int x, int y) {
	std::string ansx = "";
	int f = 1;
	for(int i = 0; i < s[x].size(); i++) {
		if(s[x][i] == ' ') {
			f++;
			continue;
		}
		if(f <= y) ansx += s[x][i];
		else if(s[x][i] >= 'A' && s[x][i] <= 'Z') ansx += s[x][i];
	}
	return ansx;
}
void solve() {
	std::cin >> n;
	getchar();
	for(int i = 1; i <= n; i++) {
		std::getline(std::cin, s[i]);
		for(int j = 0; j < s[i].size(); j++) {
			if(s[i][j] >= 'A' && s[i][j] <= 'Z')
				ans[i] += s[i][j];
		}
		pr[i] = {i, 0};
		mp[ans[i]].push_back(pr[i]);
	}
	int pp = 0;
	while(true) {
		int f = true;
		nx.clear();
		for(int i = 1; i <= n; i++) {
//			std::cout << ans[i] << ' ' << mp[ans[i]].size() << '\n';
			if(mp[ans[i]].size() != 1) {
				f = false;
				ans[i] = calc(pr[i].first, pr[i].second + 1);
				nx[ans[i]].push_back({pr[i].first, pr[i].second + 1});
				pr[i] = {pr[i].first, pr[i].second + 1};
			}
			else {
				nx[ans[i]].push_back(pr[i]);
			}
		}
		mp.clear();
		mp = nx;
//		std::cout << '\n';
		pp++;
//		if(pp == 5) exit(0);
		if(f) break;
	}
	for(int i = 1; i <= n; i++) std::cout << ans[i] << '\n';
}
signed main() {
	solve();
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
