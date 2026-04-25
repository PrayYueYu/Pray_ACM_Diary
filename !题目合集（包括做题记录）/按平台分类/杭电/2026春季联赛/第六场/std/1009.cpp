#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

struct LB // Linear Basis
{
    const int BASE = 63;
    vector<ll> d, p;
    int cnt, flag;
    LB() { d.resize(BASE + 1);  p.resize(BASE + 1); cnt = flag = 0; }
    bool insert(ll val)
    {
        for (int i = BASE - 1; i >= 0; i--)
        {
            if (val & (1ll << i))
            {
                if (!d[i])
                {
                    d[i] = val;
                    return true;
                }
                val ^= d[i];
            }
        }
        flag = 1; // 可以异或出0
        return false;
    }
    ll sol(ll ans)
    {
        for (int i = BASE - 1; i >= 0; i--)
            ans = min(ans, ans ^ d[i]);
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        LB l;
        int ans = 1 ^ n;
        for (int i = 1; i <= m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            l.insert({x ^ y ^ z});
        }
        cout << l.sol(ans) << endl;
    }
}
