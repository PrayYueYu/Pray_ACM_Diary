#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7;
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
string rev(string s) {
	string ans = "";
	for(int i = s.size() - 1; i >= 0; i--) {
		ans += s[i];
	}
	return ans;
}
string calc(string s1, string s2) {
	int l1 = s1.size() - 1, l2 = s2.size() - 1;
	int ad = 0;
	string ans = "";
	while(true) {
		int x = s1[l1] - '0' + s2[l2] - '0' + ad;
		if(x >= 2) {
			x -= 2;
			ad = 1;
		}
		else ad = 0;
		ans += (char)(x + '0');
		l1--, l2--;
		if(l2 < 0) break;
	}
	while(true) {
		int x = s1[l1] - '0' + ad;
		if(x >= 2) {
			x -= 2;
			ad = 1;
		}
		else ad = 0;
		ans += (char)(x + '0');
		l1--;
		if(l1 < 0) break;
	}
	if(ad) ans += "1";
	ans = rev(ans);
	return ans;
}
void solve() {
	string x;
	cin >> x;
	string s1 = x + "0000";
	string s2 = x + "00";
	string s3 = x;
	s2 = calc(s2, s3);
	s1 = calc(s1, s2);
	cout << s1;
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
