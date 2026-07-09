#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, a[N];
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
	std::cin >> n >> m;
	double sum = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	ans += (int)sum;
	ans *= 2; ans += m;
	double ave = (double)sum / m;
	sum = 0;
	int k = 0;
	for(int i = 1; i <= n; i++) {
		double x = std::fabs(sum - ave);
		double y = std::fabs(sum + (double)a[i] - ave);
		if(x >= y || k == m - 1) sum += a[i];
		else {
			int now = sum;
			// std::cout << i << ' ' << now << '\n';
			ans += now * now;
			k++;
			sum = a[i];
		}
	}
	ans += (int)sum * (int)sum;
	std::cout << ans << '\n';
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
	Writer: ����ޱ�� 
*/
