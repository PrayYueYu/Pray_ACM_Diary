#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 2e6 + 10, M = 1e9 + 7, INF = 1e18;
int n, fa[N];
string s1, s2, s3;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int GetFa(int x) {
	return x == fa[x]? x: fa[x] = GetFa(fa[x]);
}
void merge(int x, int y) {
	int fax = GetFa(x), fay = GetFa(y);
	if(fax != fay) {
		fa[fax] = fay;
	} 
}
signed main() {
	int T = read();
	while(T--) {
		cin >> s1 >> s2 >> s3;
		int l1 = s1.size(), l2 = s2.size();
		int l3 = s3.size();
		s1 = " " + s1;
		s2 = " " + s2;
		s3 = " " + s3;
		if(l1 != l2) {
			cout << "NO\n";
			continue;
		}
		if(l1 != l3) {
			cout << "YES\n";
			continue;
		}
		for(int i = 0; i <= 25; i++) fa[i] = i;
		n = l1;
		for(int i = 1; i <= n; i++) {
			if(s1[i] != s2[i]) {
				int p1 = s1[i] - 'a';
				int p2 = s2[i] - 'a';
				merge(p1, p2);
			}
		}
		int f = false;
		for(int i = 1; i <= n; i++) {
			int x = GetFa(s1[i] - 'a');
			int y = GetFa(s3[i] - 'a');
			if(x != y) f = true;
		}
		if(f) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
