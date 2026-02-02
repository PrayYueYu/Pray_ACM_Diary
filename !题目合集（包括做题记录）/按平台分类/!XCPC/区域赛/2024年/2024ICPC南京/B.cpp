#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 2e5 + 100, M = 1e9 + 7, INF = 1e18;
char dq[N];
int n;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
bool check(char x, char y) {
	if(x == '1' && y =='0') return true;
	if(x == '0' && y =='1') return true;
	return false;
}
void solve() {
	string s;
	cin >> s;
	n = s.size();
	s = " " + s;
	for(int i = 1; i <= n; i++) {
		if(i & 1) continue;
		if(s[i] == '1') s[i] = '0';
		else if(s[i] == '0') s[i] = '1';
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(cnt && check(dq[cnt], s[i])) cnt--;
		else dq[++cnt] = s[i];
	}
	int num1 = 0, num2 = 0;
	s = " ";
	for(int i = 1; i <= cnt; i++) {
		if(dq[i] == '1') num1++;
		else if(dq[i] == '0') num2++;
		s += dq[i];
	}
	n = cnt;
	cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '2') {
			if(num1 > num2) num2++, s[i] = '0';
			else num1++, s[i] = '1';
		}
		if(cnt && check(dq[cnt], s[i])) cnt--;
		else dq[++cnt] = s[i];		
	}
	cout << cnt << endl;
}
signed main() {
	int T = read();
	while(T--) {
		solve();
	}
    return 0;
}
