#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], b[N], bn[100], p[100], px[100];
int read() {
	int x;
	cin >> x;
	return x;
}
map<int, int> mp[40], vis;
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) b[i] = read();
	
	for(int i = 0; i <= 30; i++) mp[i].clear();
	for(int i = 1; i < n; i++) {
		int t = a[i] ^ a[i + 1], id = vis[t];
		if(!id) continue; 
		id--;
		int now = a[i] & px[id];//取0~len+1位 
		mp[id][now]++;
	}
	int ans = 0;
	for(int i = 1; i < m; i++) {
		if((b[i] ^ b[i + 1]) == 1) {
			for(int j = 0; j <= 30; j++) {//枚举len 
				int x = b[i] ^ bn[j];//枚举后缀，并异或
				int now = x & px[j];//只需要0~len+1，取0~len+1位 
				ans += mp[j][now];//加上答案
			}
		}
	}
	cout << ans << '\n';
}
signed main() {
	bn[0] = 0; int r = 2; p[0] = 1;
	vis[2] = 1; px[0] = 3;
	for(int i = 1; i <= 30; i++) {
		bn[i] = bn[i - 1] + (1ll << i);
		r = r * 2 + 2;
		p[i] = p[i - 1] * 2;
		vis[r] = i + 1;
		px[i] = px[i - 1] + (1ll << (i + 1));
	}
    //bn：枚举的x后缀
    //r: 记录 2^{len+2}-2
    //vis：标记 r 以及对应的 len
    //px：用&操作加速，x&px[i]代表只取其0~i+1位
    int T = read();
    while(T--) solve();
    return 0;
}
/*

*/
