#include<bits/stdc++.h>
#define int long long
const int N = 1e5 + 10;
int n, p[N], v[100], r[N][20], k;
void init() {
	for(int i = 0; i <= n; i++) p[i] = -1;
}
int query(int x, int y) {
	std::cout << "? " << x << ' ' << y << '\n';
	std::cout.flush();
	int ans;
	std::cin >> ans;
	return ans;
}
void print() {
	std::cout << "! ";
	for(int i = 0; i <= n; i++) {
		if(p[i] == -1) std::cout << n;
		else std::cout << p[i];
		if(i != n) std::cout << ' ';
	}
	std::cout << '\n';
	std::cout.flush();
}
void solve() {
	std::cin >> n; n--;
	init();
	if(n == 0) {
		p[0] = 0;
		print();
		return;
	}
	for(int i = 9; i >= 0; i--) {
		if(n >> i & 1) {
			k = i;
			break;
		}
	}
	for(int i = 0; i <= k; i++) {
		v[i] = query((1 << i), -1);
	}
	for(int i = 0; i < n; i++) {
		int f = true;
		for(int j = 0; j <= k; j++) {
			r[i][j] = query((1 << j), i);
			if(r[i][j] == v[j]) f = false;
		}
		if(f) {
			if(p[0] == -1) p[0] = i;
			else p[n] = i;
			for(int j = 0; j <= k; j++) {
				if(r[i][j] == (v[j] + 1) % 3) r[i][j] = 1;
				else r[i][j] = -1;
			}
		}
		else {
			for(int j = 0; j <= k; j++) {
				if(r[i][j] == v[j]) r[i][j] = 0;
				else if(r[i][j] == (v[j] + 2) % 3) r[i][j] = 2;
				else r[i][j] = -2;
			}
		}
	}
	if(p[n] == -1) p[n] = n;
	int now = p[0], id = 0;
	while(true) {
		if(id == n || now == n) break;
		p[id] = now; id++;
		int ne = 0;
		for(int i = 0; i <= k; i++) {
			if(r[now][i] == -1) {
				if(now >> i & 1) ne += 0;
				else ne += (1 << i);
			}
			else {
				if(now >> i & 1) ne += (1 << i);
				else ne += 0;
			}
		}
		for(int i = 0; i <= k; i++) {
			r[ne][i] -= r[now][i];
		}
		now = ne;
	}
	now = p[n], id = n;
	while(true) {
		if(id == 0 || now == n) break;
		p[id] = now; id--;
		int ne = 0;
		for(int i = 0; i <= k; i++) {
			if(r[now][i] == -1) {
				if(now >> i & 1) ne += 0;
				else ne += (1 << i);
			}
			else {
				if(now >> i & 1) ne += (1 << i);
				else ne += 0;
			}
		}
		for(int i = 0; i <= k; i++) {
			r[ne][i] -= r[now][i];
		}
		now = ne;
	}
	print();
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) solve();
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Ş±‹¬ | 
----------------------
*/
