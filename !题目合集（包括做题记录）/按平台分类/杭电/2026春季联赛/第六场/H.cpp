#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define FU(i, a, b) for (int i = (a); i <= (b); ++i)
#define FD(i, a, b) for (int i = (a); i >= (b); --i)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5, MAXN = maxn;
int fa[maxn];
int n, m;

void init(int x) {
    for (int i = 0; i <= x; i++) {
        fa[i] = i;
    }
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int a, int b) {
    int fA = find(a), fB = find(b);
    if (fA != fB)
        fa[fA] = fB;
}

struct edge {
    int u, v, c;
};

bool cmp1(edge a, edge b) {
    return a.c < b.c;
}
bool cmp2(edge a, edge b) {
    return a.c > b.c;
}

void solve() {
    cin >> n >> m;
    vector<edge> ed;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        ed.pb({u, v, c});
    }
    sort(ed.begin(), ed.end(), cmp1);
    init(n);
    int ans1 = 0, cnt1 = 0;
    for (auto &[u, v, c] : ed) {
        if (find(u) == find(v))
            continue;
        merge(u, v);
        ans1 += c;
        cnt1++;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<fa[i]<<" ";
    // }cout<<endl;
    init(n);
    sort(ed.begin(), ed.end(), cmp2);
    int ans2 = 0;
    for (auto &[u, v, c] : ed) {
        if (find(u) == find(v))
            continue;
        merge(u, v);
        ans2 += c;
    }
    if (cnt1 != n - 1)
        cout << "0\n";
    else
        cout << ans2 - ans1 + 1 << endl;
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
