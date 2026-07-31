#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], b[N], ned[N], visa[N], visb[N], cnta, cntb, cntn;
std::pair<int, int> ans[N];
int ansa[N], ansb[N], ansc[N];
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void init() {
	for(int i = 0; i <= n + 1; i++) {
		a[i] = b[i] = ned[i] = 0;
		visa[i] = visb[i] = 0;
	}
	cnta = cntb = cntn = 0;
}
bool calc() {
	for(int i = 1; i <= cnta; i++) {
		visa[a[i]] = visb[b[i]] = true;
	}
	int nowa = 1, nowb = 1, nown = 1;
	for(int i = 1; i <= cntn; i++) {
		while(true) {
			if(!visa[a[nowa]]) nowa++;
			else break;
		}
		while(true) {
			if(!visb[b[nowb]]) nowb++;
			else break;
		}
		int t = ned[i] - b[nowb];
		if(t > 0 && visa[t]) {
			visa[t] = false;
			visb[b[nowb]] = false;
			ans[i] = {t, b[nowb]};
			continue;
		}
		t = ned[i] - a[nowa];
		if(t > 0 && visb[t]) {
			visa[a[nowa]] = false;
			visb[t] = false;
			ans[i] = {a[nowa], t};
			continue;
		}
		return false;
	}
	return true;
}
bool calc2() {
	for(int i = 1; i <= cnta; i++) {
		visa[a[i]] = visb[b[i]] = true;
	}
	int nowa = 1, nowb = 1, nown = 1;
	for(int i = 1; i <= cntn; i++) {
		while(true) {
			if(!visa[a[nowa]]) nowa++;
			else break;
		}
		while(true) {
			if(!visb[b[nowb]]) nowb++;
			else break;
		}
		int t = ned[i] - a[nowa];
		if(t > 0 && visb[t]) {
			visa[a[nowa]] = false;
			visb[t] = false;
			ans[i] = {a[nowa], t};
			continue;
		}
		t = ned[i] - b[nowb];
		if(t > 0 && visa[t]) {
			visa[t] = false;
			visb[b[nowb]] = false;
			ans[i] = {t, b[nowb]};
			continue;
		}
		return false;
	}
	return true;
}
void solve() {
	std::cin >> n;
	if(n & 1) {
		std::cout << "-1";
		return;
	}
	if(n == 2) {
		std::cout << "-1";
		return;
	}
	if(n == 4) {
		std::cout << "1 3 0 2\n\
0 1 2 3\n\
2 0 3 1";
		return;
	}
	if(n == 6) {
		std::cout << "2 5 1 4 0 3\n\
0 1 2 3 4 5\n\
3 0 4 1 5 2";
		return;
	}
	if(n == 8) {
		std::cout << "3 7 2 6 1 5 0 4\n\
0 6 3 4 7 2 1 5\n\
4 5 6 3 0 7 2 1";
		return;
	}
	for(int i = 3; i <= n / 2; i++) a[++cnta] = i;
	if((n / 2) & 1) {
		b[++cntb] = 1;
		for(int i = 3; i <= n / 2 - 1; i++) b[++cntb] = i;
	}
	else {
		b[++cntb] = 1;
		b[++cntb] = 2;
		for(int i = 4; i <= n / 2 - 2; i++) b[++cntb] = i;
		b[++cntb] = n / 2;
	}
	for(int i = 5; i <= n - 3; i += 2) ned[++cntn] = i;
	ned[++cntn] = n - 2;
	if(!calc()) calc2();
	
	
	int p = -1;
	for(int i = n - 1; i >= n / 2 + 1; i--) ansa[++p] = i;
	ansa[++p] = 2; 
	for(int i = 1; i <= cnta; i++) ansa[++p] = ans[i].first;
	ansa[++p] = 1; ansa[++p] = 0;
	
	p = -1; 
	if((n / 2) & 1) {
		ansb[++p] = 2;
		for(int i = n - 3; i >= n / 2; i--) ansb[++p] = i;
		ansb[++p] = 0; 
		for(int i = 1; i <= cnta; i++) ansb[++p] = ans[i].second;
		ansb[++p] = n - 1; ansb[++p] = n - 2;
	}
	else {
		ansb[++p] = 3;
		for(int i = n - 3; i >= n / 2 + 1; i--) ansb[++p] = i;
		ansb[++p] = n / 2 - 1;
		ansb[++p] = 0; 
		for(int i = 1; i <= cnta; i++) ansb[++p] = ans[i].second;
		ansb[++p] = n - 1; ansb[++p] = n - 2;
	}
	for(int i = n - 1; i >= 0; i--) {
		std::cout << ansa[i] << ' ';
	}
	std::cout << '\n';
	for(int i = n - 1; i >= 0; i--) {
		std::cout << ansb[i] << ' ';
	}
	std::cout << '\n';
	
	int tt = 0;
	for(int i = 0; i < n; i++) {
		ansc[i] = (ansa[i] + ansb[i] + tt) % n;
		tt = (ansa[i] + ansb[i] + tt) / n; 
	}
	
	for(int i = n - 1; i >= 0; i--) {
		std::cout << ansc[i] << ' ';
	}
}
signed main() {
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
