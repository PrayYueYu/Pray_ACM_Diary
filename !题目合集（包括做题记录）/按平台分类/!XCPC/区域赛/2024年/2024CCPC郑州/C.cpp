#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const int N = 1e5 + 100, INF = 2e9;
int n, m, A, B, x, y;
int w1[N], w2[N], cnt1, cnt2;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
map<int, int> mp;
struct ANS {
	int a, b, c, d;
} ans[N];
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("2.out","w",stdout);
	A = read(), B = read();
	x = read(), y = read();
	if(!x && !y) {
		cout << 0 << endl;
		return 0;
	}
	if(x > A || y > B) {
		cout << -1 << endl;
		return 0;
	}
	int now = 1;
	mp[now] = true;
	while(true) {
		now *= 2;
		if(now > INF) break;
		mp[now] = true;
	}
	int g1 = __gcd(A, x);
	int tx1 = x, tx2 = A;
	if(g1) {
		tx1 /= g1, tx2 /= g1;
		if(!mp[tx2]) {
			cout << -1;
			return 0;
		}
	}
	int g2 = __gcd(B, y);
	int ty1 = y, ty2 = B;
	if(g2) {
		ty1 /= g2, ty2 /= g2;
		if(!mp[ty2]) {
			cout << -1;
			return 0;
		}
	}
	int new1 = A, new2 = B, num = 0;
	if(!tx1) new1 = 0;
	if(!ty1) new2 = 0;
	while(true) {
		if(!tx1 || tx1 == tx2) break;
		if(tx1 == 1 && tx2 == 2) {
			w1[++cnt1] = 0;
			break;
		}
		if(tx1 * 2 >= tx2) {
			w1[++cnt1] = 1;
			tx2 /= 2;
			tx1 -= tx2;
		}
		else {
			w1[++cnt1] = 0;
			tx2 /= 2;
		}
	}
	while(true) {
		if(!ty1 || ty1 == ty2) break;
		if(ty1 == 1 && ty2 == 2) {
			w2[++cnt2] = 0;
			break;
		}
		if(ty1 * 2 >= ty2) {
			w2[++cnt2] = 1;
			ty2 /= 2;
			ty1 -= ty2;
		}
		else {
			w2[++cnt2] = 0;
			ty2 /= 2;
		}		
	}
	
	while(true) {
		if(cnt1 > cnt2) {
			num++;
			int s = 0;
			if(w1[cnt1] == 0) s = 0;
			else s = A;
			ans[num] = {new1, new2, s, new2};
			new1 = (new1 + s) / 2;
			cnt1--;
		}
		else break;
	}
	while(true) {
		if(cnt2 > cnt1) {
			num++;
			int s = 0;
			if(w2[cnt2] == 0) s = 0;
			else s = B;
			ans[num] = {new1, new2, new1, s};
			new2 = (new2 + s) / 2;
			cnt2--;
		}
		else break;
	}
	for(int i = cnt2; i >= 1; i--) {
		num++;
		int s1 = 0, s2 = 0;
		if(w1[cnt1] == 1) s1 = A;
		if(w2[cnt2] == 1) s2 = B;
		ans[num] = {new1, new2, s1, s2};
		new1 = (new1 + s1) / 2;
		new2 = (new2 + s2) / 2;
		cnt1--;
		cnt2--;
	}
	cout << num << endl;
	for(int i = 1; i <= num; i++) {
		cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << " " << ans[i].d << endl;
	}
	return 0;
}
/*

*/
