#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int H[3], K[3];
std::string ANS[3][3];
int read() {
//	int x = 0, f = 1;
//	char ch = getchar();
//	while(ch < '0' || ch > '9') {
//		if(ch == '-') f = -1;
//		ch = getchar();
//	}
//	while(ch >= '0' && ch <= '9') {
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//	return x * f;
	int x;
	std::cin >> x;
	return x;
}
void solve() {
	int q = read();
	H[1] = 130; H[0] = 129;
	K[1] = 27, K[0] = 25;
	ANS[1][0] = "duo chi yu!";
	ANS[1][1] = "ni li hai!";
	ANS[1][2] = "wan mei!";
	ANS[2][0] = "duo chi rou!";
	ANS[2][1] = "shao chi rou!";
	for(int i = 1; i <= q; i++) {
		int g = read(), h = read(), k = read();
		if(h < H[g]) std::cout << ANS[1][0] << ' ';
		else if(h > H[g]) std::cout << ANS[1][1] << ' ';
		else std::cout << ANS[1][2] << ' ';
		if(k < K[g]) std::cout << ANS[2][0];
		else if(k > K[g]) std::cout << ANS[2][1];
		else std::cout << ANS[1][2];
		std::cout << '\n';
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
