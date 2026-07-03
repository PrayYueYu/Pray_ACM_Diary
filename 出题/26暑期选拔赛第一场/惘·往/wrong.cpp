#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1000000007;

vector<vector<int>> mul(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum = (sum + A[i][k] * B[k][j]) % MOD;
            }
            C[i][j] = sum;
        }
    }

    return C;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> now(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) now[i][i] = 1;

    for (int id = 1; id <= m; id++) {
        vector<vector<int>> A(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> A[i][j];
            }
        }

        now = mul(now, A);
    }

    bool ok = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x != now[i][j]) ok = false;
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
