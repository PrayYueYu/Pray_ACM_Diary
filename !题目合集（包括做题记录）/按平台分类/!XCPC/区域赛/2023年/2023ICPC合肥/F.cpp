#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 2e7 + 200, INF = 2e18;
int n;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
map<string, int> mp;
signed main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		mp[s]++;
		if(mp[s] * 2 > n) {
			cout << s;
			return 0;
		}
	}
	cout << "uh-oh";
    return 0;
}
/*

*/
