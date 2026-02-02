#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e6 + 9;
int n;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int a = 0, b = 0, c = 0, d = 0;
//	double e = 0;
	cin >> a;
	b = a / 12 * 4 + 2;
	cout << b;
//	printf("%.10lf", (double)a * b / (a + b));
    return 0;
}
