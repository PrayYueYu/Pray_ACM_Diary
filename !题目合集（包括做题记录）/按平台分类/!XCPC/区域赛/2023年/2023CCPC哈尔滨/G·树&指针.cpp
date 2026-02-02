#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const ll N = 2e5 + 100, M1 = 1e9 + 7, INF = 1e16;	
int n, m, k;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct Line {
	int x1, x2, y;
} s[N];
bool cmp1(Line a, Line b) {
	if(a.y == b.y) {
		return a.x1 < b.x1;
	}
	return a.y < b.y;
}
vector<vector<Line>> v;
int calc(Line a, Line b) {
	if(a.x1 <= b.x1 && b.x2 <= a.x2) return b.x2 - b.x1 + 1;
	if(b.x1 <= a.x1 && a.x2 <= b.x2) return a.x2 - a.x1 + 1;
	if(b.x1 <= a.x1) return b.x2 - a.x1 + 1;
	return a.x2 - b.x1 + 1;
}
signed main(){
	//freopen("1.in", "r", stdin);
	n = read(), m = read(), k = read();
	int po = n * m, eg = n * (m - 1) + m * (n - 1);
	for(int i = 1; i <= k; i++) {
		s[i].x1 = read();
		s[i].x2 = read();
		s[i].y = read();
	}
	sort(s + 1, s + k + 1, cmp1);
	for(int i = 1; i <= k; i++) {
		eg -= 2;
		po -= (s[i].x2 - s[i].x1 + 1);
		if(s[i].x1 == 1) eg++;
		if(s[i].x2 == n) eg++;
		if(s[i].y == s[i - 1].y && s[i].x1 == s[i - 1].x2 + 1) eg++;
	}
	int num = 0, cnt = 0;
	v.resize(k + 2);
	for(int i = 1; i <= k; i++) {
		int Len = s[i].x2 - s[i].x1 + 1;
		eg -= Len * 2;
		eg -= (Len - 1);
		if(s[i].y == 1) eg += Len;
		if(s[i].y == m) eg += Len;
		
		if(s[i].y != s[i - 1].y) cnt++;
		v[cnt].push_back(s[i]);
	}
	for(int i = 2; i <= cnt; i++) {
		if(v[i][0].y != v[i - 1][0].y + 1) continue;
		int l = 0;
		int sum = 0;
		for(int j = 0; j < v[i].size(); j++) {
			while(true) {
				if(l >= v[i - 1].size()) break;
				if(v[i - 1][l].x1 > v[i][j].x2) break;
				if(v[i - 1][l].x2 < v[i][j].x1) {
					l++;
					continue;
				}
				sum += calc(v[i][j], v[i - 1][l]);
				l++;
			}
			if(l) l--;
		}
		eg += sum;
	}
	if(po == eg + 1) cout << "YES";
	else cout << "NO";
	return 0;
}
/*

*/
