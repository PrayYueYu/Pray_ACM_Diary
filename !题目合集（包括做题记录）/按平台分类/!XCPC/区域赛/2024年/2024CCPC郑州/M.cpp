#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
double a[100005];
int n, k;

inline double calc(double x) {
	double sum = 0;
	for(register int i = 1; i <= n; i++) {
		if(sum>(double)k * 2){
			sum=k+1;
			break; 
		}
		sum += a[i] / (a[i] + x);
	}
	return sum;
}
signed main() {
	//freopen("M.in","r",stdin);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%Lf", &a[i]);
	}
	double l = 0, r = 1e14l, eps = 1e-10l;
	int num = 0;
	while(r - l > eps) {
		double mid = (l + r) / 2.0l;
		num++;
		if(num > 100) break;
		if(calc(mid) < (double)k) r = mid;
		else l = mid;
	}
	for(int i = 1; i <= n; i++) {
		double ans = a[i] / (a[i] + l);
		printf("%.12Lf\n", ans);
	}
	return 0;
}
