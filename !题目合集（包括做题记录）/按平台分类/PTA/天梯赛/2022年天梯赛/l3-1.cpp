#include<bits/stdc++.h>
#define reg register
const int N = 2e5 + 10, mod = 998244353, INF = 1e9;
int n, ru[N], num, to[N], fi[N], ne[N];
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
std::vector<int> v[N], ans;
std::set<std::string> st;
std::string re[N];
struct cmp {
	bool operator()(const int& x, const int& y) {
		return re[x] > re[y];
	}
};
std::priority_queue<int, std::vector<int>, cmp> q;
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void solve() {
	n = read();
	for(reg int i = 1; i <= n; i++) {
		std::string s = "", nows = "";
		int now = 0;
		std::cin >> s;
		int sz = s.size();
		for(reg int j = 0; j < sz; j++) {
			if(s[j] == '.') {
				re[now] = nows;
				v[i].push_back(now);
				now = 0;
				nows = "";
			}
			else {
				now = now * 26 + s[j] - 'a' + 1;
				nows += s[j];
			}
		}
		re[now] = nows;
		v[i].push_back(now);
	}
	//把每一位都用数字表示
	//因为每一位最高只有三个小写字母，所以开20000就够了 
	for(reg int i = 1; i <= n; i++) {
		if(v[i].size() != v[i - 1].size()) continue;
		for(int j = 0; j < v[i].size(); j++) {
			if(v[i][j] != v[i - 1][j]) {
				add(v[i - 1][j], v[i][j]);
				ru[v[i][j]]++;
				//小的指向大的，建图 
				break;
			}
		}
	}
	for(reg int i = 0; i <= 20000; i++) {
		if(re[i] == "") continue;
		if(!ru[i]) {
			q.push(i);
		}
	}
	while(!q.empty()) {
//拓扑序计算，某一位只有前面的全部入答案序列之后才能开始计算
//同一时期在队列中的，按照字典序排列即可（见cmp）
		int u = q.top(); q.pop();
		ans.push_back(u);
		for(reg int i = fi[u]; i; i = ne[i]) {
			int v = to[i];
			ru[v]--;
			if(!ru[v]) q.push(v);
		}
	}
	for(reg int i = 0; i < ans.size(); i++) {
		std::cout << re[ans[i]];
		if(i != ans.size() - 1) std::cout << '.';
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
