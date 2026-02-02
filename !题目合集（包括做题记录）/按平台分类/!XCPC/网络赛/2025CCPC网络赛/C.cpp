#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 3e5 + 100, M = 1e9 + 7, INF = 1e16; 
int n, a[N], k, L[N], vis[N], fa[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
priority_queue<pair<int, pair<int, int>>> q;
void init() {
	while(!q.empty()) q.pop();
	for(int i = 0; i <= n + 10; i++) {
		vis[i] = false;
		L[i] = 0;
	}
}
bool check(int u, int v) { //必须合法 
	if(u < 1 || v < 1 || u > n || v > n) return true;
	return false;
}
//对坐标进行优化
//fa[v]代表[v,fa[v]-1]已经使用过 
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void merge(int u, int v) {
	int fau = getfa(u), fav = getfa(v);
	fa[fau] = fav; 
}
void update(int u, int v) {
	if(check(u, v)) return;
	v = getfa(v);//找到最近的未使用的 
	if(v > n) return;//若无，推出 
	q.push({-((a[u] + a[v]) % k), {u, v}});
	//加入优先队列 
	return;
}
signed main(){
	int T = read();
	while(T--) {
		n = read(), k = read();
		for(int i = 1; i <= n; i++) a[i] = read() % k;
		for(int i = 1; i <= n + 1; i++) fa[i] = i; 
		sort(a + 1, a + n + 1);
		//初始化 
		for(int i = 1; i <= n; i++) {
			int l = 1, r = n;
			while(l < r) {
				int mid = (l + r) >> 1;
				if(a[i] + a[mid] >= k) r = mid;
				else l = mid + 1;
			}
			if(a[l] + a[i] < k) L[i] = -1;
			else L[i] = l;
			//L[i]表示对于i来说，第一个满足a[i]+a[j]>=k的j是L[i]
			//L[i]=-1表示不存在 
		}
		//按照prim算法，就以a[1]为第一个点 
		update(1, L[1]);
		update(1, 2);
		//这两条边一定是最优边 
		vis[1] = true;
		fa[1] = 2;//1用过 
		int ans = 0;
		while(!q.empty()) {
			int u = q.top().second.first;
			int v = q.top().second.second;
			int w = q.top().first;
			q.pop();
			if(vis[v]) continue;//若发现v用过了，说明有重复，直接continue 
			ans -= w;//w是负数 
			vis[v] = true;//标记v已经在连通块内 
			merge(v, v + 1);//a[v]用过，所以merge，令fa[v]=v+1 
			update(u, mov(v));
			update(v, L[v]);
			//易得，这两条边是当前连通块可能的最优解 
			//所以update 
		}
		cout << ans << endl;
		init();
	}
	return 0;
}
//月雩·薇嫭 
/*
*/
