#include<bits/stdc++.h>
using namespace std;
int vis[10], visx[10], p[10];
double px[10][10], sum, ans, a[10], b[10];
int read() {
	int x;
	scanf("%d", &x);
	return x;
}
double getp(int x, int y) {
	double p1, p2;
	if(x < y) p1 = a[p[x]], p2 = b[p[y]];
	else p1 = b[p[x]], p2 = a[p[y]];
	return p1 / (p1 + p2);
}
void calc(int t) {
	if(t == 5) {
		int tot = 0, f = false;
		double now = 1;
		int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
		for(int i = 1; i <= 8; i += 2) {
			tot++;
			if(visx[tot]) {
				if(!t1) t1 = i;
				else if(!t2) t2 = i;
				else if(!t3) t3 = i;
				else t4 = i;
				now = now * px[i][i + 1];
				if(p[i] == 1) f = true;
			}
			else {
				if(!t1) t1 = i + 1;
				else if(!t2) t2 = i + 1;
				else if(!t3) t3 = i + 1;
				else t4 = i + 1;
				now = now * px[i + 1][i];
				if(p[i + 1] == 1) f = true;
			}
		}
		if(!f) return;
		double s1, s2;
		if(p[t1] == 1) {
			s1 = px[t1][t2] * px[t3][t4] * px[t1][t3];
			s2 = px[t1][t2] * px[t4][t3] * px[t1][t4];
		}
		else if(p[t2] == 1) {
			s1 = px[t2][t1] * px[t3][t4] * px[t2][t3];
			s2 = px[t2][t1] * px[t4][t3] * px[t2][t4];
		}
		else if(p[t3] == 1) {
			s1 = px[t3][t4] * px[t1][t2] * px[t3][t1];
			s2 = px[t3][t4] * px[t2][t1] * px[t3][t2];
		}
		else {
			s1 = px[t4][t3] * px[t1][t2] * px[t4][t1];
			s2 = px[t4][t3] * px[t2][t1] * px[t4][t2];
		}
		now = now * (s1 + s2);
		sum += now;
		return;
	}
	visx[t] = 1;
	calc(t + 1);
	visx[t] = 0;
	calc(t + 1);
}
void dfs(int t) {
	if(t == 9) {
		sum = 0;
		for(int i = 1; i <= 8; i++) {
			for(int j = 1; j <= 8; j++) {
				px[i][j] = getp(i, j);
			}
		}
		calc(1);
		ans = max(ans, sum);
		return;
	}
	for(int i = 1; i <= 8; i++) {
		if(vis[i]) continue;
		vis[i] = true;
		p[t] = i;
		dfs(t + 1);
		vis[i] = false;
	}
}
signed main() {
	for(int i = 1; i <= 8; i++) {
		a[i] = read(), b[i] = read();
	}
	dfs(1);
	printf("%.10lf", ans);
	return 0;
}
