#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;

struct SegmentTree // 仅支持单点修改, 维护 max
{
    struct tree
    {
        int l, r, mx;
    } tr[4 * maxn];
    int a[maxn];
    int n;

#define lc (p << 1)
#define rc (p << 1 | 1)

    void calc(int p, ll k)
    {
        tr[p].mx = (tr[p].r - tr[p].l + 1) * k;
    }

    void pushup(int p)
    {
        tr[p].mx = max(tr[lc].mx, tr[rc].mx);
    }

    void build(int p, int l, int r)
    {
        tr[p].l = l, tr[p].r = r;
        tr[p].mx = 0;
        if (l == r)
        {
            tr[p].mx = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }

    void change(int p, int x, int y, ll k)
    {
        if (x <= tr[p].l && y >= tr[p].r)
        {
            calc(p, k);
            return;
        }
        int mid = tr[p].l + tr[p].r >> 1;
        if (x <= mid)
            change(lc, x, y, k);
        if (y > mid)
            change(rc, x, y, k);
        pushup(p);
    }

    int query(int p, int x, int y)
    {
        if (x <= tr[p].l && y >= tr[p].r)
            return tr[p].mx;
        int mid = tr[p].l + tr[p].r >> 1;
        int mx = 0;
        if (x <= mid)
            mx = max(mx, query(lc, x, y));
        if (y > mid)
            mx = max(mx, query(rc, x, y));
        return mx;
    }

    void debug(int p = 1)
    {
        // return;
        cout << "[" << tr[p].l << ", " << tr[p].r << "]: ";
        cout << endl;
        if (tr[p].l == tr[p].r)
            return;
        debug(lc), debug(rc);
    }

#undef lc
#undef rc
} t;

int a[maxn];
vector<int> g[maxn];

void sol()
{
    int n, m;
    cin >> n >> m;
    int mx = m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mx = max(mx, a[i]);
    // if (m > n)
    // {
    //     cout << -1 << endl;
    //     return;
    // }
    for (int i = 1; i <= mx; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++)
        g[a[i]].push_back(i);
    for (int i = 1; i <= mx; i++)
        reverse(g[i].begin(), g[i].end());
    for (int i = 1; i <= m; i++)
    {
        if (g[i].empty())
        {
            cout << -1 << endl;
            return;
        }
        t.a[i] = g[i].back();
    }
    t.build(1, 1, m);
    int ans = t.query(1, 1, m) - m;
    for (int i = 1; i <= n; i++)
    {
        g[a[i]].pop_back();
        if (a[i] <= m)
        {
            if (g[a[i]].empty())
                break;
            t.change(1, a[i], a[i], g[a[i]].back());
        }
        ans = min(ans, t.query(1, 1, m) - i - m);
    }
    cout << ans << endl;
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
