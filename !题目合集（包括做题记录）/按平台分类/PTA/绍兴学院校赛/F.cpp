#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define FU(i, a, b) for (int i = (a); i <= (b); ++i)
#define FD(i, a, b) for (int i = (a); i >= (b); --i)

const int maxn = 2e5 + 5;
int a[maxn];
vector<int> pos[maxn]; // pos[id] 记录离散化后数值 id 的所有下标

// 线段树节点
struct Node {
    int c[2];  // 最多存 2 个候选答案的离散化 ID
    int cnt;   // 当前节点包含的候选答案数量 (0, 1, 或 2)
} tree[maxn << 2];

// 获取数值 ID 在原数组区间 [l, r] 中的出现次数
int get_freq(int id, int l, int r) {
    auto it_r = upper_bound(pos[id].begin(), pos[id].end(), r);
    auto it_l = lower_bound(pos[id].begin(), pos[id].end(), l);
    return it_r - it_l;
}

// 向上合并节点
void pushup(int node, int l, int r) {
    int lc = node << 1;
    int rc = node << 1 | 1;
    
    // 收集左右孩子的候选答案
    int cands[4];
    int c_idx = 0;
    for (int i = 0; i < tree[lc].cnt; ++i) cands[c_idx++] = tree[lc].c[i];
    for (int i = 0; i < tree[rc].cnt; ++i) cands[c_idx++] = tree[rc].c[i];
    
    // 去重
    sort(cands, cands + c_idx);
    int unique_cnt = unique(cands, cands + c_idx) - cands;
    
    int threshold = (r - l + 1) / 3;
    tree[node].cnt = 0;
    
    // 验证哪些候选答案在当前父区间合法
    for (int i = 0; i < unique_cnt; ++i) {
        int id = cands[i];
        if (get_freq(id, l, r) > threshold) {
            tree[node].c[tree[node].cnt++] = id;
        }
    }
}

// 建树
void build(int node, int l, int r) {
    if (l == r) {
        tree[node].c[0] = a[l];
        tree[node].cnt = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    pushup(node, l, r);
}

// 区间查询：收集所有覆盖到的线段树节点的候选答案
void query(int node, int l, int r, int L, int R, vector<int>& cands) {
    if (L <= l && r <= R) {
        for (int i = 0; i < tree[node].cnt; ++i) {
            cands.pb(tree[node].c[i]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) query(node << 1, l, mid, L, R, cands);
    if (R > mid) query(node << 1 | 1, mid + 1, r, L, R, cands);
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> sorted_a;
    FU(i, 1, n) {
        cin >> a[i];
        sorted_a.pb(a[i]);
    }
    
    // 离散化
    sort(sorted_a.begin(), sorted_a.end());
    sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());
    int distinct_count = sorted_a.size();
    
    // 清空上一组数据的 pos (多测必备)
    FU(i, 1, distinct_count) pos[i].clear();
    
    FU(i, 1, n) {
        a[i] = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin() + 1;
        pos[a[i]].pb(i);
    }
    
    build(1, 1, n);
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        vector<int> cands;
        query(1, 1, n, l, r, cands);
        
        // 候选答案去重
        sort(cands.begin(), cands.end());
        cands.erase(unique(cands.begin(), cands.end()), cands.end());
        
        vector<int> valid_answers;
        int threshold = (r - l + 1) / 3;
        
        // 对收集到的候选答案做最终验证
        for (int id : cands) {
            if (get_freq(id, l, r) > threshold) {
                valid_answers.pb(sorted_a[id - 1]); // 还原为真实数值
            }
        }
        
        // 排序输出
        if (valid_answers.empty()) {
            cout << -1 << endl;
        } else {
            sort(valid_answers.begin(), valid_answers.end());
            for (int i = 0; i < valid_answers.size(); ++i) {
                cout << valid_answers[i] << (i == valid_answers.size() - 1 ? "" : " ");
            }
            cout << endl;
        }
    }
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
