#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int id, m, k, n;
    cin >> id >> m >> k >> n;

    string ans;

    for (int s = 0; s < m; ++s) {
        bool bad = false;

        for (int t = 0; t < k; ++t) {
            int N = n * n;
            vector<int> a(N);

            for (int i = 0; i < N; ++i) {
                cin >> a[i];
            }

            // 计算逆序数奇偶性
            int parity = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    if (a[i] > a[j]) parity ^= 1;
                }
            }

            // 出现奇排列，说明这套一定被 Bob 弄坏过
            if (parity) bad = true;
        }

        ans.push_back(bad ? '1' : '0');
    }

    cout << ans;
    return 0;
}
