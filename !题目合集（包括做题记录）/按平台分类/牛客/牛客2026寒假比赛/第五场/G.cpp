#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void solve() {
//	std::string s;
//	std::cin >> s;
//	s = " " + s;
//	int f = 0;
//	for(int i = 1; i <= 100; i++) {
//		if(s[i] == '0') f = 3 - f;
//		else if(s[i] == '1') {
//			if(f & 1) f = 4 - f;
//		}
//		else if(s[i] == '2') {
//			if(f <= 1) f = 1 - f;
//			else f = 5 - f;
//		}
//		else if(s[i] == '3') {
//			if(!(f & 1)) f = 2 - f;
//		}
//		else if(s[i] == '4') {
//			f = (f + 1) % 4;
//		}
//		else {
//			f = (f - 1 + 4) % 4;
//		}
//		std::cout << f;
//	}
	std::cout << "3132333010010310230010130130330130312312210210010321300120122322322101123223211001003013030031210332";
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532

*/
