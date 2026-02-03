#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int M1 = 1e9 + 7, M2 = 1e9 + 6;
int ans[4][4], f[4][4], now[4][4];
int read() {
	long long x;
	scanf("%lld", &x);
	return x;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        print(-x);
        return;
    }
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
int ksm(int x, int y, int mod) {
	x %= mod;
	if(!x) return 0;
	int ansx = 1;
	while(y) {
		if(y & 1) ansx = (ansx * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ansx;
}
int ksc(int x, int y, int mod) {
	x %= mod;
	int ansx = 0;
	while(y) {
		if(y & 1) ansx = (ansx + x) % mod;
		x = (x + x) % mod;
		y >>= 1;
	}
	return ansx;
}
void getf(int mod) {
    for(int i = 1; i <= 2; i++)
        for(int j = 1; j <= 2; j++)
            now[i][j] = 0;//重置过渡矩阵
    for(int i = 1; i <= 2; i++)
        for(int j = 1; j <= 2; j++) {
            for(int k = 1; k <= 2; k++)
            	now[i][j] += ksc(f[i][k], f[k][j], mod);
            now[i][j] %= mod;
        }
    for(int i = 1; i <= 2; i++) 
        for(int j = 1; j <= 2; j++)
            f[i][j] = now[i][j];//重新赋值
}
void getans(int mod) {
    for(int i = 1; i <= 1; i++)
        for(int j = 1; j <= 2; j++)
            now[i][j] = 0;//重置过渡矩阵
    for(int i = 1; i <= 1; i++)
        for(int j = 1; j <= 2; j++) {
            for(int k = 1; k <= 2; k++)
            	now[i][j] += ksc(ans[i][k], f[k][j], mod);
            now[i][j] %= mod;
        }
    for(int i = 1; i <= 1; i++) 
        for(int j = 1; j <= 2; j++)
            ans[i][j] = now[i][j];//重新赋值
}
void ksm_matrix(int y, int mod) {//y次幂
    while(y) {
        if(y & 1) getans(mod);//更新ans矩阵
        getf(mod);//更新f矩阵
        y >>= 1;
    }
}
signed main() {
	int n = read(), x = read(), y = read();
	int a = read(), b = read();
	if(n == 1) {
		x %= M1;
		print(x);
		return 0;
	}
	if(n == 2) {
		y %= M1;
		print(y);
		return 0;
	}
	ans[1][1] = 1;
	ans[1][2] = 0;
	f[1][1] = 1;
	f[1][2] = 1;
	f[2][1] = 1;
	f[2][2] = 0;
	ksm_matrix(n - 2, M2);
	int s = ans[1][1] + ans[1][2] - 1;
	s = (s + M2) % M2;
	int s3 = ksm(a, ksc(b, s, M2), M1);
	int s1 = ksm(x, ans[1][2], M1);
	int s2 = ksm(y, ans[1][1], M1);
	int ans = ksc(s1, s2, M1);
	ans = ksc(ans, s3, M1);
	ans %= M1;
	print(ans);
	return 0;
}
