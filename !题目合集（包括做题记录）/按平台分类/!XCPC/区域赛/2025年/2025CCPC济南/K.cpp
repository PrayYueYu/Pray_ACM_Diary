#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7;
int n, a[N], cnt[N], to[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
stack<int> s1, s2;
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		cnt[a[i]]++;
	}
	while(!s1.empty()) s1.pop();
	while(!s2.empty()) s2.pop();
	for(int i = 1; i <= n; i++) {
		if(cnt[i] == 0) s1.push(i);
	}
	vector<int> ans;
	if(cnt[a[1]] == 2) {
		s2.push(s1.top());
		s2.push(s1.top());
		s1.pop();
		cnt[a[1]]--;
		cout << 1 << '\n';
	}
	else {
		s2.push(a[1]);
		cout << 0 << '\n';
	}
	for(int i = 2; i <= n; i++) {
		if(cnt[a[i]] == 2) {
			if(!to[a[i]]) {
				to[a[i]] = s1.top();
				ans.push_back(s1.top());
				s1.pop();
			}
			else {
				ans.push_back(to[a[i]]);
			}
		}
		else {
			ans.push_back(s2.top());
			s2.pop();
			if(a[i] != a[1]) s2.push(a[i]);
		}
	}
	ans.push_back(s2.top());
	for(int i = 1; i <= n; i++) {
		cout << ans[i - 1] << ' ';
		cnt[i] = to[i] = 0;
	}
	cout << '\n';
}
signed main() {
	int T = read();
	while(T--) solve();
    return 0;
}
/*

*/
