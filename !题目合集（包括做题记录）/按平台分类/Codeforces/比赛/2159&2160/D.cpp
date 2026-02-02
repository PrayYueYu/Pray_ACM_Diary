#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 3e6 + 200, INF = 1e9;
int n, vis[N], visx[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void fls() {
	cout.flush();
}
void solve() {
	cin >> n;
	for(int i = 1; i <= 2 * n; i++) {
		vis[i] = visx[i] = 0;
	}
	for(int i = 2; i <= 2 * n; i++) {
		vector<int> v;
		for(int j = 1; j <= i; j++) {
			if(vis[j]) continue;
			v.push_back(j);
		}
		if(v.size() <= 1) continue;
		cout << "? " << v.size() << " ";
		for(int j = 0; j < v.size(); j++) {
			cout << v[j] << " ";
		}
		cout << '\n';
		fls();
		int x; cin >> x;
		if(x) vis[i] = x;
	}
	for(int i = 2 * n - 1; i >= 1; i--) {
		vector<int> v;
		if(vis[i]) continue;
		for(int j = 2 * n; j >= i; j--) {
			if(visx[j]) continue;
			v.push_back(j);
		}	
		if(v.size() <= 1) continue;
		cout << "? " << v.size() << " ";
		for(int j = 0; j < v.size(); j++) {
			cout << v[j] << " ";
		}
		cout << '\n';
		fls();	
		int x; cin >> x;
		if(x) visx[i] = x;
	}
	cout << "! ";
	for(int i = 1; i <= 2 * n; i++) cout << max(vis[i], visx[i]) <<  " ";
	cout << '\n';
	fls(); 
}
signed main() {
    int T; cin >> T;
    while(T--) {
    	solve();
	}
    return 0;
}
/*

*/
