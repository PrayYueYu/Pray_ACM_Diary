#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 3e5 + 100, M = 998244353, INF = 1e16;	
int n, m, sum[N], f[N][3], h[N], s[N], lh[N], rh[N];
int lvis[N], rvis[N], lbl, rbl, lL[N], lR[N], rL[N], rR[N];
int mul[N], lne[N], rne[N], lto[N], rto[N], lcnt, rcnt;
map<int, int> mp;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void init() {
	for(int i = 0; i <= n + 5; i++) {
		f[i][0] = f[i][1] = 0;
		sum[i] = 0;
		lvis[i] = 0;
		rvis[i] = 0;
		lL[i] = lR[i] = 0;
		rL[i] = rR[i] = 0;
		mul[i] = 1;
		lne[i] = rne[i] = 0;
		lto[i] = rto[i] = 0;
	}
	mp.clear();
}
void update1(char op, int x, int y) {
	if(op == '+') {
		int id = lvis[x];
		for(int i = lL[id]; i <= lR[id]; i++) {
			sum[i] = (sum[i] * mul[id]) % M;
		}
		mul[id] = 1;
		sum[x] = (sum[x] + y) % M;
		return;
	}
	int ne = lne[x];
	int px = lto[ne];
	if(!lto[x]) px++;
	int id = lvis[px];
	if(px > lcnt || !ne) return;
	update1('+', px, 0);
	
	for(int i = px; i <= lR[id]; i++) {
		sum[i] *= 2;
		sum[i] %= M;
	}
	for(int i = id + 1; i <= lbl; i++) {
		mul[i] *= 2;
		mul[i] %= M;
	}
}
void update2(char op, int x, int y) {
	if(op == '+') {
		int id = rvis[x];
		for(int i = rL[id]; i <= rR[id]; i++) {
			sum[i] = (sum[i] * mul[id]) % M;
		}
		mul[id] = 1;
		sum[x] = (sum[x] + y) % M;
		return;
	}
	int ne = rne[x];
	int px = rto[ne];
	if(!rto[x]) px++;
	int id = rvis[px];
	if(px > rcnt || !ne) return;
	update2('+', px, 0);
	for(int i = px; i <= rR[id]; i++) {
		sum[i] *= 2;
		sum[i] %= M;
	}
	for(int i = id + 1; i <= rbl; i++) {
		mul[i] *= 2;
		mul[i] %= M;
	}
}
signed main(){
	//freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		n = read();
		//输入 
		for(int i = 1; i <= n; i++) {
			h[i] = read();
			s[i] = h[i];
		}
		//离散化 
		sort(s + 1, s + n + 1);
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(!mp[s[i]]) mp[s[i]] = ++cnt;
		}
		for(int i = 1; i <= n; i++) {
			h[i] = mp[h[i]];
		}
		//分别求从左看和右看 
		int Max = -INF; lcnt = 0;
		for(int i = 1; i <= n; i++) {
			if(Max < h[i]) {
				lh[++lcnt] = h[i];
				lto[h[i]] = lcnt;
				Max = h[i];
			}
		}
		rcnt = 0; Max = -INF;
		for(int i = n; i >= 1; i--) {
			if(Max < h[i]) {
				rh[++rcnt] = h[i];
				rto[h[i]] = rcnt;
				Max = h[i];
			}
		}
		//求>h[i]且在序列L和R中的最小的数分别是哪个 
		for(int i = 1; i < cnt; i++) {
			int l = 1, r = lcnt;
			while(l < r) {
				int mid = (l + r) >> 1;
				if(lh[mid] <= i) l = mid + 1;
				else r = mid;  
			}
			lne[i] = lh[l];
			l = 1, r = rcnt;
			while(l < r) {
				int mid = (l + r) >> 1;
				if(rh[mid] <= i) l = mid + 1;
				else r = mid;
			}
			rne[i] = rh[l];
		} 
		//L,R分块预处理 
		int L = 1, R = 0, Len = sqrt(lcnt);
		lbl = rbl = 0;
		while(true) {
			R = min(L + Len - 1, lcnt);
			lbl++;
			lL[lbl] = L;
			lR[lbl] = R;
			for(int i = L; i <= R; i++) {
				lvis[i] = lbl;
			}
			L = R + 1;
			if(R == lcnt) break;
		}
		L = 1, R = 0, Len = sqrt(rcnt);
		while(true) {
			R = min(L + Len - 1, rcnt);
			rbl++;
			rL[rbl] = L;
			rR[rbl] = R;
			for(int i = L; i <= R; i++) {
				rvis[i] = rbl;
			}
			L = R + 1;
			if(R == rcnt) break;
		}
		//分块求答案 
		for(int i = 1; i <= n; i++) {
			if(h[i] == lh[1]) f[i][0] = 1;
			if(h[i] == rh[1]) f[i][1] = 1;
		}
		for(int i = 1; i <= n; i++) {
			if(lto[h[i]] && lto[h[i]] != 1) {
				update1('+', lto[h[i]], 0);
				f[i][0] = sum[lto[h[i]]];
			}
			update1('*', h[i], 0);

			if(lto[h[i]])
				update1('+', lto[h[i]] + 1, f[i][0]);
		}
		
		for(int i = 0; i <= n + 1; i++) {
			sum[i] = 0;
			mul[i] = 1;
		}
		for(int i = n; i >= 1; i--) {
			if(rto[h[i]] && rto[h[i]] != 1)	{
				update2('+', rto[h[i]], 0);
				f[i][1] = sum[rto[h[i]]];
			}
			update2('*', h[i], 0);
			if(rto[h[i]])
				update2('+', rto[h[i]] + 1, f[i][1]);

		}
		//求f[i][1]对答案贡献的后缀和 
		for(int i = 1; i <= n + 1; i++) sum[i] = 0;
		for(int i = n; i >= 1; i--) {
			sum[i] = sum[i + 1] * 2ll;
			if(h[i] == Max) sum[i] += f[i][1];
			sum[i] %= M;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			if(h[i] != Max) continue;
			ans = (ans + f[i][0] * f[i][1] % M) % M;
		}
		for(int i = 1; i <= n; i++) {
			if(h[i] != Max) continue;
			ans = (ans + f[i][0] * sum[i + 1] % M) % M;
		}
		cout << ans << endl;
		
		init();
	}
	return 0;
}
/*


*/

