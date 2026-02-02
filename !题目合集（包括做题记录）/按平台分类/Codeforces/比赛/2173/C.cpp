#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7, INF = 1e18;
int n, k, a[N];
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
map<int, int> mp, mpx;
void solve() {
	n = read();
	k = read();
	priority_queue<int> q;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		mp[a[i]] = true;
		q.push(-a[i]);
	}
	int f = true;
	vector<int> ans;
	while(!q.empty()) {
		int x = -q.top();
		q.pop();
		if(mpx[x]) continue;
		for(int i = 1; ; i++) {
			if(x * i > k) break;
			if(mp[x * i] == 0) {
				f = false;
				break;
			}
			else mpx[x * i] = 1;
		}
		if(!f) break;
		ans.push_back(x);
		
	}
	if(!f) cout << -1 << '\n';
	else {
		cout << ans.size() << '\n';
		for(auto x: ans) cout << x << ' ';
		cout << endl;
	}
	
	mp.clear();
	mpx.clear();
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
