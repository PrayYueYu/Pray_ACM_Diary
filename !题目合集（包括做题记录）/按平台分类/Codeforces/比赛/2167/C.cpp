#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
int ans[N], a[N], n;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}

void solve() {
	n = read();
	int num = 0;
	vector<int> v1, v2;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(a[i] & 1) v2.push_back(a[i]);
		else v1.push_back(a[i]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	if(v1.size() && v2.size()) {
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << endl;
	}
	else {
		for(int i = 1; i <= n; i++) cout <<a[i] <<  " ";
		cout << endl;
	}
}
signed main() {
	int T = read();
	while(T--) {
		solve();
	//	init();
	}
	return 0;
} 
