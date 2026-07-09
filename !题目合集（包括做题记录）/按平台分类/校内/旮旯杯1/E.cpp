#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n;
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

}
signed main() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		int x; std::cin >> x;
		std::cout << (char)x;
	}
	return 0;
}
/*
	Writer: ����ޱ�� 
*/
