#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9, N = 600;
int n, k, ask1[N], ask2[N], cnt;
int fi[N], ne[N], to[N], num;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
struct Gauss_rk2 {
	pair<bitset<N>, int> eq[N]; 
	int rank = 0, vis[N], ans[N];
	
	Gauss_rk2() {//初始化，构造函数
        memset(vis, 0, sizeof(vis));
        memset(ans, 0, sizeof(ans));
    }
	bool add(pair<bitset<N>, int> now) {//判断&添加新的方程
		for(int i = 1; i <= n; i++) {//0-base
			if(!now.first[i]) continue;//方程中第i位不为 1 
			if(!vis[i]) {//最高为1的在第i列的方程 不存在 
				rank++;//秩++ 
				eq[i] = now;//添加到已存在方程中 
				vis[i] = true;//标记为true 
				return true;//成功添加一组线性无关的异或和方程 
			}
			else {
				now.first ^= eq[i].first;
				now.second ^= eq[i].second;
			}
		}
		return false;//能被构造出来，线性相关，返回false 
	}
	
	bool check() {//判断是否满足求解条件
		if(rank == n) return true;//已经满足求解条件，即秩=n
		return false; 
	}
	
	void solve() {//求解出答案
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(eq[i].first[j] == 1) {
					eq[i].first ^= eq[j].first;
					eq[i].second ^= eq[j].second;
				}
			}
			ans[i] = eq[i].second;
            //ans是global变量
		}
	}
};
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
pair<bitset<N>, int> now, askeq[N];
Gauss_rk2 s, sx;
void dfs(int u, int fa, int d, int S) {
	if(d == k) {
		if(s.check()) return;//已满，不用继续走了 
		if(s.add(now) == 0) return;//不满足条件 
		ask1[++cnt] = S;
		ask2[cnt] = u;
		askeq[cnt] = now;
		//S 到 u 
		return;
	}
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		now.first[v] = 1;
		dfs(v, u, d + 1, S);
		now.first[v] = 0;
	}
}
signed main() {
    n = read(), k = read();
    for(int i = 1; i < n; i++) {
    	int u = read(), v = read();
    	add(u, v);
    	add(v, u);
	}	
	
	now.first[1] = 1;
	s.add(now), sx.add(now);//初始化，根节点为0
	now.first.reset();
	
	for(int i = 1; i <= n; i++) {
		now.first[i] = 1;
		dfs(i, 0, 0, i);
		now.first.reset();
		if(s.check()) break;
	}
	if(!s.check()) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << '\n';
	cout << "? " << cnt << " ";
	for(int i = 1; i <= cnt; i++) {
		cout << ask1[i] << " " << ask2[i] << " ";
	}
	cout.flush();
	for(int i = 1; i <= cnt; i++) {
		askeq[i].second = read();
		sx.add(askeq[i]);
	}
	sx.solve();
	cout << "! ";
	for(int i = 2; i <= n; i++) {
		cout << sx.ans[i] << " ";
	}
    return 0;
}
/*

*/
