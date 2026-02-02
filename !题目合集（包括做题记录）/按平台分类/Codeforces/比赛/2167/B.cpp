#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
int num[N], n;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void init() {
	for(int i = 'a'; i <= 'z'; i++) {
		num[i] = 0;
	}
}
void solve() {
	string s1, s2;
	cin >> n;
	cin >> s1 >> s2;
	if(s1.size() != s2.size()) {
		cout << "NO\n";
		return;
	}
	for(int i = 0; i < s1.size(); i++) {
		num[s1[i]]++;
	}
	for(int i = 0; i < s2.size(); i++) {
		num[s2[i]]--;
		if(num[s2[i]] < 0) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
} 
