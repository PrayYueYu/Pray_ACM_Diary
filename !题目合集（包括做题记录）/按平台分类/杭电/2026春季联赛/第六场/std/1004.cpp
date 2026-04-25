#include <bits/stdc++.h>
using namespace std;

static const long long SCALE = 10000000LL;

struct Point {
    long long x, y;
    Point() {}
    Point(long long _x, long long _y): x(_x), y(_y) {}
    Point operator + (const Point& other) const { return Point(x + other.x, y + other.y); }
    Point operator - (const Point& other) const { return Point(x - other.x, y - other.y); }
};

static inline __int128 cross2(const Point& a, const Point& b) {
    return (__int128)a.x * b.y - (__int128)a.y * b.x;
}

static inline __int128 cross3(const Point& a, const Point& b, const Point& c) {
    return cross2(b - a, c - a);
}

static inline __int128 dot2(const Point& a, const Point& b) {
    return (__int128)a.x * b.x + (__int128)a.y * b.y;
}

static inline int sgn128(__int128 x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

static inline bool above(const Point& a, const Point& b, const Point& c) {
    return cross3(a, b, c) > 0;
}

static inline bool below(const Point& a, const Point& b, const Point& c) {
    return cross3(a, b, c) < 0;
}

static inline long double dist(const Point& a, const Point& b) {
    long double dx = (long double)a.x - (long double)b.x;
    long double dy = (long double)a.y - (long double)b.y;
    return sqrtl(dx * dx + dy * dy) / (long double)SCALE;
}

long long parse_scaled(const string& s) {
    int sign = 1, pos = 0;
    if (s[pos] == '-') {
        sign = -1;
        ++pos;
    }

    long long ip = 0;
    while (pos < (int)s.size() && s[pos] != '.') {
        ip = ip * 10 + (s[pos] - '0');
        ++pos;
    }

    long long fp = 0;
    int cnt = 0;
    if (pos < (int)s.size() && s[pos] == '.') {
        ++pos;
        while (pos < (int)s.size() && cnt < 7) {
            fp = fp * 10 + (s[pos] - '0');
            ++pos;
            ++cnt;
        }
    }
    while (cnt < 7) {
        fp *= 10;
        ++cnt;
    }

    return sign * (ip * SCALE + fp);
}

// SoftSurfer 风格的 O(log N) 凸多边形切线查询，要求多边形为 CCW
int rtangent(const vector<Point>& v, const Point& p) {
    int n = (int)v.size();
    if (below(p, v[1], v[0]) && !above(p, v[n - 1], v[0])) return 0;

    int a = 0, b = n;
    while (true) {
        int c = (a + b) >> 1;
        int cc = c % n;

        bool dnC = below(p, v[(cc + 1) % n], v[cc]);
        if (dnC && !above(p, v[(cc - 1 + n) % n], v[cc])) return cc;

        bool upA = above(p, v[(a + 1) % n], v[a % n]);
        if (upA) {
            if (dnC) b = c;
            else if (above(p, v[a % n], v[cc])) b = c;
            else a = c;
        } else {
            if (!dnC) a = c;
            else if (below(p, v[a % n], v[cc])) b = c;
            else a = c;
        }
    }
}

int ltangent(const vector<Point>& v, const Point& p) {
    int n = (int)v.size();
    if (above(p, v[n - 1], v[0]) && !below(p, v[1], v[0])) return 0;

    int a = 0, b = n;
    while (true) {
        int c = (a + b) >> 1;
        int cc = c % n;

        bool dnC = below(p, v[(cc + 1) % n], v[cc]);
        if (above(p, v[(cc - 1 + n) % n], v[cc]) && !dnC) return cc;

        bool dnA = below(p, v[(a + 1) % n], v[a % n]);
        if (dnA) {
            if (!dnC) b = c;
            else if (below(p, v[a % n], v[cc])) b = c;
            else a = c;
        } else {
            if (dnC) a = c;
            else if (above(p, v[a % n], v[cc])) b = c;
            else a = c;
        }
    }
}

// 顶点 i 是否是点 p 的一个切点（允许退化：共线）
bool is_tangent_vertex(const vector<Point>& v, const Point& p, int i) {
    int n = (int)v.size();
    int s1 = sgn128(cross3(p, v[i], v[(i - 1 + n) % n]));
    int s2 = sgn128(cross3(p, v[i], v[(i + 1) % n]));
    return s1 == 0 || s2 == 0 || s1 == s2;
}

// 极少数退化情况下，一个外点的切点可能不止 2 个（例如落在某条边的延长线上）
// 把左右极值切点以及它们的邻点都拉出来，再用局部切线条件过滤即可
vector<int> tangent_candidates(const vector<Point>& v, const Point& p) {
    int n = (int)v.size();
    int l = ltangent(v, p), r = rtangent(v, p);

    vector<int> tmp;
    for (int x : {l, r}) {
        for (int d = -1; d <= 1; ++d) {
            int id = (x + d) % n;
            if (id < 0) id += n;
            tmp.push_back(id);
        }
    }

    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    vector<int> res;
    for (int id : tmp) {
        if (is_tangent_vertex(v, p, id)) res.push_back(id);
    }
    return res;
}

// 判断线段 p->q 是否穿过凸包内部
// 做法：先用 p 的左右切点确定“可见链”
// 若射线 p->q 严格落在两条切线之间，则它会与可见链恰好命中一次
// 在可见链上二分第一处 cross >= 0 的位置，再判断该命中是否发生在线段终点 q 之前
bool crosses_interior(const vector<Point>& v, const Point& p, const Point& q) {
    int n = (int)v.size();
    int l = ltangent(v, p), r = rtangent(v, p);

    int sL = sgn128(cross3(p, v[l], q));
    int sR = sgn128(cross3(p, v[r], q));

    // 在视锥外，或者正好在切线上，都不会进入内部
    if (sL > 0 || sR < 0) return false;
    if (sL == 0 || sR == 0) return false;

    // 可见链：l -> l+1 -> ... -> r（按下标循环）
    int m = (r - l + n) % n + 1;
    auto idx = [&](int k) { return (l + k) % n; };

    int lo = 0, hi = m - 1;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (cross3(p, v[idx(mid)], q) >= 0) hi = mid;
        else lo = mid + 1;
    }

    int k = lo;
    int j = idx(k);
    int i = idx(k - 1);

    int sj = sgn128(cross3(p, v[j], q));
    Point u = q - p;
    __int128 uu = dot2(u, u);

    // 恰好打到顶点
    if (sj == 0) {
        // 若与相邻可见边共线，则只是贴着边走，不进内部
        if (k > 0 && sgn128(cross3(p, v[i], q)) == 0) return false;
        if (k + 1 < m && sgn128(cross3(p, v[idx(k + 1)], q)) == 0) return false;

        __int128 num = dot2(v[j] - p, u); // = lambda * |u|^2
        return num < uu;                  // lambda < 1
    }

    // 命中边 (i, j)
    Point A = v[i], B = v[j];
    __int128 den = cross2(u, B - A);
    __int128 num = cross2(A - p, B - A); // lambda = num / den

    // 判断 lambda < 1，注意 den 可能为负
    if (den > 0) return num < den;
    else return num > den;
}

