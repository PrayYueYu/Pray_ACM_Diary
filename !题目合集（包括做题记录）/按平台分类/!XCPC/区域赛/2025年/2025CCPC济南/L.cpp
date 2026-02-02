#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, p[N], tr[N], a[N], fa[N], son[N][3], maxn[N];
int read() {
    int x;
    cin >> x;
    return x;
}
int lowbit(int x) {
    return x & (-x);
}
void add(int x, int y) {
    while(x <= n - 1) {
        tr[x] += y;
        x += lowbit(x);
    }
}
int query(int x) {
    int sum = 0;
    while(x) {
        sum += tr[x];
        x -= lowbit(x);
    }
    return sum;
}
void update(int u) {
    int now = u;
    while(true) {
        if(fa[now] == 0) break;
        now = fa[now]; 
        a[now] = min(a[son[now][1]], a[son[now][2]]);
        add(p[now], -maxn[now]);
        maxn[now] = max(a[son[now][1]], a[son[now][2]]);
        add(p[now], maxn[now]);
    }
}
void init() {
    queue<int> q;
    for(int i = 1; i <=n; i++) {
        q.push(i);
    }
    int tot = n, now = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(q.empty()) break;
        int y = q.front();
        q.pop();
        fa[x] = fa[y] = ++tot;
        son[tot][1] = x; son[tot][2] = y;
        p[tot] = ++now;
        q.push(tot);
    }
    for(int i = 1; i <= n; i++) update(i);
}
signed main() {
    n = read(), m = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    init();
    for(int i = 1; i <= m; i++) {
        char c;
        cin >> c;
        if(c == 'A') {
            int l = read(), r = read();
            cout << query(r) - query(l - 1) << '\n';
        }
        else {
            int x = read(), y = read();
            swap(a[x], a[y]);
            update(x);
            update(y);
        }
    }
    return 0;
}
/*

*/
