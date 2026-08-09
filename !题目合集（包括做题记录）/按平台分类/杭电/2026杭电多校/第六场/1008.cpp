#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, k, num[2][1005];
std::string s, t;
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
	for(int i = 'a'; i <= 'z'; i++) {
		num[0][i] = num[1][i] = 0;
	}
}
void solve() {
	std::cin >> n >> k;
	std::cin >> s >> t;
	s = " " + s; t = " " + t;
	for(int i = 1; i <= n; i++) {
		num[0][s[i]]++;
		num[1][t[i]]++;
	}
	for(int i = 'a'; i <= 'z'; i++) {
		if(num[0][i] != num[1][i]) {
			std::cout << "No\n";
			return;
		}
	}
	if(k > n - k) {
		for(int i = 2; i < n; i++) {
			if(s[i] != t[i]) {
				std::cout << "No\n";
				return;
			}
		}
		std::cout << "Yes\n";
		return;
	} else if (k == n - k) {
		for(int i = 2; i < k; i++) {
			if(s[i] != t[i]) {
				cout << "No\n";
				return;
			}
		}
		for(int i = k + 2; i < n; i++) {
			if(s[i] != t[i]) {
				cout << "No\n";
				return;
			}
		}
		string a;
		a += s[1];
		a += s[k];
		a += s[k + 1];
		a += s[n];
		string b;
		b += t[1];
		b += t[k];
		b += t[k + 1];
		b += t[n];
		queue<string> q;
		set<string> vis;
		q.push(a);
		vis.insert(a);
		while(!q.empty()) {
			auto now = q.front();
			q.pop();
			auto shit = now;
			swap(shit[0], shit[3]);
			if(!vis.count(shit)) {
				vis.insert(shit);
				q.push(shit);
			}
			shit = now;
			swap(shit[0], shit[1]);
			swap(shit[2], shit[3]);
			if(!vis.count(shit)) {
				vis.insert(shit);
				q.push(shit);
			}
		}
		if(vis.count(b))
			cout << "Yes\n";
		else
			cout << "No\n";
		return;
    }
	int l = k, r = n - k + 1;
	for(int i = 2; i < l; i++) {
		if(s[i] != t[i]) {
			std::cout << "No\n";
			return;
		}
	}
	for(int i = r + 1; i < n; i++) {
		if(s[i] != t[i]) {
			std::cout << "No\n";
			return;
		}
	}
	std::cout << "Yes\n";
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
