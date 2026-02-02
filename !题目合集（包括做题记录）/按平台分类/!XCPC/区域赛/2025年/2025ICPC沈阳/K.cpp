#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define y1 yy
#define int long long
map<pii,int> M;
const int N = 2e5 + 100;
int y1[N], y2[N], x1[N], x2[N], n, m;
int read() {
	int x;
	cin >> x;
	return x;
}
signed main(){
	int n,m;
	cin>>n>>m;
	int sa=0,sb=0;
	for(int i=1;i<=n;i++){
		x1[i] = read(), y1[i] = read();
		x2[i] = read(), y2[i] = read();
		sa+=x2[i]-x1[i];
		sb+=y2[i]-y1[i];
	}
	sa /= 2, sb /= 2;
	//cout << sa << " " << sb << endl;
	for(int i = 1; i <= n; i++) {
	//	cout << x2[i] - x1[m] << " " << y2[i] << " " << 
		if(sa == x2[i] - x1[m] && sb == y2[i] - y1[m]) {
			cout << i;
			return 0;
		}
	}
	
}

