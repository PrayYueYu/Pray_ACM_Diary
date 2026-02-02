#include<bits/stdc++.h>
#define ll long long
#define int long long 
using namespace std;
const int N = 6e6 + 200, M = 998244353, INF = 2e18;
int n;
string s;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
struct Trie {
	int cnt, son[11], fail, len, ans;
} tr[N];
int getfail(int u, int t) {
	while(true) {
		if(t - tr[u].len - 1 >= 0 && s[t - tr[u].len - 1] == s[t]) {
			//找到符合条件的最长的 
			break;
		}
		u = tr[u].fail;//否则回溯 
	}
	return u;
}
int num = 1;
void build() {
	tr[0].fail = 1;
	tr[0].len = 0;
	tr[1].fail = 0;
	tr[1].len = -1;
	num = 1;//因为有两个根节点，所以从1开始 
	int cur = 0;
	for(int i = 0; i < s.size(); i++) {
		int v = s[i] - '0';
		int pos = getfail(cur, i);//找到以i结尾的最长回文位置
		//即最大的后缀回文 
		if(!tr[pos].son[v]) {
			//如果不存在，那么只能新建一个点
			tr[++num].fail = tr[getfail(tr[pos].fail, i)].son[v];
			tr[pos].son[v] = num;//这个必须放在后面！！ 
			//fail指向的是次大的后缀回文 
			tr[num].len = tr[pos].len + 2;//回文长度
			tr[num].cnt = tr[tr[num].fail].cnt + 1; 
		}
		cur = tr[pos].son[v];
		if(i >= n) tr[cur].ans++;
	}
	int sum = 0;
	for(int i = num; i >= 2; i--) {
		tr[tr[i].fail].ans += tr[i].ans;
		if(tr[i].len <= n) {
			int now = tr[i].ans * tr[i].ans;
			now %= M;
			now *= tr[i].len;
			now %= M;
			sum += now;
			sum %= M;
		}
	}
	cout << sum << endl;
}
signed main() {
	//freopen("1.in", "r", stdin);
	n = read();
	cin >> s;
	s = s + s;
	build();
    return 0;
}
