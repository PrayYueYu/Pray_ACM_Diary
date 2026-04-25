#include <bits/stdc++.h>
using ld = long double;
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> stk;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (stk.empty() || stk.back().first != x) {
            stk.push_back({x, 1});
        } else if (stk.back().second + 1 == k) {
            stk.pop_back();
        } else {
            stk.back().second++;
        }
    }
    vector<int> ans;
    for (auto [f, s] : stk) {
        for (int i = 0; i < s; i++) {
            ans.push_back(f);
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}
