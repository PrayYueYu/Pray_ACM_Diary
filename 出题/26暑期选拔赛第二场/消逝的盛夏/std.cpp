#include <bits/stdc++.h>
using namespace std;

struct Group {
    vector<int> basis;      // basis[bit] = 该位上的基向量，0 表示空
    vector<int> mask_basis; // 对应基向量的组合掩码
    vector<int> pos;        // 该组包含的位置编号
};

// 尝试将向量 v 插入组 g，返回是否成功
// 若成功，mask_out 保存新向量在组内的标记掩码
bool tryInsert(Group& g, int v, int& mask_out, int L) {
    int mask = 1 << g.pos.size(); // 新向量在组内的索引
    for (int bit = L - 1; bit >= 0; --bit) {
        if (!((v >> bit) & 1)) continue;
        if (g.basis[bit] == 0) {
            g.basis[bit] = v;
            g.mask_basis[bit] = mask;
            mask_out = mask;
            return true;
        } else {
            v ^= g.basis[bit];
            mask ^= g.mask_basis[bit];
        }
    }
    return false; // 线性相关，插入失败
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 计算二进制位数 L
    int L = 0;
    while ((1 << L) < n) ++L;
    if (L == 0) L = 1;

    vector<Group> groups;

    // 将每个位置分配到合适的组
    for (int i = 1; i <= n; ++i) {
        int v = a[i];
        bool inserted = false;

        // 尝试加入已有组
        for (auto& g : groups) {
            int mask;
            if (tryInsert(g, v, mask, L)) {
                g.pos.push_back(i);
                inserted = true;
                break;
            }
        }

        // 若所有组都放不下，新建一组
        if (!inserted) {
            Group ng;
            ng.basis.assign(L, 0);
            ng.mask_basis.assign(L, 0);
            int mask;
            tryInsert(ng, v, mask, L); // 新建组必定成功
            ng.pos.push_back(i);
            groups.push_back(ng);
        }
    }

    int ans = n + 1;

    // 对每组进行询问并解码
    for (auto& g : groups) {
        if (g.pos.empty()) continue;

        // 输出询问
        cout << "? " << g.pos.size();
        for (int p : g.pos) {
            cout << ' ' << p;
        }
        cout << endl;

        int y;
        cin >> y;

        // 解码得到该组内的标记掩码
        int mask = 0;
        for (int bit = L - 1; bit >= 0; --bit) {
            if ((y >> bit) & 1) {
                y ^= g.basis[bit];
                mask ^= g.mask_basis[bit];
            }
        }

        // 根据掩码更新答案
        for (int j = 0; j < (int)g.pos.size(); ++j) {
            if ((mask >> j) & 1) {
                ans = min(ans, g.pos[j]);
            }
        }
    }

    if (ans == n + 1) ans = -1; // 理论上题目保证有标记，这里仅为防御
    cout << "! " << ans << endl;

    return 0;
}
