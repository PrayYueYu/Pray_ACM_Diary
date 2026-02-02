#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100, INF = 2e18; 
int n, a[N][4], num[4];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
priority_queue<pair<int, int>> q;
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		int Max = -1, id = 0, Max2 = -1;
		for(int j = 1; j <= 3; j++) {
			a[i][j] = read();
			if(a[i][j] > Max) {
				Max = a[i][j];
				id = j;
			}
		}
		for(int j = 1; j <= 3; j++) {
			if(j == id) continue;
			Max2 = max(Max2, a[i][j]);
		}
		q.push({Max - Max2, i});
	}
	int ans = 0;
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		int Max = -1, id = 0;
		for(int i = 1; i <= 3; i++) {
			if(Max < a[u][i]) {
				Max = a[u][i];
				id = i;
			}
		}
		if(num[id] == n / 2) {
			int Max2 = -1;
			for(int i = 1; i <= 3; i++) {
				if(id == i) continue;
				Max2 = max(Max2, a[u][i]);
			}
			ans += Max2;
		}
		else {
			num[id]++;
			ans += a[u][id];
		}
	}
	num[1] = num[2] = num[3] = 0;
	cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) solve(); 
    return 0;
}
/*

*/
