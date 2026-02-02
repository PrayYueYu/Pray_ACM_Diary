#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100, INF = 2e18; 
int n, k;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
signed main() {
	n = read(), k = read();
	string s = "";
	cin >> s;
	s = " " + s;
	int num = 0, f = false, l = 0, r = 0;
	vector<int> v;
	for(int i = 1; i <= n; i++) {
		if((i == 1 && s[i] == '0') || (s[i] == '0' && s[i - 1] == '1')) {
			l = i;
		}
		if((i == n && s[i] == '0') || (s[i] == '0' && s[i + 1] == '1')) {
			r = i;
			v.push_back(r - l + 1);
		}
	}
	sort(v.begin(), v.end());
	num = 0;
	for(int i = 0; i < v.size(); i++) {
		num += (v[i] / k);
	}
	//cout << num << endl;
	int res = n - (num * k);
	int ans = (res / k) * k;
	if(num & 1) ans += (((num + 1) / 2) * k);
	else ans += ((num / 2) * k);
	cout << ans;
    return 0;
}
/*

*/
