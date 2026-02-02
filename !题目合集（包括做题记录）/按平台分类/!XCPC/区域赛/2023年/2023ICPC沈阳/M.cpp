#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 200, M = 1e9 + 7, INF = 2e18;
int f[N], el[N], inv3, p[N], w[N], g[N], sum[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % M;
		x = (x * x) % M;
		y >>= 1;
	}
	return ans;
}
void init() {
	int NX = 1e6 + 5;
	for(int i = 1; i <= NX; i++) {
		if(i & 1) f[i] = f[i - 1] * 2 + 1;
		else f[i] = f[i - 1] * 2;
		f[i] %= M;
		
		el[i] = el[i - 1];
		if(!(i & 1)) el[i]++;
		
		p[i] = p[i - 1] * 4 + 1;
		p[i] %= M;
	}
	for(int i = 1; i <= NX; i++) {
		sum[i] = f[i];
		sum[i] += sum[i - 1];
		sum[i] %= M;
	}
	inv3 = ksm(3, M - 2);
}
int check(string s) {
	if(s == "01") return 2;
	if(s == "11") return 3;
	if(s == "10") return 4;
	return -1;
}
void solve() {
	string s, t;
	cin >> s >> t;
	int k, ans = 0, num = 0, F = false;
	cin >> k;
	int s1 = s.size(), s2 = t.size();
	while(true) {
		int t1 = 0, t2 = 0;
		if(!s1) t1 = 0;
		else {
			s1--;
			t1 = s[s1] - '0';
		}
		if(!s2) t2 = 0;
		else {
			s2--;
			t2 = t[s2] - '0';
		}
		num++;
		g[num] = 0;
		w[num] = t1 ^ t2;
		if(w[num]) F = true;
		if(!s1 && !s2) break;
	}
	for(int i = num; i >= 1; i--) {
		if(!w[i]) num--;
		else break;
	}
	if(!F) {
		k--;
		int ans = ksm(2, 2 * k);
		ans = (ans - 1 + M) % M;
		ans = (ans * 4) % M;
		ans = (ans * inv3) % M;
		cout << ans << '\n';
		return;
	}
	ans += sum[num - 1] + el[num - 1];
	ans %= M;
	if(num & 1) {
		int cnt = 0;
		for(int i = 1; i <= num - 1; i += 2) {
			string s = "";
			s += (w[i + 1] + '0');
			s += (w[i] + '0');
			if(check(s) == -1) {
				cnt++;
				if(cnt + 1 <= k) g[i] = 5;
				else g[i] = 1;
			}
			else g[i] = check(s);
		}
		if(cnt + 1 < k) {
			cout << -1 << '\n';
			return;
		}
	}
	else {
		if(w[num - 1] == 0) ans += f[num - 1];
		ans %= M;
		int cnt = 0;
		for(int i = 1; i <= num - 2; i += 2) {
			string s = "";
			s += (w[i + 1] + '0');
			s += (w[i] + '0');
			if(check(s) == -1){
				cnt++;
				if(cnt + 1 <= k) g[i] = 5;
				else g[i] = 1;
			}
			else g[i] = check(s);
		}
		if(cnt + 1 < k) {
			cout << -1 << '\n';
			return;
		}
	}
	F = true;
	int Fx = false;
	for(int i = num; i >= 1; i--) {
		if(g[i] == 5 && !Fx) Fx = true;
		if(Fx) {
			if(w[i] != 0) {
				F = false;
				break;
			}
		}
	}
	if(!F) {
		cout << -1 << '\n';
		return;
	}
	int cnt = 0;
	F = false;
	for(int i = 1; i <= num - 1; i++) {
		if(!g[i]) continue;
		cnt++;
		if(g[i] != 5) ans += (g[i] - 1) * p[cnt];
		else F = (g[i] - 1) * p[cnt];
		ans %= M;
	}
	ans += F;
	ans = (ans + 1) % M;
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	init();
	while(T--) {
		solve();
	}
    return 0;
}
/*

*/
