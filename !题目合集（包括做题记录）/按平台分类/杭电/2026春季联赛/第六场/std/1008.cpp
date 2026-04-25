#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

struct DSU
{
    int fa[maxn], sz[maxn];

    int find(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    bool merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
            swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
    void init(int n)
    {
        for (int i = 0; i <= n; i++)
            sz[i] = 1, fa[i] = i;
    }
} dsu;

struct node
{
    int x, y, z;
} a[maxn];

void sol()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = {x, y, z};
    }
    dsu.init(n);
    for (int i = 1; i <= m; i++)
    {
        auto [x, y, z] = a[i];
        dsu.merge(x, y);
    }
    for (int i = 1, c = 0; i <= n; i++)
    {
        if (dsu.find(i) == i)
            c++;
        if (c >= 2)
        {
            cout << 0 << endl;
            return;
        }
    }
    dsu.init(n);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= m; i++)
    {
        auto [x, y, z] = a[i];
        if (z == 0) dsu.merge(x, y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dsu.find(i) == i)
            cnt1++;
    }

    dsu.init(n);
    for (int i = 1; i <= m; i++)
    {
        auto [x, y, z] = a[i];
        if (z == 1) dsu.merge(x, y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dsu.find(i) == i)
            cnt2++;
    }
    
    cout << (n - cnt1 + 1) - (cnt2 - 1) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        sol();
}
