#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int dotnum, L, R, MaxA, to[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
vector<pair<int, int>> pa[N];
void add(int u, int v, int w) {
	pa[u].push_back({v, w});
	//pa[v].push_back({u, w});
	dotnum = max(dotnum, max(u, v));
}
void addx(int u, int Len) {
	//从u点出发，向后Len个完全边 
	pa[u].push_back({-Len, -1});
	MaxA = max(MaxA, Len);
}
string rev(string s) {
	string sx = "";
	for(int i = s.size() - 1; i >= 0; i--) {
		sx += s[i];
	}
	return sx;
}
string getBin(int x) {//二进制位数 
	string bin = "";
	while(true) {
		bin += (char)(x % 2 + '0');
		x /= 2;
		if(!x) break;
	}
	return rev(bin);
}
string getstring(string s, int x) {
	string sx = "";
	for(int i = x; i < s.size(); i++) {
		sx += s[i];
	}
	return sx;
}
void Print() {

	cout << dotnum << '\n';
	for(int i = 1; i <= dotnum; i++) {
		cout << pa[i].size() << ' ';
	//	cout << i << " ";
		for(auto u: pa[i]) {
			cout << u.first << " " << u.second << ' ';
		}
		cout << '\n';
	}
}
void solve(string Lb, string Rb, int S, int T, int w1, int w2) {
	int Min = Lb.size();
	int Max = Rb.size();
	if(Max - 1 > Min) {
		MaxA = max(MaxA, Max - 2);
		//中间最大完全边长度 
	}
	if(w1 == w2) {
		if(Min == 1) {
			if(Lb[0] == '0') {
				add(w1, T, 0);
			}
			else add(w1, T, 1);
			add(w1, S, 1);
		}
		else add(w1, S, 1);
	}
	else {
		if(Min == 1) {
			if(Lb[0] == '0') {
				add(w1, T, 0);
			}
			else add(w1, T, 1);
		}
		else add(w1, S, 1);
		add(w2, S, 1);
	}
	//w号起始点，S占位，T号终点 
	int now = T, lasdot = S;
	for(int i = 1; i < Max; i++) {
		if(Rb[i] == '0') {
			if(i == Max - 1) {
				add(lasdot, T, 0);
				continue;
			}
			add(lasdot, ++now, 0);
			lasdot = now;
		}
		else {
			if(i == Max - 1) {
				add(lasdot, T, 1);
				add(lasdot, T, 0);
				continue;
			}
			add(lasdot, ++now, 0);
			add(lasdot, ++now, 1);
			addx(now - 1, Max - i - 1);
			lasdot = now;
		}
	}
	lasdot = S;
	for(int i = 1; i < Min; i++) {
		if(Lb[i] == '1') {
			if(i == Min - 1) {
				add(lasdot, T, 1);
				continue;
			}
			add(lasdot, ++now, 1);
			lasdot = now;
		}
		else {
			if(i == Min - 1) {
				add(lasdot, T, 1);
				add(lasdot, T, 0);
				continue;
			}
			add(lasdot, ++now, 1);
			add(lasdot, ++now, 0);
			addx(now - 1, Min - i - 1);
			lasdot = now;
		}
	}
	to[0] = T;
	lasdot = T;
	for(int i = 1; i <= MaxA - 1; i++) {
		add(++now, lasdot, 0);
		add(now, lasdot, 1);
		lasdot = now;
		to[i] = now;
	}
	for(int i = Min + 1; i <= Max - 1; i++) {
		addx(S, i - 1);
	}
	for(int i = 1; i <= dotnum; i++) {
		for(int j = 0; j < pa[i].size(); j++) {
			if(pa[i][j].first <= 0) {
				pa[i][j].first = -pa[i][j].first;
				pa[i][j].first--;
				int x = to[pa[i][j].first];
				pa[i][j] = {x, 0};
				add(i, x, 1);
			}
		}
	}
	Print();
}
void solve2(string Lb, string Rb, int Len) {
	if(Lb == Rb) {
		int now = 1, lasdot = 1;
		for(int i = 0; i < Len; i++) {
			add(lasdot, ++now, Rb[i] - '0');
			lasdot = now;
		}
		Print();
		return;
	}
	add(1, 2, 1);
	int T = 3;//3终点 
	int now = 3, lasdot = 2, f = true, id = Len;
	for(int i = 1; i < Len; i++) {
		if(Rb[i] == Lb[i] && f) {
			add(lasdot, ++now, Rb[i] - '0');
			lasdot = now;
		}
		else {
			if(i == Len - 1) {
				add(lasdot, T, 0);
				add(lasdot, T, 1);
				id = i + 1;
				break;
			}
			id = i + 1;
			break;
		}
	}
	int lasL = 0, lasR = 0;
	if(id <= Len - 1) {
		add(lasdot, ++now, 0);
		lasL = now;
		for(int i = id; i < Len; i++) {
			if(Lb[i] == '0') {
				if(i == Len - 1) {
					add(lasL, T, 0);
					add(lasL, T, 1);
					continue;
				}
				add(lasL, ++now, 1);
				add(lasL, ++now, 0);
				addx(now - 1, Len - i - 1);
				lasL = now;
			}
			else {
				if(i == Len - 1) {
					add(lasL, T, 1);
					continue;
				}
				add(lasL, ++now, 1);
				lasL = now;
			}
		}
		add(lasdot, ++now, 1);
		lasR = now;
		for(int i = id; i < Len; i++) {
			if(Rb[i] == '1') {
				if(i == Len - 1) {
					add(lasR, T, 0);
					add(lasR, T, 1);
					continue;
				}
				add(lasR, ++now, 0);
				add(lasR, ++now, 1);
				addx(now - 1, Len - i - 1);
				lasR = now;
			}
			else {
				if(i == Len - 1) {
					add(lasR, T, 0);
					continue;
				}
				add(lasR, ++now, 0);
				lasR = now;
			}		
		}
	}
	to[0] = T;
	lasdot = T;
	for(int i = 1; i <= MaxA - 1; i++) {
		add(++now, lasdot, 0);
		add(now, lasdot, 1);
		lasdot = now;
		to[i] = now;
	}
	for(int i = 1; i <= dotnum; i++) {
		for(int j = 0; j < pa[i].size(); j++) {
			if(pa[i][j].first <= 0) {
				pa[i][j].first = -pa[i][j].first;
				pa[i][j].first--;
				int x = to[pa[i][j].first];
				pa[i][j] = {x, 0};
				add(i, x, 1);
			}
		}
	}
	Print();
}
signed main() {
	L = read(), R = read();
	string Lb = getBin(L);
	string Rb = getBin(R);
	if(Lb.size() == Rb.size()) {
		solve2(Lb, Rb, Lb.size());
	}
	else {
		solve(Lb, Rb, 2, 3, 1, 1);
	}
	return 0;
}
