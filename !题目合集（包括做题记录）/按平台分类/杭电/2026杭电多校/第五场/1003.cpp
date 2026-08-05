#include<bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const double PI = acos(-1.0);

struct Point {
    long long x, y, color;
};

// 叉积，返回 __int128 避免溢出
__int128 cross(const Point& a, const Point& b) {
    return (__int128)a.x * b.y - (__int128)a.y * b.x;
}

// 用于极角排序的比较器，按相对于 origin 的角度升序
struct AngleCmp {
    Point o;
    AngleCmp(Point _o) : o(_o) {}
    bool operator()(const Point& a, const Point& b) const {
        Point va = {a.x - o.x, a.y - o.y};
        Point vb = {b.x - o.x, b.y - o.y};
        __int128 cr = cross(va, vb);
        if (cr != 0) return cr > 0; // 逆时针角度更小
        // 共线时按距离排序（确保稳定性）
        long long da = (a.x - o.x) * (a.x - o.x) + (a.y - o.y) * (a.y - o.y);
        long long db = (b.x - o.x) * (b.x - o.x) + (b.y - o.y) * (b.y - o.y);
        return da < db;
    }
};

void solve() {
	int n;
    std::cin >> n;
    std::vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        std::cin >> pts[i].x >> pts[i].y >> pts[i].color;
    }

    // 按 (y, x) 升序，保证唯一最低点
    std::vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int a, int b) {
        if (pts[a].y != pts[b].y) return pts[a].y < pts[b].y;
        return pts[a].x < pts[b].x;
    });

    // 预计算：每个点 j 按极角排序的其他点，以及每个点的排名
    std::vector<std::vector<int>> order(n);
    std::vector<std::vector<int>> rank(n, std::vector<int>(n, -1));
    std::vector<std::vector<double>> angles(n);

    for (int j = 0; j < n; j++) {
        std::vector<std::pair<double, int>> tmp;
        for (int i = 0; i < n; i++) {
            if (i == j) continue;
            double ang = atan2((double)(pts[i].y - pts[j].y), (double)(pts[i].x - pts[j].x));
            if (ang < 0) ang += 2.0 * PI;
            tmp.push_back({ang, i});
        }
        std::sort(tmp.begin(), tmp.end());
        order[j].resize(n-1);
        angles[j].resize(n-1);
        for (int k = 0; k < n-1; k++) {
            order[j][k] = tmp[k].second;
            rank[j][tmp[k].second] = k;
            angles[j][k] = tmp[k].first;
        }
    }

    // 预计算每对 (j, k) 的区间端点 [L, R) (在复制后的角度数组中)
    std::vector<std::vector<int>> L(n, std::vector<int>(n, 0)), R(n, std::vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        int m = n - 1;
        if (m == 0) continue;
        std::vector<double> ang2(2 * m);
        for (int i = 0; i < m; i++) {
            ang2[i] = angles[j][i];
            ang2[i + m] = angles[j][i] + 2.0 * PI;
        }
        for (int k = 0; k < n; k++) {
            if (k == j) continue;
            double theta = atan2((double)(pts[k].y - pts[j].y), (double)(pts[k].x - pts[j].x));
            if (theta < 0) theta += 2.0 * PI;
            // 区间 (theta, theta + PI)
            int l = upper_bound(ang2.begin(), ang2.end(), theta) - ang2.begin();
            int r = lower_bound(ang2.begin(), ang2.end(), theta + PI) - ang2.begin();
            L[j][k] = l;
            R[j][k] = r;
        }
    }

    long long ans = 0;

    // 枚举最低点 s
    for (int sidx = 0; sidx < n; sidx++) {
        int s = ord[sidx];
        Point sp = pts[s];

        // 候选点：排在 s 后面的点（y更大，或 y相同但 x更大）
        std::vector<int> cand;
        for (int i = sidx + 1; i < n; i++) {
            int idx = ord[i];
            if (pts[idx].y > sp.y || (pts[idx].y == sp.y && pts[idx].x > sp.x)) {
                cand.push_back(idx);
            }
        }
        int m = cand.size();
        if (m < 2) continue;

        // 按相对于 s 的极角排序候选点
        sort(cand.begin(), cand.end(), [&](int a, int b) {
            Point va = {pts[a].x - sp.x, pts[a].y - sp.y};
            Point vb = {pts[b].x - sp.x, pts[b].y - sp.y};
            __int128 cr = cross(va, vb);
            if (cr != 0) return cr > 0;
            long long da = (pts[a].x - sp.x) * (pts[a].x - sp.x) + (pts[a].y - sp.y) * (pts[a].y - sp.y);
            long long db = (pts[b].x - sp.x) * (pts[b].x - sp.x) + (pts[b].y - sp.y) * (pts[b].y - sp.y);
            return da < db;
        });

        // dp[i][j] 表示以 s 开头，最后两个点是 cand[i], cand[j] 的链数
        std::vector<std::vector<long long>> dp(m, std::vector<long long>(m, 0));

        // 初始化：三角形 s, i, j
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                Point vi = {pts[cand[i]].x - sp.x, pts[cand[i]].y - sp.y};
                Point vj = {pts[cand[j]].x - pts[cand[i]].x, pts[cand[j]].y - pts[cand[i]].y};
                if (cross(vi, vj) > 0 && pts[s].color != pts[cand[i]].color && pts[cand[i]].color != pts[cand[j]].color) {
                    dp[i][j] = 1;
                }
            }
        }

        // DP 转移
        for (int j = 0; j < m; j++) {
            int cur = cand[j];
            // 构建 val 数组：按全局 rank 存储 dp[i][j]
            int total = n - 1; // 每个点的邻居数量
            std::vector<long long> val(total, 0);
            for (int i = 0; i < j; i++) {
                int pre = cand[i];
                int rk = rank[cur][pre]; // pre 相对于 cur 的排名
                val[rk] = (val[rk] + dp[i][j]) % MOD;
            }
            // 构建前缀和 (复制一份处理环形)
            std::vector<long long> pref(2 * total + 1, 0);
            for (int t = 0; t < total; t++) {
                pref[t + 1] = (pref[t] + val[t]) % MOD;
            }
            for (int t = 0; t < total; t++) {
                pref[t + total + 1] = (pref[t + total] + val[t]) % MOD;
            }

            for (int k = j + 1; k < m; k++) {
                int nxt = cand[k];
                if (pts[cur].color == pts[nxt].color) continue;
                int l = L[cur][nxt];
                int r = R[cur][nxt];
                long long sum = (pref[r] - pref[l] + MOD) % MOD;
                dp[j][k] = (dp[j][k] + sum) % MOD;
            }
        }

        // 累加所有以 s 为最低点的凸多边形
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
            	if (pts[cand[j]].color != pts[s].color) {
                	ans = (ans + dp[i][j]) % MOD;
            	}
            }
        }
    }

    std::cout << ans << "\n";
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
1
4
1 1 0
2 2 0
1 2 0
2 0 0
----------------------
	Writer: 月雩薇嫭 | 
----------------------
*/
