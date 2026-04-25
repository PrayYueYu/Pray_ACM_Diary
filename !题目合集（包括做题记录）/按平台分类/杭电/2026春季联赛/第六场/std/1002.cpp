#include <bits/stdc++.h>
using ld = long double;
#define int long long
using namespace std;

struct tz {
    int x, y;
    array<int, 6> co;
    tz() : x(0), y(0), co{} {}
};

int pw[8];
const int inf = 1e9 + 7;

// tz -> color
int encoder(const tz &t) {
    int r = 0;
    for (int i = 0; i < 6; i++) {
        r += pw[i] * t.co[i];
    }
    r += pw[6] * t.x;
    r += pw[7] * t.y;
    return r;
}

// color -> tz
// tz decoder(int r) {
//     tz t;
//     for (int i = 0; i < 6; i++) {
//         t.co[i] = r % 7;
//         r /= 7;
//     }
//     t.x = r % 300;
//     t.y = r / 300;
//     return t;
// }

// 0 顶 | 1 下 | 2 右 | 3 左 | 4 上 | 5 底
tz dir(const tz &t, int d) {
    tz res;
    if (d == 0) { // 上
        res.x = t.x - 1;
        res.y = t.y;
        res.co = {t.co[1], t.co[5], t.co[2], t.co[3], t.co[0], t.co[4]};
    } else if (d == 1) { // 下
        res.x = t.x + 1;
        res.y = t.y;
        res.co = {t.co[4], t.co[0], t.co[2], t.co[3], t.co[5], t.co[1]};
    } else if (d == 2) { // 左
        res.x = t.x;
        res.y = t.y - 1;
        res.co = {t.co[2], t.co[1], t.co[5], t.co[0], t.co[4], t.co[3]};
    } else if (d == 3) { // 右
        res.x = t.x;
        res.y = t.y + 1;
        res.co = {t.co[3], t.co[1], t.co[0], t.co[5], t.co[4], t.co[2]};
    } else {
        assert(false);
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    tz st;
    for (int i = 0; i < 6; i++) cin >> st.co[i];
    int enx, eny, ct;
    cin >> st.x >> st.y >> enx >> eny >> ct;
    unordered_map<int, int> dis;
    dis.reserve(n * m * 24 + 100);
    queue<tz> q;
    int ans = inf;
    dis[encoder(st)] = 0;
    q.push(st);
    while (!q.empty()) {
        tz u = q.front();
        q.pop();
        int D = dis[encoder(u)];
        if (u.x == enx && u.y == eny && u.co[5] == ct) {
            ans = D;
            break;
        }
        for (int i = 0; i < 4; i++) {
            tz v = dir(u, i);
            if (v.x < 1 || v.x > n || v.y < 1 || v.y > m) continue;
            int vc = encoder(v);
            if (dis.find(vc) != dis.end()) continue;
            dis[vc] = D + 1;
            q.push(v);
        }
    }
    if (ans == inf) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

signed main() {
    pw[0] = 1;
    for (int i = 1; i < 7; i++) pw[i] = pw[i - 1] * 7;
    pw[7] = pw[6] * 300;

    ios::sync_with_stdio(0), cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}
