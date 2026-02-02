#include<bits/stdc++.h>
#define ll long long
#define int long long 
using namespace std;
const int N = 3e5 + 200, INF = 2e18;
int n;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void cfl() {
	cout.flush();
} 
void solve() {
	cin >> n;
	int idx = 0, idy = 0;
	for(int i = 1; i <= n; i += 2) {
		if(i + 1 > n) break;
		cout << "? " << i << " " << i + 1 << '\n';
		cfl();
		int x; cin >> x;
		if(x) {
			idx = i, idy = i + 1;
			break;
		}
	}
	if(n & 1) {
		cout << "? " << n - 1 << " " << n << '\n';
		cfl();
		int x; cin >> x;
		if(x) {
			idx = n - 1, idy = n;
		}
	}
	if(!idx) {
		cout << "! 1\n";
		cfl();
		return;
	}
	int elx = 0, ely = 0;
	for(int i = 1; i <= n; i++) {
		if(i != idx && i != idy) {
			if(!elx) elx = i;
			else {
				ely = i;
				break;
			}
		}
	}
	int x;
	cout << "? " << elx << " " << idx << '\n';
	cfl();
	cin >> x;
	if(x) {
		cout << "? " << ely << " " << idx << '\n';
		cfl();
		cin >> x;
		if(x) cout << "! 2\n";
		else cout << "! 1\n";
		cfl();
		return;
	}
	else {
		cout << "? " << elx << " " << idy << '\n';
		cfl();
		cin >> x;
		if(x) {
			cout << "? " << ely << " " << idy << '\n';
			cfl();
			cin >> x;
			if(x) cout << "! 2\n";
			else cout << "! 1\n";
			cfl();
			return;
		}
		cout << "! 1\n";
		cfl();
		return;
	}
}
signed main() {
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
    return 0;
}
