#include <bits/stdc++.h>
using namespace std;

// 全局随机数生成器：使用 mt19937_64 和当前时间作为种子
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// 生成 [L, R] 范围内的随机 long long
long long RandLL(long long L, long long R) {
    return std::uniform_int_distribution<long long>(L, R)(rng);
}

// 写一组数据到 .in 文件，并创建空的 .out 文件
void write_case(int case_id, int n, int k, const vector<int>& special_pos) {
    string in_filename = "xsdsx" + to_string(case_id) + ".in";
    string out_filename = "xsdsx" + to_string(case_id) + ".out";

    ofstream fout(in_filename);
    if (!fout) {
        cerr << "无法打开文件 " << in_filename << endl;
        exit(1);
    }

    // 生成排列 a[1..n]
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    shuffle(a.begin(), a.end(), rng);

    // 确定标记位置
    vector<int> marked;
    if (!special_pos.empty()) {
        marked = special_pos;
        if ((int)marked.size() != k) {
            cerr << "错误：特殊位置数量与 k 不匹配" << endl;
            exit(1);
        }
    } else {
        // 随机选 k 个不同位置
        vector<int> all_pos(n);
        iota(all_pos.begin(), all_pos.end(), 1);
        shuffle(all_pos.begin(), all_pos.end(), rng);
        marked.assign(all_pos.begin(), all_pos.begin() + k);
    }

    // 写入 .in 文件
    fout << n << '\n';
    for (int i = 0; i < n; i++) {
        fout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
    fout << k << '\n';
    for (int i = 0; i < k; i++) {
        fout << marked[i];
        if(i != k - 1) fout << ' ';
    }
    fout.close();

    // 创建空的 .out 文件
    ofstream out_file(out_filename);
    out_file.close();
}

int main() {
    // 20 组数据的参数
    struct CaseInfo {
        int n;
        int k;
        vector<int> special_pos; // 若非空，则使用这些位置
    };

    vector<CaseInfo> cases(20);

    // 第 1 组：n=10，随机 k
    cases[0] = {10, 0, {}}; // k=0 表示随机

    // 第 2~4 组：小数据随机
    cases[1] = {50, 0, {}};
    cases[2] = {100, 0, {}};
    cases[3] = {500, 0, {}};

    // 第 5 组：n=1000, k=1, 标记第一个
    cases[4] = {1000, 1, {1}};

    // 第 6 组：n=1000, k=1, 标记最后一个
    cases[5] = {1000, 1, {1000}};

    // 第 7 组：n=1000, k=n, 标记所有位置
    vector<int> all_pos_1000(1000);
    iota(all_pos_1000.begin(), all_pos_1000.end(), 1);
    cases[6] = {1000, 1000, all_pos_1000};

    // 第 8 组：n=1000, k=2, 标记第一个和最后一个
    cases[7] = {1000, 2, {1, 1000}};

    // 第 9 组：n=1000, k=500, 标记前 500 个连续位置
    vector<int> first_500(500);
    iota(first_500.begin(), first_500.end(), 1);
    cases[8] = {1000, 500, first_500};

    // 第 10 组：n=1000, k=500, 标记后 500 个连续位置
    vector<int> last_500(500);
    iota(last_500.begin(), last_500.end(), 501);
    cases[9] = {1000, 500, last_500};

    // 第 11 组：n=1000, k=999, 随机
    cases[10] = {1000, 999, {}};

    // 第 12 组：n=1000, k=2, 随机
    cases[11] = {1000, 2, {}};

    // 第 13 组：n=1000, k=100, 随机
    cases[12] = {1000, 100, {}};

    // 第 14 组：n=1000, k=10, 随机
    cases[13] = {1000, 10, {}};

    // 第 15 组：n=1000, k=900, 随机
    cases[14] = {1000, 900, {}};

    // 第 16 组：n=1000, k=3, 标记连续中间位置 500,501,502
    cases[15] = {1000, 3, {500, 501, 502}};

    // 第 17 组：n=1000, k=1, 标记中间位置 500
    cases[16] = {1000, 1, {500}};

    // 第 18 组：n=1000, k=1000, 再次标记所有位置（排列不同）
    cases[17] = {1000, 1000, all_pos_1000};

    // 第 19 组：n=1000, k=1, 标记 999
    cases[18] = {1000, 1, {999}};

    // 第 20 组：n=1000, k 随机
    cases[19] = {1000, -1, {}}; // k=-1 表示随机生成

    for (int i = 0; i < 20; i++) {
        int n = cases[i].n;
        int k = cases[i].k;
        vector<int> special = cases[i].special_pos;

        if (k == -1) {
            // 第 20 组随机 k
            uniform_int_distribution<int> k_dist(1, n);
            k = k_dist(rng);
        }
        if (k == 0) {
            // 前几组未指定 k，随机生成
            uniform_int_distribution<int> k_dist(1, n);
            k = k_dist(rng);
        }

        write_case(i + 1, n, k, special);
    }

    return 0;
}
