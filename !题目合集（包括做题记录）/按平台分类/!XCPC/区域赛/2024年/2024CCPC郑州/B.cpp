#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int a[205][205];
int b[205][205];
int dist[205][205];
bool vis[205][205];
int n;
const int inf = 1e9;
void bfs1() {
	int t = 4;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 2 * i - 1; j >= 1; j--) {
				b[i][j] = t++;
				if (t == 5)t = 1;
			}
		} else {
			for (int j = 1; j <= 2 * i - 1; j++) {
				b[i][j] = t++;
				if (t == 5)t = 1;
			}
		}
	}
}


void bfs2(int x, int y) {
	queue<pair<pii, int>> qu;
	qu.push({{1, 1}, 0});
	while (!qu.empty()) {
		auto[x, y] = qu.front().first;
		int bs = qu.front().second;
		qu.pop();
		if (vis[x][y])continue;
		vis[x][y] = 1;
		if(a[x][y] != b[x][y])continue;
		dist[x][y] = bs;
		if (y % 2 == 1) {
			if (!vis[x][y - 1])qu.push({{x, y - 1}, bs + 1});
			if (!vis[x][y + 1])qu.push({{x, y + 1}, bs + 1});
			if (!vis[x + 1][y + 1])qu.push({{x + 1, y + 1}, bs + 1});
		}
		else {
			if (!vis[x][y - 1])qu.push({{x, y - 1}, bs + 1});
			if (!vis[x][y + 1])qu.push({{x, y + 1}, bs + 1});
			if (!vis[x - 1][y - 1])qu.push({{x - 1, y - 1}, bs + 1});
		}
	}

}

signed main() {
	for (int i = 0; i < 203; i++) {
		for (int j = 0; j < 203; j++) {
			vis[i][j] = 1;
			dist[i][j] = inf;
		}
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * i - 1; j++) {
			cin >> a[i][j];
			vis[i][j] = 0;
		}
	}
//	cout << "ok\n";
	int dx, dy;
	cin >> dx >> dy;
	bfs1();
	bfs2(1, 1);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= 2 * i - 1; j++) {
//			cout << dist[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
	if (dist[dx][dy] == inf) {
		cout << "-1";
	} else
		cout << dist[dx][dy];
	return 0;
}
