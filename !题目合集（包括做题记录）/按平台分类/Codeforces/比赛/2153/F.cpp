#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
const int N = 5e5 + 100, M = 998244353, INF = 1e9 + 10;
const int SN = sqrt(N) + 5;
int n, m, visL[N], visR[N], vis[N], a[N];
int sum[N], one[N], to[N], b[N];
ll val[SN][SN];
bitset<N / 2 + 5> bs[SN];
//把只出现过一次的记录下来，那剩下的个数不会超过n/2 
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f= -1;
		ch = getchar();
	}
	while(ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void print(ll x){
	if(!x)putchar(48);
	else{
		int d[20];
		for(d[0]=0;x;d[++d[0]]=x%10,x/=10);
		for(;d[0];putchar(d[d[0]--]^48));
	}
}
void pre() {
	int Len = sqrt(n), L = 0, R = 0, t = 0;
	while(true) {
		t++;
		L = R + 1;
		R = min(L + Len - 1, n);
		visL[t] = L;
		visR[t] = R;
		for(int i = L; i <= R; i++) vis[i] = t;
		if(R == n) break;
	}
	for(int i = 1; i <= n; i++) {
		one[a[i]]++;
	}
	int tt = 0;
	for(re int i = 1; i <= n; i++) {
		if(one[i] > 1) to[i] = ++tt;
		else to[i] = 0;
	}
	for(re int i = 1; i <= n; i++) {
		b[i] = to[a[i]];
		one[a[i]] = 0;
	}
	for(re int i = 1; i <= t; i++) {
		bs[i] = bs[i - 1];
		for(re int j = visL[i]; j <= visR[i]; j++) {
			bs[i].flip(b[j]);
		}
		//1~i块奇偶次bitset的异或和
		//可用前缀和思想快速求出[l,r]
		//[l,r]的bitset=bs[r]^bs[l-1] 
	}
	for(re int i = 1; i <= t; i++) {
		ll num = 0;
		for(re int j = i; j <= t; j++) {
			//求每个[l,r]块的答案 
			for(re int k = visL[j]; k <= visR[j]; k++) {
				sum[a[k]] ^= 1;
				if(sum[a[k]]) num += a[k];
				else num -= a[k];
			}
			val[i][j] = num;
		}
		//回退清空 
		for(re int j = i; j <= t; j++) {
			for(re int k = visL[j]; k <= visR[j]; k++) {
				sum[a[k]] = 0; 
			}
		}
	}
}
inline ll proc(int l, int r) {
	int idl = vis[l], idr = vis[r];
	if(idl == idr) {
		ll tot = 0;
		for(re int i = l; i <= r; i++) {
			sum[a[i]] ^= 1;
			if(sum[a[i]]) tot += a[i];
			else tot -= a[i];
		}
		for(re int i = l; i <= r; i++) sum[a[i]] = 0;
		return tot;
	}
	ll pt = val[idl + 1][idr - 1];
	for(re int i = l; i <= visR[idl]; i++) {
		if(!b[i]) {
			pt += a[i];
			continue;
		}
		sum[b[i]] ^= 1;
		if(sum[b[i]] ^ bs[idr - 1][b[i]] ^ bs[idl][b[i]]) pt += a[i];
		else pt -= a[i];
	}
	for(re int i = visL[idr]; i <= r; i++) {
		if(!b[i]) {
			pt += a[i];
			continue;
		}
		sum[b[i]] ^= 1;
		if(sum[b[i]] ^ bs[idr - 1][b[i]] ^ bs[idl][b[i]]) pt += a[i];
		else pt -= a[i];
	}
	//清空 
	for(re int i = l; i <= visR[idl]; i++) sum[b[i]] = 0;
	for(re int i = visL[idr]; i <= r; i++) sum[b[i]] = 0;
	return pt;
} 
inline void solve() {
	n = read(), m = read();
	for(re int i = 1; i <= n; i++) {
		a[i] = read();
	}
	pre();
	ll ans = 0; 
	for(re int i = 1; i <= m; i++) {
		ll x, y;
		cin >> x >> y;
		ll l = (((x - 1) + ans) % n) + 1;
		ll r = (((y - 1) + ans) % n) + 1;
		if(l > r) swap(l, r);
		ans = proc(l, r);
		print(ans);
		putchar(' ');
	}
	putchar('\n');
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}
/*

*/
