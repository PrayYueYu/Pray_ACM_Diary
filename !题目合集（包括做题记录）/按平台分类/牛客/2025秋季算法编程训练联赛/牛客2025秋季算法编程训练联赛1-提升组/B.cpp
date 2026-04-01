#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 1e9 + 7;
int n, k;
string s;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
bool check(int mid) {
	int num0 = 0, num1 = 0;
	for(int i = 1; i <= n; i++) {
		if(i < mid) {
			if(s[i] == '0') num0++;
			else num1++;
			continue;
		}
		if(s[i] == '0') num0++;
		else num1++;
		if(i > mid) {
			if(s[i - mid] == '0') num0--;
			else num1--;
		}
		if(num1 <= k || num0 <= k) return true;
	}
	return false;
}
signed main() {
	n = read(), k = read();
	cin >> s;
	s = " " + s;
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}
