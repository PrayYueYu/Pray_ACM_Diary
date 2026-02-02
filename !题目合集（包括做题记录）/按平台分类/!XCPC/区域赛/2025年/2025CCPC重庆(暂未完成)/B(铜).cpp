#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int M = 1e9 + 7;
int f[200][200], ans[200][200], n, k, t[2000];
int ma, na, mf, nf, now[200][200], vis[2000];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
void getf() {
    for(int i = 1; i <= nf; i++)
        for(int j = 1; j <= mf; j++)
            now[i][j] = 0;//重置过渡矩阵
    for(int i = 1; i <= nf; i++)
        for(int j = 1; j <= mf; j++) 
            for(int k = 1; k <= nf; k++) {
                now[i][j] += f[i][k] * f[k][j];
                now[i][j] %= M;
                now[i][j] = (now[i][j] + M) % M;
            }
    for(int i = 1; i <= nf; i++) 
        for(int j = 1; j <= mf; j++)
            f[i][j] = now[i][j];//重新赋值
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
            	now[i][j] = (now[i][j] + M) % M;
        	}
    for(int i = 1; i <= na; i++) 
        for(int j = 1; j <= ma; j++)
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
	n = read(), k = read();
	for(int i = 1; i < k; i++) {
		t[i] = read();
		vis[t[i]]++;
	}
	for(int i = 1; i <= 102; i++) {
		for(int j = 1; j <= 102; j++) {
			if(j == 1) {
				if(i == 1) f[i][j] = 1;
				continue;
			}
			if(j < 102) {
				if(i == j + 1) f[i][j] = 1;
			}
			else {
				if(i == 1 || i == 102) f[i][j] += k;
				if(vis[102 - i]) {
					f[i][j] = (f[i][j] - vis[102 - i] + M) % M;
				}
			}
		}
	}
	for(int i = 1; i <= min(102ll, n); i++) {
		ans[1][i] = 1 + ans[1][i - 1];
		ans[1][i] %= M;
		for(int j = 1; j < k; j++) {
			if(i - 1 - t[j] >= 0) {
				ans[1][i] += 1 + ans[1][i - 1] - ans[1][i - 1 - t[j]];
				ans[1][i] %= M;
				ans[1][i] = (ans[1][i] + M) % M;
			}
		}
	}
	if(n <= 102) {
		cout << ans[1][n] << '\n';
		return;
	}
	ans[1][1] = 1;
	n -= 102;
	na = 1;
	ma = nf = mf = 102;
	ksm_matrix(n);
	cout << ans[1][102];
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}

/*
f[i+1] = k * (1 + f[i]) - \sum f[i - t[j]]
f[i+1]=1+f[i]+\sum f[i]-f[i-t[j]]+1

114514 5
28 26 70 27
*/
