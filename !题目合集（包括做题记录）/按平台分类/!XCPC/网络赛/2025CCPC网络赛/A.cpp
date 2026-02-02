#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7;
int n, m, f;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int solve(int i, int j) {
	int sum = 0;
	for(int y = j + 1; y <= min(i + j - 1, m); y++) {
		int r = min(m + i - y, n), l = i + 1;
		if(r >= l) sum += r - l + 1;
	}
	for(int y = j + 1; y <= m; y++) {
		int l = max(1ll, max(i - j + 1, y - j + 1));
		int r = i - 1;
		if(r >= l) sum += r - l + 1;
	}
	for(int y = max(1ll, i + j - n); y <= j - 1; y++) {
		int r = i - 1, l = max(1 + i - y, 1ll);
		if(r >= l) sum += r - l + 1;
	}
	for(int y = 1; y <= j - 1; y++) {
		int r = min(min(m + i - j, n), n + y - j);
		int l = i + 1;
		if(r >= l) sum += r - l + 1;
	}
	sum += min(n - i, m - j);
	sum += min(n - i, j - 1);
	sum += min(i - 1, m - j);
	sum += min(i - 1, j - 1);
	return sum;
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	n = read(), m = read();
	n++, m++;
	if(m > n) swap(n, m), f = true;
	vector<vector<int>> ans;
	ans.resize(n + 5, vector<int>(m + 5, 0));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			ans[i][j] = solve(i, j);
		}
	}
	if(f) {
		for(int j = 1; j <= m; j++) {
			for(int i = n; i >= 1; i--) {
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	else {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cout << ans[i][j] << " ";
			}
			cout << '\n';
		}
	}
    return 0;
}
