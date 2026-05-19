#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int to[10][5], n, vis[10], cnt[10], ans[10];
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
int getx(int x) {
	int val = 0;
	for(int i = 1; i <= n; i++) {
		if(i % 10 == x) val++;
	}
	return val;
}
void solve() {
	to[2][0] = 6, to[2][1] = 2, to[2][2] = 4, to[2][3] = 8;
	to[3][0] = 1, to[3][1] = 3, to[3][2] = 9, to[3][3] = 7;
	to[7][0] = 1, to[7][1] = 7, to[7][2] = 9, to[7][3] = 3;
	to[8][0] = 6, to[8][1] = 8, to[8][2] = 4, to[8][3] = 2;
	n = read();
	for(int y = 1; y <= n; y++) {
		std::vector<int> v;
		v.push_back(y % 4);
		vis[y % 4] = true;
		int id = -1;
		while(true) {
			int t = v[v.size() - 1];
			int r = t * y % 4;
			if(vis[r]) {
				for(int j = 0; j < v.size(); j++) {
					if(v[j] == r) id = j;
				}
				break;
			}
			vis[r] = true;
			v.push_back(r);
		}
		int T = v.size() - id, nx = n;
		for(int j = 0; j < id; j++) {
			cnt[v[j]]++;
			nx--;
		}
		for(int j = id; j < v.size(); j++) cnt[v[j]] += nx / T;
		for(int j = id; j < id + nx % T; j++) cnt[v[j]]++;
		for(auto t: v) vis[t] = false;
	}
	int cnteven = n / 2, cntodd = n - cnteven;
	for(int i = 0; i <= 9; i++) {
		int num = getx(i);
		if(i == 0 || i == 1 || i == 5 || i == 6)
			ans[i] += n * n * num;
		else if(i == 4) {
			ans[4] += cntodd * n * num;
			ans[6] += cnteven * n * num;
		}
		else if(i == 9) {
			ans[9] += cntodd * n * num;
			ans[1] += cnteven * n * num;
		}
		else {
			for(int j = 0; j < 4; j++) 
				ans[to[i][j]] += cnt[j] * num;
		}
	}
	for(int i = 0; i <= 9; i++) std::cout << ans[i] << ' ';
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

*/ 
