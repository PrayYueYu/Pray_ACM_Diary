#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 100;
int n, ansl[N], ansr[N];
int Tx, tot;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void solve() {
	string s;
	cin >> s;
	n = s.size();
	s = " " + s + " ";
	int cnt = 0, L = 0;
	for(int i = n; i >= 1; i--) {
		if(s[i] == '>') {
			L = i;
		}
		else break;
	}
	if((n - L + 1) <= 2 || L == 1 || s[1] == '-') {
		cout << "No\n";
		return;
	}
	int now = n;
	for(int i = n; i >= L; i--) {
		ansl[++cnt] = i - 5 + 1;
		ansr[cnt] = 5;
		if(ansl[cnt] <= 0) {
			cnt--;
			break;
		}
	}
	int f = false;
	now = L + 2;
	for(int i = 1; i <= L - 1; i++) {
		if(s[i] == '>') {
			f = true;
			ansl[++cnt] = i;
			ansr[cnt] = now - i + 1;
		}
	}
	if(!f || now != L + 2) {
		cout << "No\n";
		return;
	}
	cout << "Yes " << cnt << endl;
	for(int i = 1; i <= cnt; i++) {
		cout << ansl[i] << " " << ansr[i] << endl;
	}
}
signed main() {
	int T = read();
	Tx = T;
	while(T--) solve();
	return 0;
} 
