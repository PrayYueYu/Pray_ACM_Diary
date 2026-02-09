#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int a[N], n, k, col;
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
bool check(int mid) {
	int re = k, t = mid, gt = 0, R = 0, L = 0; 
	int maxR = 0;
	//re:剩余几个初始
	//gt:已经染了几个
	//t:当前段剩余时间 
	//R:当前段最右边在哪 
	//L:当前段未搜寻部分最左端 
	//[L,R]:即将搜寻的区间 
	//maxR:当前已经搜寻的白色中，R最远的那一个在哪
	//每次初始化的时候就选择最远的那一个，这样才是最优解！ 
	for(int i = 1; i <= n; i++) {
		if(a[i]) {
			maxR = std::max(maxR, std::min(n, a[i] + i));
			re--;
			gt++;
			R = std::min(n, a[i] + i);
			L = i + 1;
			break;
		}
	}
	while(true) {
		if(gt == col) break;
		if(!t) {//当前段时间用完，重新找新的 
			int id = L; //需要从L处开始找
			//因为[L,R]没时间搜了 
			if(!re) break;
			while(true) {
				if(id == n + 1) break;
				if(a[id]) {
					maxR = std::max(maxR, std::min(n, a[id] + id));
					gt++;
					re--;
					t = mid;
					L = id + 1;
					R = maxR;//选择最远 
					break;
				}
				id++;
			}
			continue;
		}
		//时间没用完，找剩余未寻找段
		t--;
		int maxn = -1;
		for(int i = L; i <= R; i++) {
			if(a[i]) {
				maxR = std::max(maxR, std::min(n, a[i] + i));
				gt++;
				if(maxn < std::min(n, a[i] + i)) {
					maxn = std::min(n, a[i] + i);
				}
			}
		}
		if(maxn <= R) {//找不到更长的了或者区间内没有，自动搜寻下一个 
			if(!re) break;
			int id = R + 1;//[L,R]已搜寻，从R+1开始 
			while(true) {
				if(id == n + 1) break;
				if(a[id]) {
					maxR = std::max(maxR, std::min(n, a[id] + id));
					gt++;
					re--;
					t = mid;
					L = id + 1;
					R = maxR;//选择最远 
					break;
				}
				id++;
			}
			continue;
		}
		//找到下一个，更新
		L = R + 1;
		R = maxn;
	}
	if(gt >= col) return true;
	return false;
}
void solve() {
	n = read(), k = read();
	col = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(a[i]) col++;
	}
	int l = 0, r = 1e15;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(!check(l)) std::cout << "-1\n";
	else std::cout << l << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
