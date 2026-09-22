#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> dp(m + 1), dp2(m + 1);
        vector<ll> S(m + 1);

        // 读取第一行
        S[0] = 0;
        for (int j = 1; j <= m; ++j) {
            ll h;
            cin >> h;
            S[j] = S[j - 1] + h;
        }
        ll R = S[m];
        ll S_total = R;

        // 初始化 dp (用于 M) 和 dp2 (用于 N)
        for (int j = 0; j <= m; ++j) {
            dp[j] = S[j];
            dp2[j] = R - S[j];
        }

        // 读取剩余行
        for (int i = 2; i <= n; ++i) {
            S[0] = 0;
            for (int j = 1; j <= m; ++j) {
                ll h;
                cin >> h;
                S[j] = S[j - 1] + h;
            }
            R = S[m];
            S_total += R;

            // 更新 dp（左上闭区域最小和）
            vector<ll> min_dp(m + 1);
            min_dp[m] = dp[m];
            for (int j = m - 1; j >= 0; --j) {
                min_dp[j] = min(dp[j], min_dp[j + 1]);
            }
            for (int j = 0; j <= m; ++j) {
                dp[j] = S[j] + min_dp[j];
            }

            // 更新 dp2（右下闭区域最大和）
            vector<ll> max_dp2(m + 1);
            max_dp2[m] = dp2[m];
            for (int j = m - 1; j >= 0; --j) {
                max_dp2[j] = max(dp2[j], max_dp2[j + 1]);
            }
            for (int j = 0; j <= m; ++j) {
                dp2[j] = (R - S[j]) + max_dp2[j];
            }
        }

        // 计算 M 和 N
        ll min_sum = dp[0];
        for (int j = 1; j <= m; ++j) min_sum = min(min_sum, dp[j]);
        ll M = max(0LL, -min_sum);

        ll max_sum = dp2[0];
        for (int j = 1; j <= m; ++j) max_sum = max(max_sum, dp2[j]);
        ll N = max(0LL, max_sum);

        // 最小代价
        ll cost = S_total + 2 * max({M, N - S_total, 0LL});
        cout << cost << '\n';
    }
    return 0;
}
