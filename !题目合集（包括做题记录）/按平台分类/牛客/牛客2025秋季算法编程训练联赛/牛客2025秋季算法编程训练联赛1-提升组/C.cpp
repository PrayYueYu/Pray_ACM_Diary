#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 1e9 + 7;
int P[N], ha[N], n, a, b, c, f[N], p = 131;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
int calc(int r, int l) {
	if(l < 0 || l > r) return -1;
	int len = r - l + 1;
	int ans = (ha[r] - (ha[l - 1] * P[len]) % M + M) % M;
	return ans;
}
int getH(string s) {
	int hx = 0;
	for(int i = 0; i < s.size(); i++) {
		hx = (hx * p + s[i] - 'a' + 1) % M;
	}
	return hx;
}
signed main() {
	n = read(), a = read(), b = read(), c = read();
	string s = "";
	cin >> s;
	s = " " + s;
	string A = "nico", B = "niconi", C = "niconiconi";
	int sA = getH(A);
	int sB = getH(B);
	int sC = getH(C);
	P[0] = 1;
	for(int i = 1; i <= n; i++) {
		ha[i] = (ha[i - 1] * p + s[i] - 'a' + 1) % M;
		P[i] = P[i - 1] * p % M;
	}
	for(int i = 1; i <= n; i++) {
		int s1 = calc(i, i - 3);
		int s2 = calc(i, i - 5);
		int s3 = calc(i, i - 9);
		f[i] = f[i - 1];
		if(s1 == sA) {
			f[i] = max(f[i], f[i - 4] + a);
		}
		if(s2 == sB) {
			f[i] = max(f[i], f[i - 6] + b);
		}
		if(s3 == sC) {
			f[i] = max(f[i], f[i - 10] + c);
		}
	}
	cout << f[n];
	return 0;
}
