#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, INF = 1e18;
int a[N], tr[N][2], n, m, p2[100];
int lowbit(int x) {return x & (-x);}
int query(int x, int p) {
	int ans = 0;
	while(x) {
		ans += tr[x][p];
		x -= lowbit(x);
	}
	return ans;
}
void add(int x, int y, int p) {
	while(x <= n) {
		tr[x][p] += y;
		x += lowbit(x);
	}
}
void addx(int l, int r, int x) {
	if(!l || r > n) return;
	add(l, x, 0); add(r + 1, -x, 0);
	add(l, x * l, 1); add(r + 1, -x * (r + 1), 1);
}
int queryx(int l, int r) {
	int s1 = (r + 1) * query(r, 0) - query(r, 1);
	int s2 = l * query(l - 1, 0) - query(l - 1, 1);
	return s1 - s2;
}

void modify(int l, int r, int w, int op, int k) {
	int len = std::abs(r - l) + 1;
	int now = 0, mod = p2[len];
	if(w == -1) {
		for(int j = l; j >= r; j += w) {
			a[j] = queryx(j, j);
			now = now * 2ll + a[j];
		}
	}
	else {
		for(int j = l; j <= r; j += w) {
			a[j] = queryx(j, j);
			now = now * 2ll + a[j];
		}
	}
	
	if(op == 1) now = ((now - k) % mod + mod) % mod;
	else now = (now + k) % mod;
	
	int id = len - 1;
	if(w == 1) {
		for(int j = l; j <= r; j += w) {
			int t = ((now >> id) & 1);
			if(a[j] != t) addx(j, j, t - a[j]);
			id--;
		}
	}
	else {
		for(int j = l; j >= r; j += w) {
			int t = ((now >> id) & 1);
			if(a[j] != t) addx(j, j, t - a[j]);
			id--;
		}		
	}
}

void solve() {
	std::string s;
	std::cin >> n >> m;
	std::cin >> s; s = " " + s;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'H') a[i] = 0;
		else a[i] = 1;
		addx(i, i, a[i]);
	}
	for(int i = 1; i <= m; i++) {
		int op, p, k;
		std::cin >> op >> p >> k;
		if(!k) continue;
		int id = 0, len = 0;
		for(int j = 63; j >= 0; j--) {
			if(k >> j & 1) {
				id = j;
				break;
			}
		}
		len = id + 1;
		if(op == 3) {// left + 1
			if(len >= p) {
				modify(1, p, 1, 1, k);
				continue;
			}
			int w = 0, f = false;
			for(int j = p; j >= p - len + 1; j--) {
				a[j] = queryx(j, j);
				int t = (k >> w) & 1;
				if(f) {
					if(a[j]) {
						addx(j, j, -1);
						a[j] = 0;
						f = false;
					}
					else {
						addx(j, j, 1);
						a[j] = 1;
					}
				}
				if(t) {
					if(a[j]) addx(j, j, -1);
					else {
						addx(j, j, 1);
						f = true;
					}
				}
				w++;
			}
			if(f) {
				int l = 1, r = p - len;
				while(l < r) {
					int mid = (l + r + 1) >> 1;
					if(queryx(mid, p - len)) l = mid;
					else r = mid - 1;
				}
				if(!queryx(l, l)) l = 0;
				addx(l, l, -1);
				addx(l + 1, p - len, 1);
			}
		}
		if(op == 4) {// left + 0
			if(len >= p) {
				modify(1, p, 1, 0, k);
				continue;
			}
			int w = 0, f = false;
			for(int j = p; j >= p - len + 1; j--) {
				a[j] = queryx(j, j);
				int t = (k >> w) & 1;
				if(f) {
					if(!a[j]) {
						addx(j, j, 1);
						a[j] = 1;
						f = false;
					}
					else {
						addx(j, j, -1);
						a[j] = 0;
					}
				}
				if(t) {
					if(!a[j]) addx(j, j, 1);
					else {
						f = true;
						addx(j, j, -1);
					}
				}
				w++;
			}
			if(f) {
				int l = 1, r = p - len;
				while(l < r) {
					int mid = (l + r + 1) >> 1;
					if(queryx(mid, p - len) != p - len - mid + 1) l = mid;
					else r = mid - 1;
				}
				if(queryx(l, l)) l = 0;
				addx(l, l, 1);
				addx(l + 1, p - len, -1);
			}
		}
		if(op == 1) {// right + 1
			if(len >= n - p + 1) {
				modify(n, p, -1, 1, k);
				continue;
			}
			int w = 0, f = false;
			for(int j = p; j <= p + len - 1; j++) {
				a[j] = queryx(j, j);
				int t = (k >> w) & 1;
				if(f) {
					if(a[j]) {
						addx(j, j, -1);
						a[j] = 0;
						f = false;
					}
					else {
						addx(j, j, 1);
						a[j] = 1;
					}
				}
				if(t) {
					if(a[j]) addx(j, j, -1);
					else {
						addx(j, j, 1);
						f = true;
					}
				}
				w++;
			}
			if(f) {
				int l = p + len, r = n;
				while(l < r) {
					int mid = (l + r) >> 1;
					if(queryx(p + len, mid)) r = mid;
					else l = mid + 1;
				}
				if(!queryx(l, l)) l = n + 1;
				addx(l, l, -1);
				addx(p + len, l - 1, 1);
			}
		}
		if(op == 2) {// right + 0
			if(len >= n - p + 1) {
				modify(n, p, -1, 0, k);	
				continue;
			}
			int w = 0, f = false;
			for(int j = p; j <= p + len - 1; j++) {
				a[j] = queryx(j, j);
				int t = (k >> w) & 1;
				if(f) {
					if(!a[j]) {
						addx(j, j, 1);
						a[j] = 1;
						f = false;
					}
					else {
						addx(j, j, -1);
						a[j] = 0;
					}
				}
				if(t) {
					if(!a[j]) addx(j, j, 1);
					else {
						addx(j, j, -1);
						f = true;
					}
				}
				w++;
			}
			if(f) {
				int l = p + len, r = n;
				while(l < r) {
					int mid = (l + r) >> 1;
					if(queryx(p + len, mid) != mid - p - len + 1) r = mid;
					else l = mid + 1;
				}
				if(queryx(l, l)) l = n + 1;
				addx(l, l, 1);
				addx(p + len, l - 1, -1);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		int ans = queryx(i, i);
		if(ans) std::cout << 'N';
		else std::cout << 'H';
	}
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	p2[0] = 1;
	for(int i = 1; i <= 63; i++) {
		p2[i] = p2[i - 1] * 2ll;
	}
	
	solve();
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
