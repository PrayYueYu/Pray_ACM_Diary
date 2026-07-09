#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int n, m, num, b[N], ans[N], tr[N], cnt;

struct D { int x, y; } d[N];
struct S { int sx, sy, ex, ey, id; } s[N];
struct Q { int x, y, id, f; } q[N];

bool cmpd(D x, D y) {
    if(x.x == y.x) return x.y < y.y;
    return x.x < y.x;
}

bool cmpq(Q x, Q y) {
    if(x.x == y.x) return x.y < y.y;
    return x.x < y.x;
}

int lowbit(int x) { return x & -x; }

void add(int x) {
    while(x <= cnt) {
        tr[x]++;
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

int find(int x) {
    if(x <= 0) return 0;
    return upper_bound(b + 1, b + cnt + 1, x) - b - 1;
}

void solve() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> d[i].x >> d[i].y;
        d[i].y++;
        b[++num] = d[i].y;
    }
    sort(d + 1, d + n + 1, cmpd);
    
    for(int i = 1; i <= m; i++) {
        cin >> s[i].sx >> s[i].sy >> s[i].ex >> s[i].ey;
        s[i].sy++;
        s[i].ey++;
        b[++num] = s[i].ey;
        b[++num] = s[i].sy - 1;
    }
    sort(b + 1, b + num + 1);
    cnt = unique(b + 1, b + num + 1) - (b + 1);
    for(int i = 1; i <= n; i++) {
        d[i].y = find(d[i].y);
    }
    int cntx = 0;
    for(int i = 1; i <= m; i++) {
        s[i].id = i;
        q[++cntx] = {s[i].ex, find(s[i].ey), i, 1};
        q[++cntx] = {s[i].ex, find(s[i].sy - 1), i, -1};
        q[++cntx] = {s[i].sx - 1, find(s[i].ey), i, -1};
        q[++cntx] = {s[i].sx - 1, find(s[i].sy - 1), i, 1};
    }
    
    sort(q + 1, q + cntx + 1, cmpq);
    
    int now = 0;
    for(int i = 1; i <= cntx; i++) {
        while(now < n && d[now + 1].x <= q[i].x) {
            now++;
            add(d[now].y);
        }
        ans[q[i].id] += q[i].f * query(q[i].y);
    }
    
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}