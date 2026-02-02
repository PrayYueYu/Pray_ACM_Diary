#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100, INF = 2e18; 
int n, a, b;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
signed main() {
	n = read(), a = read(), b = read();
	string s = "";
	cin >> s;
	int l = 0, r = 0;
	int numa = 0, numb = 0, ans = 0;
	s = " " + s;
	for(int i = 1; i <= n; i++) {
		while(true) {
			if(l == n) break;
			if(numa >= a) break;
			if(s[l + 1] == 'a') numa++, l++;
			else l++;
		}
		while(true) {
			if(r == n) break;
			if(s[r + 1] == 'b') {
				if(numb + 1 >= b) break;
				else r++, numb++;
			}
			else r++;
		}
		if(r >= l) {
			if(numa >= a && numb < b) {
				ans += r - l + 1;
			}
		}
		if(s[i] == 'a') numa--;
		else numb--;
	}
	cout << ans;
    return 0;
}
/*

*/
