#include<bits/stdc++.h>
#define int long long
const int N = 1e5 + 10, mod = 998244353, INF = 1e18;

int read() {
//	int x = 0, f = 1;
//	char ch = getchar();
//	while(ch < '0' || ch > '9') {
//		if(ch == '-') f = -1;
//		ch = getchar();
//	}
//	while(ch >= '0' && ch <= '9') {
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//	return x * f;
	int x;
	std::cin >> x;
	return x;
}
std::unordered_map<std::string, int> id, gen, vi;
std::string s2[N], s1[N];
int fa[N], n, vis[N];
bool check(std::string sn1, std::string sn2) {
	int x = vi[sn1], y = vi[sn2];
	while(true) {
		vis[x] = true;
		x = fa[x];
		if(!x) break;
	}
	int f = false;
	for(int j = 1; j <= 4; j++) {
		if(vis[y]) f = true;
		y = fa[y];
		if(!y) break;
	}
	x = vi[sn1];
	while(true) {
		vis[x] = false;
		x = fa[x];
		if(!x) break;
	}
	return f;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		std::string sx = "", s = "";
		std::cin >> s1[i] >> s2[i];
		char c = s2[i][s2[i].size() - 1];
		int d = 0;
		if(c == 'm') d = 1;
		else if(c == 'f') d = 1;
		else if(c == 'n') d = 4;
		else d = 7;
		for(int j = 0; j < s2[i].size() - d; j++) 
			sx += s2[i][j];
		s2[i] = sx;
		s = s1[i] + " " + s2[i];
		if(c == 'm' || c == 'n') gen[s] = 2;
		else gen[s] = 1;
		vi[s] = i;
		id[s1[i]] = i;
		if(c == 'm' || c == 'f') fa[i] = -1;
	}
	for(int i = 1; i <= n; i++) {
		if(fa[i] == -1) fa[i] = 0;
		else fa[i] = id[s2[i]];
	}
	int q = read();
	for(int i = 1; i <= q; i++) {
		std::string n1, n2, n3, n4, sn1, sn2;
		std::cin >> n1 >> n2 >> n3 >> n4;
		sn1 = n1 + " " + n2;
		sn2 = n3 + " " + n4;
		if(!vi[sn1] || !vi[sn2]) {
			std::cout << "NA\n";
			continue;
		}
		if(gen[sn1] == gen[sn2]) {
			std::cout << "Whatever\n";
			continue;
		}
		int f = true;
		if(check(sn1, sn2) || check(sn2, sn1)) f = false;
		if(f) std::cout << "Yes\n";
		else std::cout << "No\n";
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

*/
