#include<bits/stdc++.h>
#define int long long
const int N = 1e3 + 10, M = 998244353;
int f[N][N], a[N], v[N][12], to[N], n, m, cnt;
int now[N][N], ans[2][N], nf, mf, na, ma;
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
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % M;
		x = x * x % M;
		y >>= 1;
	}
	return ans;
}
int getid() {
	int ans = 1;
	for(int i = 3; i <= n; i++) {
		if(a[i] == a[i - 2]) 
			ans += (1 << (i - 3));
	}
	return ans;
}
bool check(int x, int y) {
	for(int i = 1; i <= n; i++) {
		if(v[x][i] == v[y][i]) return false;
	}
	return true;
}
void dfs(int x) {
	if(x == n + 1) {
		cnt++;
		for(int i = 1; i <= n; i++) v[cnt][i] = a[i];
		to[cnt] = getid();
		return;
	}
	if(x == 1 || a[x - 1] != 0) {
		a[x] = 0;
		dfs(x + 1);
	}
	if(x == 1 || a[x - 1] != 1) {
		a[x] = 1;
		dfs(x + 1);
	}
	if(x == 1 || a[x - 1] != 2) {
		a[x] = 2;
		dfs(x + 1);
	}
} 
void getf() {
    for(int i = 1; i <= nf; i++)
        for(int j = 1; j <= mf; j++)
            now[i][j] = 0;//重置过渡矩阵
    for(int i = 1; i <= nf; i++)
        for(int j = 1; j <= nf; j++)
        	for(int k = 1; k <= nf; k++) {
                now[i][j] += f[i][k] * f[k][j];
                now[i][j] %= M;
            }
    for(int i = 1; i <= nf; i++) 
        for(int j = 1; j <= mf; j++) {
        	f[i][j] = now[i][j];
		}
}
void getans() {
    for(int i = 1; i <= na; i++)
        for(int j = 1; j <= ma; j++)
            now[i][j] = 0;//重置过渡矩阵
    for(int i = 1; i <= na; i++)
        for(int j = 1; j <= mf; j++) 
            for(int k = 1; k <= ma; k++) {
            	now[i][j] += ans[i][k] * f[k][j];
                now[i][j] %= M;
        	}
    for(int i = 1; i <= na; i++) 
        for(int j = 1; j <= ma; j++)
            ans[i][j] = now[i][j];//重新赋值
}
void ksm_matrix(int y) {
    while(y) {
        if(y & 1) getans();
        getf();
        y >>= 1;
    }
}
void solve() {
	std::cin >> n >> m;
	if(n == 1) {
		std::cout << 3 * ksm(2, m - 1) % M << '\n';
		return;
	}
	dfs(1);
	for(int i = 1; i <= cnt; i++) {
		if(v[i][1] || v[i][2] != 1) continue;
		for(int j = 1; j <= cnt; j++) {
			if(check(i, j)) f[to[i]][to[j]]++;
		}
	}
	cnt = (1 << (n - 2));
	for(int i = 1; i <= cnt; i++) ans[1][i] = 1;
	na = 1, nf = mf = ma = cnt;
	ksm_matrix(m - 1);
	int sum = 0;
	for(int i = 1; i <= cnt; i++) sum = (sum + ans[1][i]) % M;
	std::cout << 6 * sum % M << '\n';
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
----------------------
	Writer: 月雩薇嫭 | 
----------------------
*/
