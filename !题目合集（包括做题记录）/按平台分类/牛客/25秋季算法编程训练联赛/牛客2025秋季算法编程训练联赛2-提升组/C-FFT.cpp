#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 4e3 + 100, mod = 1e9 + 7, INF = 1e13;
const ll D = 1ll << 15;//pow(2,15)
ll f[N], wx[N], inv_w[N], g = 5;
ll n, m;
vector<vector<int>> fx;
const double pi = acos(-1.0);//计算 π的值 
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
ll ksm(ll x, ll y) {
	ll ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ans;
}
void init() {
	for(int i = 1; i <= 40; i++) {
		wx[i] = ksm(g, (mod - 1) / (1 << i));
		inv_w[i] = ksm(wx[i], mod - 2);
	}
}
void FFT(complex<long double> *a, int type, int Max) {//FFT模板
	for (int i = 0; i < Max; ++i) {
        if(i < f[i]) swap(a[i], a[f[i]]);
    }
    for(int mid = 1; mid < Max; mid <<= 1) {
    	complex<long double> W(cos(pi / mid), type * sin(pi / mid));
    	int len = mid << 1;
    	for(int j = 0; j < Max; j += len) { 
    		complex<long double> w(1, 0);
    		for(int k = 0; k < mid; k++, w = w * W) {
    			complex<long double> u = a[j + k];
    			complex<long double> v = w * a[j + k + mid];
    			a[j + k] = u + v;
    			a[j + k + mid] = u - v;
			}
		}
	}
}
complex<long double> Get(complex<long double> x, int Max) {
	long double xr = x.real(), xi = x.imag();
	xr = xr / Max + 0.5;
	xi = xi / Max + 0.5;
	//先用long double计算，以免掉精度 
	ll xrr = xr, xii = xi;
	xrr %= mod, xii %=mod;
	//+0.5之后能转换为整型，再取模 
	x.real(xrr); x.imag(xii);//重新赋值 
	return x;
}
vector<ll> Multi(vector<ll> a, vector<ll> b, int len) {
	complex<long double> A[N], B[N], T[N];
	for(int i = 0; i < a.size(); i++) {
		A[i].real((a[i] % D));
		B[i].real((a[i] / D));
        //初始化
	}
	for(int i = 0; i < b.size(); i++) {
		T[i].real((b[i] % D));
		T[i].imag((b[i] / D));
	}	
	int Max = 1;
	int cnt = 0;
	while(Max <= len) Max <<= 1, cnt++;
	a.resize(Max + 3); b.resize(Max + 3);
	for(int i = 0; i < Max; i++) 
		f[i] = (f[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
	
	FFT(A, 1, Max); FFT(B, 1, Max); FFT(T, 1, Max);
		for(int i = 0; i < Max; i++) {
		A[i] = A[i] * T[i];
		B[i] = B[i] * T[i];
	}
	FFT(A, -1, Max); FFT(B, -1, Max);//逆运算
	for(int i = 0; i < Max; i++) {
		A[i] = Get(A[i], Max);//归一化
		B[i] = Get(B[i], Max);
		ll ar = A[i].real(), ai = A[i].imag();
		ll br = B[i].real(), bi = B[i].imag();
		ll ans = (ai + br) * D; ans %= mod;
		ans = (ans + ar) % mod;
		ans = (ans + (bi * D * D)) % mod;//计算答案
		a[i] = ans;
	}
	return a;
}
pair<int, vector<ll>> Solve(int l, int r) {
	if(l == r) return {fx[l].size() - 1, fx[l]};//这里注意可能会改成别的值
	int mid = (l + r) >> 1;
	pair<int, vector<int>> ansl = Solve(l, mid);
	pair<int, vector<int>> ansr = Solve(mid + 1, r);
	int len = ansl.first + ansr.first;
	vector<int> ansx = Multi(ansl.second, ansr.second, len);
	ansx.resize(len + 1);
	return {len, ansx};
    //Multi的len一定不要忘了，否则可能会超时
}
signed main() {
	g = 3; init();
	n = read();
	fx.resize(n + 5);
	for(int i = 1; i <= n; i++) {
		int x = read();
		fx[i].push_back(((1 - x) % mod + mod) % mod);
		fx[i].push_back(x);
	}
	vector<int> ans = Solve(1, n).second;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	return 0;
}
//月雩·薇嫭 
