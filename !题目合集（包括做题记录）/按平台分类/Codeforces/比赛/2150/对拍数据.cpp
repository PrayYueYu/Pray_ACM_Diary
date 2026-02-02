#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 5e3, M = 998244353, INF = 1e14;
char ans[100][100];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
signed main() {
	freopen("1.in", "w", stdout);
	srand(time(0));
	int n = 100000;
	int x = rand() % n + 1;
	cout << n << " " << x << endl;
	for(int i = 0; i < n; i++) {
		int x = rand() % n;
		cout << 999 << " ";
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*
79
89
15 12 1 20 17 21 9 15 8 7 8 25 20 15 1 12 7 2 6 14 6 1 2 23 9 24 3 3 13 16 3 2 19 25 1 18 20 17 14 25 10 1 12 15 5 2 19 18 3 8 4 2 18 4 10 6 6 23 13 3 2 19 2 11 13 2 4 8 6 17 7 21 21 4 25 17 11 2 9 15 9 11 2 13 20 12 8 6 14


79
85
15 12 1 20 17 21 9 15 8 7 8 25 20 15 1 12 7 2 6 23 9 24 3 3 13 16 3 2 19 25 1 18 20 17 14 25 10 1 12 15 5 2 19 18 3 8 4 2 18 4 10 6 6 23 13 3 2 19 2 11 13 2 4 8 6 17 7 21 21 4 25 17 11 2 9 15 9 11 2 13 20 12 8 6 14

*/
