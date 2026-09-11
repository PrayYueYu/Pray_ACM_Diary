#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, f[N];
struct BIT2D {
    int n;
    std::vector<std::vector<int>> ys, bit;

    BIT2D(int n = 0) : n(n), ys(n + 1), bit(n + 1) {}

    // 离线建树：xr, yr 是离散化后的坐标，范围 1..n 和 1..m
    void build(const std::vector<int>& xr, const std::vector<int>& yr) {
        int m = xr.size();
        for (int i = 0; i < m; ++i) {
            for (int x = xr[i]; x <= n; x += x & -x) {
                ys[x].push_back(yr[i]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            auto& v = ys[i];
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            bit[i].assign(v.size() + 1, -INF);
        }
    }

    // 在 (x, y) 位置插入值 val，维护最大值
    void add(int x, int y, int val) {
        for (int i = x; i <= n; i += i & -i) {
            int p = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin() + 1;
            for (int j = p; j < (int)bit[i].size(); j += j & -j) {
                bit[i][j] = std::max(bit[i][j], val);
            }
        }
    }

    // 查询 x' <= x 且 y' <= y 的最大值
    int ask(int x, int y) {
        int res = -INF;
        for (int i = x; i > 0; i -= i & -i) {
            int p = upper_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
            for (int j = p; j > 0; j -= j & -j) {
                res = std::max(res, bit[i][j]);
            }
        }
        return res;
    }
};
void solve() {
	
	std::cin >> n;
    std::vector<int> x(n), y(n), dp(n);
    std::vector<int> xs, ysAll;

    for (int i = 0; i < n; ++i) {
        int r, yx, b;
        std::cin >> r >> yx >> b;
        if(r && !i) f[0] = 1;
        if(i) {
        	x[i] = x[i - 1] + r - yx;
        	y[i] = y[i - 1] + r - b;
		}
		else {
			x[i] = r - yx;
			y[i] = r - b;
		}
        xs.push_back(x[i]);
        ysAll.push_back(y[i]);
    }
    // 离散化 x
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    // 离散化 y
    sort(ysAll.begin(), ysAll.end());
    ysAll.erase(unique(ysAll.begin(), ysAll.end()), ysAll.end());

    std::vector<int> xr(n), yr(n);
    for (int i = 0; i < n; ++i) {
        xr[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin() + 1;
        yr[i] = lower_bound(ysAll.begin(), ysAll.end(), y[i]) - ysAll.begin() + 1;
    }

    BIT2D bit(xs.size());
    bit.build(xr, yr);
	bit.add(xr[0], yr[0], f[0]);
	for(int i = 1; i < n; i++) {
		f[i] = std::max(f[i - 1], i + bit.ask(xr[i], yr[i]));
		if(x[i] >= 0 && y[i] >= 0) f[i] = i + 1;
		bit.add(xr[i], yr[i], f[i] - i);
	}
	std::cout << f[n - 1] << '\n';
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: 月雩薇嫭 | 
----------------------
*/
