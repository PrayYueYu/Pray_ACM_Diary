#include<bits/stdc++.h>
#define int __int128
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n;
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
void print(int x) {
	if(x < 0) {
		std::cout << '-';
		print(-x);
		return;
	}
	if(x <= 9 && x >= 0) {
		putchar((char)(x + '0'));
		return;
	}
	print(x / 10);
	putchar((char)(x % 10 + '0'));
}
std::vector<int> v;
void solve2() {
	if(!v.size()) {
		std::cout << "p1\nsub 0\np1\np1\nsub 1\nsub 1\nsub 2\nend";
		return;
	}
	std::cout << "p1\nadd 0\np1\n";
	long long now = 0, cnt = 2;
	for(int i = 0; i < v.size(); i++) {
		while(true) {
			if(now == v[i]) break;
			std::cout << "mul " << cnt - 1 << '\n';
			now++;
		}
		if(i != v.size() - 1) {
			std::cout << "dup\n";
			cnt++;
		}
	}
	for(long long i = 2; i < cnt; i++) {
		std::cout << "add " << cnt - i << '\n';
	}
	std::cout << "p1\np1\nsub 1\nsub 1\nsub 2\nend";
}
void solve() {
	n = read();
	
	if(!n) {
		std::cout << "p1\nsub 0\nend";
		return;
	}
	for(int i = 0; i <= 63; i++) {
		if((n >> i) & 1) {
			v.push_back(i);
		}
	}
	if(v.size() > 32) {
		v.clear();
		for(int i = 0; i <= 63; i++) {
			if(!((n >> i) & 1)) {
				v.push_back(i);
			}
		}
		solve2();
		return;
	}
	std::cout << "p1\nadd 0\np1\n";
	long long now = 0, cnt = 2;
	for(int i = 0; i < v.size(); i++) {
		while(true) {
			if(now == v[i]) break;
			std::cout << "mul " << cnt - 1 << '\n';
			now++;
		}
		if(i != v.size() - 1) {
			std::cout << "dup\n";
			cnt++;
		}
	}
	for(long long i = 2; i < cnt; i++) {
		std::cout << "add " << cnt - i << '\n';
	}
	std::cout << "end";
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
4294967295
13835058055282163712
*/
