#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
int a[N], b[N], n, m, visa[N], visb[N];
int Tx, tot;
int read() {
	int x = 0;
	scanf("%lld", &x);
	return x;
}
void init() {
	for(int i = 0; i <= n + 5; i++) visa[i] = false;
	for(int i = 0; i <= m + 5; i++) visb[i] = false;
}
void solve() {
	n = read(), m = read();
	int us = 0, nd = 0, cnt = 0, bo = 0;
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) b[i] = read();
	tot++;
	if(Tx == 525) {
		if(tot != 84) return;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	for(int i = 1; i <= n; i++) {
		if(a[i] != 1) a[i]--, us++;
		else {
			cnt++;
			visa[i] = true;
		}
	}
	for(int i = 1; i <= m; i++) {
		if(b[i] > i - 1) nd += b[i] - (i - 1);
	}
	if(cnt) us++;
	if(nd <= us) {
		if(Tx != 525) cout << "Yes\n";
		return;
	}
	bo += cnt;
	int fia = 1, fib = 1;
	while(true) {
		int f = false;
		for(int i = fia; i <= n; i++) {
			if(visa[i]) {
				fia = i + 1;
				continue;
			}
			if(a[i] <= bo) {
				visa[i] = true;
				bo++;
				fia = i + 1;
				f = true;
			}
			else {
				fia = i;
				break;
			}
			
		}
		if(f) continue;
		for(int i = fib; i <= m; i++) {
			if(visb[i]) {
				fib = i + 1;
				continue;
			}
			if(b[i] <= bo) {
				visb[i] = true;
				bo++;
				fib = i + 1;
				f = true;
				break;
			}
			else {
				if((b[i] - bo) <= us) {
					us -= (b[i] - bo);
					bo++;
					visb[i] = true;
					f = true;
					fib = i + 1;
					break;
				}
				else {
					fib = i;
					break;
				}
			}
		}
		if(!f) break;
	}
	int f = true;
	for(int i = 1; i <= m; i++) {
		if(!visb[i]) {
			f = false;
			break;
		}
	}
	if(Tx == 525) {
		if(f) cout << "Yes\n";
		cout << n << " " << m << " " << f << endl;
		for(int i = 1; i <= n; i++) cout << a[i] << ' ';
		cout << '\n';
		for(int i = 1; i <= m; i++) {
			cout << b[i] << ' ';
		}
		cout << endl;
		
		exit(0);
	}
	else {
		if(f) cout << "Yes\n";
		else cout << "No\n";
	}
}
signed main(){
	int T = read();
	Tx = 0;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
