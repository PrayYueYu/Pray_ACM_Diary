#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 2;
int ans1[N], ans2[N], vis[N], n;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
struct S {
	int a, b;
	int id;
} s1[N];
bool cmp1(S x, S y) {
	return x.a + x.b > y.a + y.b;
}
signed main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		s1[i].a = read();
		s1[i].id = i;
	}
	for(int i = 1; i <= n; i++) {
		s1[i].b = read();
		//s2[i].id = i;
	}
	sort(s1 + 1, s1 + n + 1, cmp1);
	//sort(s2 + 1, s2 + n + 1, cmp2);
	int i = 1, j = 1, num1 = 0, num2 = 0;
	while(true) {
		if(num1 + num2 >= n) break;
		while(true) {
			if(num1 == num2) {
				int x = s1[i].id;
				if(!vis[x]) {
					vis[x] = true;
					ans1[++num1] = x;
					break;	
				}
				i++;
			}
			else {
				int x = s1[j].id;
				if(!vis[x]) {
					vis[x] = true;
					ans2[++num2] = x;
					break;
				}
				j++;
			}
		}
	}
	for(int i = 1; i <= num1; i++) cout << ans1[i] << ' ';
	cout << '\n';
	for(int i = 1; i <= num2; i++) cout << ans2[i] << ' ';
	return 0;
} 
