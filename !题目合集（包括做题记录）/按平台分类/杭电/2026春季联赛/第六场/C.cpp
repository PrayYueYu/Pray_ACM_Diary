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
const int maxn = 5e5 + 5, MAXN = maxn;

void solve() {
    int s1, s2;
    cin >> s1 >> s2;
    if (s2 < 45) {
        cout << "0.0" << endl;
        return;
    }
    int S = ceil(0.6 * s1 + 0.4 * s2);
    if (S >= 95) {
        cout << "5.0" << endl;
    } else if (S < 60) {
        cout << "0.0" << endl;
    } else {
        double ans = 5.0 - 0.1 * (95 - S);
        cout << fixed << setprecision(1) << ans << endl;
    }
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
