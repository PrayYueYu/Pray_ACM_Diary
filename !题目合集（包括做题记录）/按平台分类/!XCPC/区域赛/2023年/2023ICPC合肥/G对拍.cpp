#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int dp[N][6][2], pre[N];
int n,m,k;
string s;

void solve(){
	auto check = [&](int mid){
		for (int i = 0; i <= n; i++)
			for(int j = 0; j <= k; j++)
				dp[i][j][0] = dp[i][j][1] = 0x3f3f3f3f;

		dp[0][0][0] = 0;
		for (int i = 1; i <= n; i++){
			for(int j = 0; j <= k; j++){
				if(s[i]=='0'){
					dp[i][j][0] = min({dp[i][j][0], dp[i-1][j][0], dp[i-1][j][1]});
					dp[i][j][1] = min({dp[i][j][1], dp[i-1][j][1] + 1});
				}else{
					dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0]);
					dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][1]);
				}
				if (i >= mid && j >= 1)
					dp[i][j][1] = min(dp[i][j][1], dp[i-mid][j-1][0] + pre[i] - pre[i-mid]);
			}
		}

		return min(dp[n][k][0], dp[n][k][1]) <= m;
	};

	cin>>n>>m>>k>>s;
	s = "@" + s;
	for(int i = 1; i<=n; i++){
		pre[i] += pre[i-1] + (s[i] == '0');
	}
	int l = 0, r = 2e5;
	while (l < r){
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	if(l)
		cout<<l<<'\n';
	else cout << "-1\n";

}

int main() {
	freopen("1.in", "r", stdin);
	int t = 1;
	while (t--)
		solve();

	return 0;
}


