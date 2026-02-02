#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, l, d;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
int calc() {
	int minn = 0;
	if((l - n) % d == 0) {
		minn = (l - n) / d * n;
	}
	else {
		int x = (l - n) / d;
		minn = x * n;
		int L = x * d + 1 + d;
		if(L > l) minn++;
		else minn = minn + 1 + (l - L);
	}
	return minn;
}
void solve() {
	n = read();
	d = read();
	l = read();
	int maxn = (l - 1 - n) * n + 1;
	int minn = calc();
	cout << minn << ' ' << maxn << '\n';
	
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
} 
