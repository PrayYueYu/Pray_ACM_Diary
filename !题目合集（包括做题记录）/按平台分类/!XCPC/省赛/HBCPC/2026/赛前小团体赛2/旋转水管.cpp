#include <bits/stdc++.h>
#define int long long
#define y0 yx
using namespace std;
const int N = 1e5 + 100;
int vis[5][5][N], m, x0, y0, a[5][N];
string s1, s2;
void init() {
    for(int i = 0; i <= 4; i++) {
        for(int j = 0; j <= 4; j++) {
            for(int k = 0; k <= m + 2; k++) {
                vis[i][j][k] = false;
            }
        }
    }
}
void solve() {
    cin >> m >> x0 >> y0;
    cin >> s1 >> s2;
    for(int i = 0; i < m; i++) {
        if(s1[i] == 'I') a[2][i + 1] = 1;
        else a[2][i + 1] = 2;
    }
    for(int i = 0; i < m; i++) {
        if(s2[i] == 'I') a[3][i + 1] = 1;
        else a[3][i + 1] = 2;
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {2, x0}});

    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int op = q.front().first;q.pop();
        if(vis[op][x][y]) continue;
        vis[op][x][y] = true;
        if(x == 1 || x == 4 || !y || y > m) continue;
        
        if(a[x][y] == 1) {
                if(op == 1&&((x == 2 && y == x0)||(x == 3 && y == y0))) {
                    q.push({1, {x + 1, y}});
                }
                if(op == 2&&((x == 2 && y == x0)||(x == 3 && y == y0))) {
                    q.push({2, {x - 1, y}});
                }
                if(op == 3&&!((x == 2 && y == x0)||(x == 3 && y == y0))) {
                    q.push({3, {x, y + 1}});
                }
                if(op == 4&&!((x == 2 && y == x0)||(x == 3 && y == y0))) {
                    q.push({4, {x, y - 1}});
                }
        }
        else {
            if(op == 1 || op == 2) {
                q.push({3, {x, y + 1}});
                q.push({4, {x, y - 1}});
            }
            if(op == 3 || op == 4) {
                q.push({1, {x + 1, y}});
                q.push({2, {x - 1, y}});
            }
        }
    }
    if(vis[1][4][y0]) std::cout << "YES\n";
    else std::cout << "NO\n";
}
signed main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
        init();
    }
    return 0;
}