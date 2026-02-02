#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, p, F, vis[20];
int read() {
	int x;
	cin >> x;
	return x;
}
void dfs(int t, int Max, int a, int b) {
	if(t == Max + 1) {
		if(F) return;
		for(int i = 1; i <= Max; i++) {
			if(vis[i] == 0) a -= (i + 1);
			else b -= (i + 1);
		}
		int xx = Max;
		Max = min(21ll - n, 15ll);
		for(int i = 0; i <= Max; i++) {
			int sum = i;
			int ca[20] = {}, cb[20] = {};
			for(int j = 1; j <= i; j++) {
				ca[j] = 2;
				sum += ca[j];
			}
			for(int j = 1; j <= i; j++) {
				if(sum < a) {
					ca[j] += min(a - sum, 5ll);
					sum += min(a - sum, 5ll);
				}
				else if(sum > a){
					sum -= 2;
					ca[j] -= 2;
				}
			}
			if(sum != a) continue;
			sum = Max - i;
			for(int j = 1; j <= Max - i; j++) {
				cb[j] = 2;
				sum += cb[j];
			}
			for(int j = 1; j <= Max - i; j++) {
				if(sum < b) {
					cb[j] += min(b - sum, 5ll);
					sum += min(b - sum, 5ll);
				}
				else if(sum > b){
					sum -= 2;
					cb[j] -= 2;
				}
			}
			if(sum != b) continue;
			for(int j = 1; j <= i; j++) {
				cout << 1;
				if(ca[j]) cout << ca[j];
				else cout << "//";
			}
			cout << '/';
			for(int j = 1; j <= Max - i; j++) {
				cout << 1;
				if(cb[j]) cout << cb[j];
				else cout << "//";
			}
			int nowf = 1;
			for(int j = 1; j <= xx; j++) {
				if(vis[j] == 0) {
					if(nowf == 1) {
						cout << '/';
						nowf = 0;
					}
					cout << j + 1;
				}
				else {
					if(nowf == 0) {
						cout << '/';
						nowf = 1;
					}
					cout << j + 1;
				}
			}
			if(nowf != p) cout << '/';
			cout << '\n';
			F = true;
			break;
		}
		return;
	}
	if(t == 6 && !n) {
		vis[t] = p;
		dfs(t + 1, Max, a, b);
		return;
	}
	vis[t] = 1;
	dfs(t + 1, Max, a, b);
	vis[t] = 0;
	dfs(t + 1, Max, a, b);
}
void solve() {
	int a = read(), b = read();
	n = read(), p = read();
	F = false;
	dfs(1, max(0ll, 6ll - n), a, b);
	if(!F) cout << "NA\n";
}
signed main() {
    int T = read();
    while(T--) solve();
    return 0;
}
/*

*/
