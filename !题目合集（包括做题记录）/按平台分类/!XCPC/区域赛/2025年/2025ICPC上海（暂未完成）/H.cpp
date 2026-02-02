#include<bits/stdc++.h>
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7;
int n;
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
void solve() {
	
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}

/*

*/
