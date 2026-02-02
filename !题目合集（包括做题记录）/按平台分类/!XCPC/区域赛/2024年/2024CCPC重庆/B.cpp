#include <bits/stdc++.h>
#define ll long long
#define double long double
using namespace std;
const ll N = 1e2 + 10, M = 1e6 + 9;
int a[N], ppmax;
int ppx[N] = {0, 320, 300, 200, 100, 50, 0};
int accx[N] = {0, 300, 300, 200, 100, 50, 0};
double eps = 1e-10;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

double Print(double x) {
	int y = x;
	if(x - (double)y >= 0.5 - eps) return y + 1;
	return y;
}

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cout << fixed << setprecision(2);
    int T = read();
	while(T--) {
		ppmax = read();
		int sum = 0, as = 0, ps = 0;
		for(int i = 1; i <= 6; i++) {
			a[i] = read();
			sum += a[i];
			as += a[i] * accx[i];
			ps += a[i] * ppx[i]; 
		}
		double acc = 0L, pp = 0L;
		acc = (double)1.0L * (double)(as) / ((double)(300) * sum); 
		pp = max(0.0L, (double)ps / (double)(320.0L * sum) - 0.8L);
		pp = pp * 5.0L * (double)ppmax;
		cout << (double)(acc * 100. + 1e-7); cout << "% ";
		printf("%.0Lf\n", Print(pp));
	} 
    return 0;
}
