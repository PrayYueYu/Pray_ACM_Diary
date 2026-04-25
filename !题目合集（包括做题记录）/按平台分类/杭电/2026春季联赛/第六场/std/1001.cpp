#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll __int128_t
const int N = 1000 + 10;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

istream &operator>>(istream &it, __int128_t &j)
{
    string val;
    it >> val;
    reverse(val.begin(), val.end());
    __int128_t ans = 0;
    bool f = 0;
    char c = val.back();
    val.pop_back();
    for (; c < '0' || c > '9'; c = val.back(), val.pop_back())
    {
        if (c == '-')
            f = 1;
        if (val.empty())
            break;
    }
    for (; c >= '0' && c <= '9'; c = val.back(), val.pop_back())
    {
        ans = ans * 10 + c - '0';
        if (val.empty())
            break;
    }
    j = f ? -ans : ans;
    return it;
}

ostream &operator<<(ostream &os, const __int128_t &j)
{
    string ans;
    function<void(__int128_t)> write = [&](__int128_t x)
    {
        if (x < 0)
            ans += '-', x = -x;
        if (x > 9)
            write(x / 10);
        ans += x % 10 + '0';
    };
    write(j);
    return os << ans;
}

struct edge
{
    int to, ne, w;
} e[maxn << 1];
int head[maxn], ecnt = 1;

void add(int x, int y, int z)
{
    e[++ecnt].to = y;
    e[ecnt].ne = head[x];
    e[ecnt].w = z;
    head[x] = ecnt;
}

vector<int> res;

struct Center
{
    ll d1[maxn], d2[maxn], d[maxn], up[maxn], vis[maxn], x, y, mi;
    vector<int> v;

    void dfsd(int x, int fa) // ÇóÈ¡d1ºÍd2
    {
        v.push_back(x);
        vis[x] = 1;
        for (int i = head[x]; i; i = e[i].ne)
        {
            int y = e[i].to, w = e[i].w;
            if (y == fa) continue;
            dfsd(y, x);
            if (d1[y] + w > d1[x])
                d2[x] = d1[x], d1[x] = d1[y] + w;
            else if (d1[y] + w > d2[x])
                d2[x] = d1[y] + w;
        }
    }

    void dfsu(int x, int fa)
    {
        for (int i = head[x]; i; i = e[i].ne)
        {
            int y = e[i].to, w = e[i].w;
            if (y == fa)
                continue;
            up[y] = up[x] + w;
            if (d1[y] + w != d1[x])
                up[y] = max(up[y], d1[x] + w);
            else
                up[y] = max(up[y], d2[x] + w);
            dfsu(y, x);
        }
    }

    void solve(int rt)
    {
        x = y = 0, mi = INF;
        v.clear();
        dfsd(rt, 0);
        dfsu(rt, 0);
        for (auto i : v)
        {
            if (max(d1[i], up[i]) < mi)
            {
                mi = max(d1[i], up[i]);
                x = i,  y = 0;
            } else if (max(d1[i], up[i]) == mi)
                y = i;
        }
        res.push_back(x);
    }
} t;

void sol()
{
    ll n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i <= n; i++)
        t.d1[i] = t.d2[i] = t.up[i] = t.vis[i] = head[i] = 0;
    ecnt = 1; res.clear();
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z), add(y, x, z);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!t.vis[i])
            t.solve(i);
    }
    ll sum = 0, cnt = 0, mxd = 0;
    multiset<ll> st;
    for (auto x : res)
    {
        sum += max(t.d1[x], t.up[x]), cnt++;
        st.insert(max(t.d1[x], t.up[x]));
        t.d[x] = max(t.d1[x], t.up[x]);
        mxd = max(mxd, t.d1[x] + max(t.d2[x], t.up[x]));
    }

    auto check = [&](ll val)
    {
        if (val < mxd) return false;
        for (auto z : res)
        {
            st.extract(t.d[z]);
            auto it = st.end();
            it--; ll x = *it;
            ll Cnt = cnt - 1, Sum = sum - t.d[z];
            if (it == st.begin())
            {
                if (x + s + t.d[z] > val) {st.insert(t.d[z]); continue;}
                st.insert(t.d[z]);
                return true;
            }
            it--; ll y = *it;
            if (x >= val / 2)
            {
                ll det = val - x - 1;
                if (det <= y) {st.insert(t.d[z]); continue;}
                if (det * (Cnt - 1) - (Sum - x) + 1 < s)  {st.insert(t.d[z]); continue;}
                if (x + 1 + t.d[z] > val) {st.insert(t.d[z]); continue;}
            }
            else
            {
                ll det = val / 2, pt = val & 1;
                if (det + pt <= x || det <= y) { st.insert(t.d[z]); continue;}
                if (det * Cnt + pt - Sum < s) {st.insert(t.d[z]); continue;}
                ll f = s - ((x + 1) * Cnt - Sum), add = f / Cnt;
                if (f % Cnt != 0) add++;
                if (f < 0) add = 0;
                if (x + 1 + add + t.d[z] > val) {st.insert(t.d[z]); continue;}
            }
            st.insert(t.d[z]);
            return true;
        }
        return false;
    };

    ll l = 0, r = 1e15;
    while (l + 1 < r)
    {
        ll mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    if (check(l)) cout << l << endl;
    else cout << r << endl;
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
