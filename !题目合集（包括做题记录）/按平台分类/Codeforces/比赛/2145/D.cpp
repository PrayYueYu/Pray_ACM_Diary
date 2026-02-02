#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 10, INF = 1e16;
int n, k, Max[100];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
vector<int> v[32][1000];
int getx(vector<int> & a) {
	vector<pair<int, int>> b;
	for(int i = 0; i < a.size(); i++) {
		for(int j = i + 1; j < a.size(); j++) {
			if(a[i] > a[j]) {
				b.push_back({i, j});
			}
		}
	}
//	cout << b.size() << endl;
	for(int i = 0; i < a.size(); i++) Max[i] = -1;
	for(auto u: b) {
		int l = u.first, r = u.second;
		Max[r] = max(Max[r], l);
	}
	for(int i = 0; i < a.size(); i++) {
		if(!i) continue;
		Max[i] = max(Max[i], Max[i - 1]);
	}
	int sum = 0;
	for(int i = 0; i < a.size(); i++) {
		for(int j = i + 1; j < a.size(); j++) {
			int L = Max[j];
			if(i <= L) {
				sum++;
			//	cout << L << endl;
			}
		}
	}
	return sum;
}
void init() {
	v[1][0] = {1};
//	v[1][1] = {1, 2, 3, 4, 5};
//	cout << getx(v[1][1]) << endl;
//	system("pause");
	for(int i = 2; i <= 30; i++) {
		for(int j = 0; j <= i - 1; j++) {
			n = i - 1;
			for(int k = 0; k <= (i - 1) * (i - 2) / 2; k++) {
				int sum = (n - j) * (j + 1);
				if(!v[i - 1][k].size()) continue;
				
				vector<int> now;
				int tot = 0;
				if(!j) now.push_back(i);
				for(int p = 0; p < n; p++) {
					now.push_back(v[i - 1][k][p]);
					if(p + 1 == j) now.push_back(i);
				}
				
				int x = getx(now);
				if(v[i][x].size()) continue;
				v[i][x] = now;
			}
		}
		
	}
}
void solve() {
	n = read(), k = read();
	if(!v[n][k].size()) cout << 0 << endl;
	else {
		for(auto ans: v[n][k]) cout << ans << " ";
		cout << endl;
	}
}
signed main() {
	init();
   int T = read();
   while(T--) {
		solve();
	//	init();
   }
    return 0;
}
/*
5 6
1 2 1 2 1
2 1 2 2
2 1 3 3
1 1 1
1 3 5
2 1 2 4
2 1 2 2
*/
