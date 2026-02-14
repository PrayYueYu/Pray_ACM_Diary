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
	std::cout << "一生推不如一生恋\n";
	std::cout << "FLOWERS\n";
	std::cout << "梅时露霁书~雨潺海汐间~\n";
	std::cout << "梦现Re:Master\n";
	std::cout << "魔法少女的魔女审判\n";
	std::cout << "青空下的加缪\n";
	std::cout << "提早绽放的黑百合\n";
	std::cout << "言语关系\n";
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

*/
