#include<bits/stdc++.h>
using namespace std;
int n, sum[1000], num[1000][1000];
int read() {
	int x;
	scanf("%d", &x);
	return x;
}
signed main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		int a = read(), b = read();
		int c = read();
		if(!num[a][b]) {
			num[a][b] = true;
			if(c < 240) {
				cout << b << '\n';
				sum[a]++;
			}
			else {
				if(sum[a] < 3) {
					sum[a]++;
					cout << b << '\n';
				}
				else cout << 0 << '\n';
			}
		}
		else cout << "0\n";
	}
	return 0;
}
