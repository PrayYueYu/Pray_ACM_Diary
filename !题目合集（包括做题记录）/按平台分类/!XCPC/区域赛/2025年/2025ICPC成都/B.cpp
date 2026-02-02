#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int na, ma, nf, mf, valc[100], vala[100];
int n, k, R, m, a[100], c[100];
int now[100][100], f[100][100], ans[100][100];
int read() {
	int x;
	cin >> x;
	return x;
}
void init() {
	int S = 1 << n;
	for(int i = 0; i < S; i++) {
		for(int j = 0; j < S; j++) {
			f[i][j] = ans[i][j] = 0;
			valc[i] = vala[i] = 0;
		}
	}
}
void getf() {
    for(int i = 0; i <= nf; i++)
        for(int j = 0; j <= mf; j++)
            now[i][j] = -INF;//重置过渡矩阵
    for(int i = 0; i <= nf; i++)
        for(int j = 0; j <= mf; j++) {
            for(int k = 0; k <= nf; k++)
            now[i][j] = max(now[i][j], f[i][k] + f[k][j]);
        }
    for(int i = 0; i <= nf; i++) 
        for(int j = 0; j <= mf; j++)
            f[i][j] = now[i][j];//重新赋值
}
void getans() {
    for(int i = 0; i <= na; i++)
        for(int j = 0; j <= ma; j++)
            now[i][j] = -INF;//重置过渡矩阵
    for(int i = 0; i <= na; i++)
        for(int j = 0; j <= mf; j++) {
            for(int k = 0; k <= ma; k++)
            	now[i][j] = max(now[i][j], ans[i][k] + f[k][j]);
        }
    for(int i = 0; i <= na; i++) 
        for(int j = 0; j <= ma; j++)
            ans[i][j] = now[i][j];//重新赋值
}
void ksm_matrix(int y) {//y次幂
    while(y) {
        if(y & 1) getans();//更新ans矩阵
        getf();//更新f矩阵
        y >>= 1;
    }
}

void solve() {
	n = read(), m = read(), k = read(), R = read();
	for(int i = 1; i <= n; i++) {
		a[i - 1] = read();
		c[i - 1] = read();
	}
	for(int i = 0; i < (1 << n); i++) {
		for(int j = 0; j < n; j++) {
			if((i >> j & 1)) {
				valc[i] += c[j];
				vala[i] += a[j];
			}
		}
	}
	for(int i = 0; i < (1 << n); i++) {
		for(int j = 0; j < (1 << n); j++) {
			int x = (i & j), nowx = 0;
			for(int p = 0; p < n; p++) {
				if(x >> p & 1) nowx++;
			} 
			nowx = nowx * k;
			nowx = nowx + valc[j];
			if(nowx > m) {
				f[i][j] = -INF;
				continue;
			}
			f[i][j] = vala[j];
			
		}
	}
	na = nf = mf = ma = (1 << n) - 1;
	for(int i = 0; i < (1 << n); i++) {
		for(int j = 0; j < (1 << n); j++) {
			if(i != j) ans[i][j] = -INF;
		}
	}
	R--;
	if(R >= 0) ksm_matrix(R);
	int Max = -1;
	for(int i = 0; i < (1 << n); i++) {
		for(int j = 0; j < (1 << n); j++) {
			if(valc[i] <= m && ans[i][j] >= 0) {
				Max = max(Max, ans[i][j] + vala[i]);
			}
		}
	}
	cout << Max << '\n';
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

*/
