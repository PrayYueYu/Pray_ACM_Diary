#include <bits/stdc++.h>
using ld = long double;
// #define int long long
using namespace std;

int ans[402][402];
int d[402][802];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, Q;
    cin >> n >> m >> Q;
    memset(ans, 0x3f, sizeof(ans));
    vector<vector<pair<int, char>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    for (int i = 1; i <= n; i++) {
        memset(d, 0x3f, sizeof(d));
        queue<pair<int, int>> q;
        d[i][0] = 0;
        q.push({i, 0});
        while (!q.empty()) {
            auto [u, t] = q.front();
            q.pop();
            if (t == 0) ans[i][u] = min(ans[i][u], d[u][t]);
            for (auto [v, c] : g[u]) {
                int val = t + (c == '(' ? 1 : -1);
                if (val < 0) continue;
                if (d[v][val] > d[u][t] + 1) {
                    d[v][val] = d[u][t] + 1;
                    q.push({v, val});
                }
            }
        }
    }

    while (Q--) {
        int u, v;
        cin >> u >> v;
        if (ans[u][v] == 0x3f3f3f3f) {
            cout << -1 << '\n';
        } else {
            cout << ans[u][v] << '\n';
        }
    }


    return 0;
}
