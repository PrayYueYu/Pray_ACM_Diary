#include<bits/stdc++.h>
#define int long long
#define front top
//#define getchar getchar_unlocked
const int N = 1e3 + 10, mod = 998244353, INF = 1e18;
int n, m, k, cnt;
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
std::vector<int> ans[N], line;
void solve() {
	n = read(), m = read(), k = read();
	std::stack<int> hand, box;
	line.push_back(-1);
	for(int i = 1; i <= n; i++) {
		int x = read();
		line.push_back(x);
	}
	int now = 1;
	while(true) {
		int x = INF, y = INF, z = INF;
		if(now <= n) x = line[now];
		if(!box.empty()) y = box.front();
		if(!hand.empty()) z = hand.front();
		if(box.empty() && now > n) break;
//		std::cout << "1 " << x << ' ' << y << ' ' << z << '\n';
		if(hand.size() == k || (box.size() == m && x > z) || (now > n && y > z)) {
			cnt++;
			while(!hand.empty()) {
				ans[cnt].push_back(hand.front());
				hand.pop();
			}
			continue;
		}
//		std::cout << "2 " << x << ' ' << y << ' ' << z << '\n';
		if(hand.size() == 0) {
			if(!box.empty()) {
				hand.push(box.front());
				box.pop();
			}
			else {
				hand.push(line[now]);
				now++;
			}
			continue;
		}
//		std::cout << "3 " << x << ' ' << y << ' ' << z << '\n';
		if(y <= z) {
			hand.push(y);
			box.pop();
			continue;
		}
		if(x <= z) {
			hand.push(x);
			now++;
			continue;
		}
		if(now <= n) {
			box.push(x);
			now++;
		}
	}
	if(!hand.empty()) {
		cnt++;
		while(!hand.empty()) {
			ans[cnt].push_back(hand.front());
			hand.pop();
		}
	}
	for(int i = 1; i <= cnt; i++) {
		for(int j = ans[i].size() - 1; j >= 0; j--) {
			std::cout << ans[i][j];
			if(j) std::cout << ' ';
		}
		if(i != cnt) std::cout << '\n';
	}
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
