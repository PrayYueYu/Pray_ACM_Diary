#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, M = 1e6 + 9;
int n, num[N], to[N];
int read() {
	int x;
	scanf("%d", &x);
	return x;
}
struct A {
	int a, id;
} s[N], las[N];
bool cmp(A x, A y) {
	return x.a < y.a;
}
bool cmp2(A x, A y) {
	return x.id < y.id;
}
void solve() {
	n = read(); int t = read(), T; T = t;
	for(int i = 1; i <= n; i++) {
		s[i].a = read();
		s[i].id = i;
	}
	int cnt = 3;
	while(true) {
		sort(s + 1, s + n + 1, cmp);
		int f = -1;
		for(int i = 1; i <= n; i++) {
			las[i] = s[i];
			if(s[i].a > n + 1) continue;
			num[s[i].a]++;
		}
		for(int i = 0; i <= n + 1; i++) {
			if(f == -1) {
				if(num[i] >= 2) to[i] = -1;
				else if(num[i] == 1) to[i] = i;
				else f = i;
			}
			if(f != -1) to[i] = f;
			num[i] = 0;
		}
		for(int i = 0; i <= n + 1; i++) {
			if(to[i] == -1) to[i] = f;
		}
		for(int i = 1; i <= n; i++) {
			if(s[i].a > n) s[i].a = to[n];
			else s[i].a = to[s[i].a];
		}
		t--;
		cnt--;
		if(!t || !cnt) break;
	}
	
	if(!t) {
		sort(s + 1, s + n + 1, cmp2);
		for(int i = 1; i <= n; i++) {
			cout << s[i].a << ' ';
		}
		cout << '\n';
	}
	else {
		if(T & 1) sort(s + 1, s + n + 1, cmp2);
		else sort(las + 1, las + n + 1, cmp2);
		for(int i = 1; i <= n; i++) {
			if(T & 1) cout << s[i].a << ' ';
			else cout << las[i].a << ' ';
		}
		cout << '\n';
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = read();
	while(T--) solve();
    return 0;
}
