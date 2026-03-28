#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int vis[30][30];
int read() {
	int x;
	std::cin >> x;
	return x;
}
double getd(double x1, double y1, double x2, double y2) {
	double ans = (x1 - x2) * (x1 - x2);
	ans = ans + (y1 - y2) * (y1 - y2);
	ans = sqrt(ans);
	return ans;
}
std::vector<std::pair<double, double>> v[30];
std::vector<int> W[30][3];
void solve() {
	double x1 = 7, y1 = 7;
	double x2 = 7, y2 = 8;
	for(int i = 1; i <= 20; i++) {
		for(int j = 1; j <= 20; j++) {
			int x = read(), y = read();
			v[i].push_back({x, y});
		}
	}
	double tA = 0, tB = 0;
	double MaxT = 1200000.0;
	int anscnt = 0;
	for(int i = 1; i <= 20; i++) {
		std::vector<int> ans[3];
		while(true) {
			double minnA = 10000000, minnB = 10000000;
			int idA = -1, idB = -1;
			for(int j = 0; j < 20; j++) {
				if(vis[i][j]) continue;
				int x0 = v[i][j].first, y0 = v[i][j].second;
				int d = getd(x1, y1, x0, y0);
				if(minnA > d) {
					minnA = d;
					idA = j;
				}
			}
			for(int j = 0; j < 20; j++) {
				if(vis[i][j]) continue;
				int x0 = v[i][j].first, y0 = v[i][j].second;
				int d = getd(x2, y2, x0, y0);
				if(minnB > d) {
					minnB = d;
					idB = j;
				}
			}
			if(idA == -1 && idB == -1) break;
			if(tA + minnA / 2.0 > MaxT) {
				if(tB + minnB / 2.0 > MaxT) break;
				vis[i][idB] = true;
				tB += minnB / 2.0;
				ans[1].push_back(idB);
				x2 = v[i][idB].first;
				y2 = v[i][idB].second;
			}
			else if(tB + minnB / 2.0 > MaxT) {
				vis[i][idA] = true;
				tA += minnA / 2.0;
				ans[0].push_back(idA);
				x1 = v[i][idA].first;
				y1 = v[i][idA].second;
			}
			else if(tA + minnA / 2.0 <= tB + minnB / 2.0) {
				vis[i][idA] = true;
				tA += minnA / 2.0;
				ans[0].push_back(idA);
				x1 = v[i][idA].first;
				y1 = v[i][idA].second;
			}
			else {
				vis[i][idB] = true;
				tB += minnB / 2.0;
				ans[1].push_back(idB);
				x2 = v[i][idB].first;
				y2 = v[i][idB].second;
			}
//			std::cout << tA << ' ' << tB << ' ' << idA << ' ' << idB << '\n';
		}
		if(ans[0].size() + ans[1].size() == 20) {
			anscnt++;
			W[anscnt][0] = ans[0];
			W[anscnt][1] = ans[1];
		}
		tA = tB = std::max(tA, tB);
	}
	std::cout << anscnt << '\n';
	for(int i = 1; i <= anscnt; i++) {
		std::cout << W[i][0].size() << ' ' << W[i][1].size() << '\n';
		for(auto x: W[i][0]) std::cout << x << ' ';
		std::cout << '\n';
		for(auto x: W[i][1]) std::cout << x << ' ';
		std::cout << '\n';
	}
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
