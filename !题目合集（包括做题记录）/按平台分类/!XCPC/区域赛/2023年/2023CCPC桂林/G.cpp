#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 100;
int n, sum[N], w;
int read() {
	int x;
	cin >> x;
	return x;
}
void solve() {
	string s, ans = "";
	cin >> s;
	n = s.size();
	s = " " + s;
	w += n + 1;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		w++;
		sum[i] = sum[i - 1];
		if(s[i] == '(') sum[i]++;
		else sum[i]--;
		if(!cnt && s[i] == ')') continue;
		if(s[i] == '(') cnt++;
		else cnt--;
	}
	int p = n;
	for(int i = n; i >= 1; i--) {
		w++;
		if(s[i] == ')') {
			int len = n - i + 1;
			int l = i - len;
			if(l <= 0) break;
			if(sum[n] - sum[l - 1] == 0) p = i - 1;
		}
		else break;
	}
	if(cnt > 0) {
		cout << "impossible\n";
		return;
	}
	for(int i = 1; i <= p; i++) {
		w++;
		cout << s[i];
	}
	cout << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = read();
	while(T--) {
		solve();
	}
	return 0;
} 