int main() {


//	freopen("data7.in","r",stdin);
//	freopen("data7.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    cout.setf(ios::fixed);
    cout << setprecision(10);

    while (TC--) {
        int n, q;
        cin >> n >> q;

        vector<Point> v(n);
        for (int i = 0; i < n; ++i) {
            string sx, sy;
            cin >> sx >> sy;
            v[i] = Point(parse_scaled(sx), parse_scaled(sy));
        }

        vector<long double> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + dist(v[i], v[(i + 1) % n]);
        }
        long double per = pre[n];

        auto ccw_dist = [&](int a, int b) -> long double {
            if (b >= a) return pre[b] - pre[a];
            return per - (pre[a] - pre[b]);
        };

        while (q--) {
            string sx, sy, tx, ty;
            cin >> sx >> sy >> tx >> ty;
            double D;
            cin>>D; 
            Point s(parse_scaled(sx), parse_scaled(sy));
            Point t(parse_scaled(tx), parse_scaled(ty));

            long double ans = 1e100L;

            // 直线可走
            if (!crosses_interior(v, s, t)) {
                ans = dist(s, t);
            }

            // 否则最短路一定是：切线 + 边界链 + 切线
            vector<int> cs = tangent_candidates(v, s);
            vector<int> ct = tangent_candidates(v, t);

            for (int i : cs) {
                for (int j : ct) {
                    long double arc = ccw_dist(i, j);
                    arc = min(arc, per - arc);
                    long double cur = dist(v[i], s) + arc + dist(v[j], t);
                    if (cur < ans) ans = cur;
                }
            }
            if(ans<D)printf("Yes\n");
            else printf("No\n");
//			printf("%.7Lf\n",ans); 
//            cout << (double)ans << '\n';
        }
    }
    return 0;
}
