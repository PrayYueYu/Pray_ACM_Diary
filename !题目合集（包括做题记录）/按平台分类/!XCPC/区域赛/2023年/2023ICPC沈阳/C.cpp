#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 5e5 + 100, M = 998244353, INF = 1e16;
int read() {
	int x;
	cin >> x;
	return x;
}
void solve() {
	
}
signed main() {
	int x = read(), y = read();
	if(!x && y <= 1) {
		cout << 4 << endl;
	}
	else if(!x && y == 2) {
		cout << 6 << endl;
	}
	else if(x == 1 && y <= 1) {
		cout << 3 << endl;
	}
	else if(x == 1 && y == 2) {
		cout << 4 << endl;
	}
	else if(x == 2 && y <= 2) {
		cout << 2 << endl;
	}
	return 0;
}
/*

*/
