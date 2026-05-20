#include <bits/stdc++.h>
using namespace std;

const int MAXV = 100000;
vector<int> divs[MAXV + 1];

void init_divs() {
    for (int i = 1; i <= MAXV; ++i)
        for (int j = i; j <= MAXV; j += i)
            divs[j].push_back(i);
}

struct BIT {
    vector<int> bit;
    int n;
    BIT(int n) : n(n), bit(n + 2, 0) {}
    void update(int i, int val) {
        while (i <= n) {
            if (bit[i] >= val) break; // 剪枝
            bit[i] = val;
            i += i & -i;
        }
    }
    int query(int i) {
        int res = 0;
        while (i > 0) {
            if (bit[i] > res) res = bit[i];
            i -= i & -i;
        }
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // 每个 g 的倍数位置（自动有序）
    vector<vector<int>> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int g : divs[a[i]]) {
            if (g <= n) pos[g].push_back(i);
        }
    }

    // 桶装区间：intervals_at_L[L] = { (R, g) }
    vector<vector<pair<int,int>>> intervals_at_L(n + 2);
    for (int g = 1; g <= n; ++g) {
        auto &v = pos[g];
        for (size_t k = 1; k < v.size(); ++k) {
            int L = v[k-1], R = v[k];
            intervals_at_L[L].emplace_back(R, g);
        }
    }

    // 读入查询，按左端点装桶
    vector<vector<pair<int,int>>> queries_at_l(n + 2);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries_at_l[l].emplace_back(r, i);
    }

    vector<int> ans(q);
    BIT bit(n);

    // 从右往左扫描左端点
    for (int l = n; l >= 1; --l) {
        for (auto &pr : intervals_at_L[l]) {
            bit.update(pr.first, pr.second); // R, g
        }
        for (auto &pr : queries_at_l[l]) {
            ans[pr.second] = bit.query(pr.first); // r
        }
    }

    for (int x : ans) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init_divs();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
