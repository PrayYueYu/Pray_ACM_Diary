#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 100;
int n, f[N][N], vis[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
bitset<N> B[N];
signed main() {
	n = read();
	srand(time(0));
	int Max = -1, fi = 0, num1 = 0;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < n; j++) {
			if(s[j] == '1') {
				f[i][j + 1] = 1;
				num1++;
			}
			B[i][j] = s[j] - '0';
		}
		if(num1 > Max) {
			Max = num1;
			fi = i; 
		}
	}
	vector<int> ans;
	int num = 0, ne = fi;
	while(true) {
		int x = 0;
		if(num == n) break;
		while(true) {
			if(ne) break;
			x = rand() % n + 1;
			if(vis[x]) continue;
			else {
				ne = x;
				break;
			}
		}
		x = ne; ne = 0;
		int fx = true;
		for(register int i = 1; i <= n; i++) {
			if(i == x) continue;
			if(f[x][i]) continue;
			if((B[x] & B[i]) == B[x]) {
				if(!vis[i]) ne = i;
				fx = false;
			}
		}
		//cout << x << endl;
		vis[x] = true;
		num++;
		if(fx) {
			ans.push_back(x);
			if(ans.size() == 3) break;
		}
	}
	if(ans.size() < 3) {
		cout << "NOT FOUND";
	}
	else cout << ans[0] << " " << ans[1] << " " << ans[2];
	return 0;
} 
/*
1001 1100 0100 0000
0110 0011 1011 1111
*/
