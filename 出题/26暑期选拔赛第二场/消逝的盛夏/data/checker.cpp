#include <bits/stdc++.h>
using namespace std;

// 检查单个数据文件是否合法
bool check_file(int case_id) {
    string filename = "xsdsx" + to_string(case_id) + ".in";
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "无法打开文件: " << filename << endl;
        return false;
    }

    auto trim_r = [](string &s) {
        while (!s.empty() && (s.back() == '\r')) s.pop_back();
    };

    auto check_line_end = [&](const string &s, const string &filename, int line_no) {
        if (!s.empty() && (s.back() == ' ' || s.back() == '\t')) {
            cerr << filename << " 第 " << line_no << " 行行末有多余空格" << endl;
            return false;
        }
        return true;
    };

    string line;
    int n, k;

    // 第一行：n
    if (!getline(fin, line)) {
        cerr << filename << " 缺少第一行 n" << endl;
        return false;
    }
    trim_r(line);
    if (!check_line_end(line, filename, 1)) return false;
    stringstream ss1(line);
    if (!(ss1 >> n)) {
        cerr << filename << " 第一行 n 不是整数" << endl;
        return false;
    }
    int extra;
    if (ss1 >> extra) {
        cerr << filename << " 第一行有多余内容" << endl;
        return false;
    }
    if (n < 1 || n > 1000) {
        cerr << filename << " n 超出范围 [1,1000]，实际为 " << n << endl;
        return false;
    }

    // 第二行：n 个数字，是 1~n 的排列
    if (!getline(fin, line)) {
        cerr << filename << " 缺少第二行排列" << endl;
        return false;
    }
    trim_r(line);
    if (!check_line_end(line, filename, 2)) return false;
    stringstream ss2(line);
    vector<bool> used_a(n + 1, false);
    int a;
    for (int i = 0; i < n; i++) {
        if (!(ss2 >> a)) {
            cerr << filename << " 第二行数字个数不足 " << n << endl;
            return false;
        }
        if (a < 1 || a > n) {
            cerr << filename << " 第二行数字 " << a << " 超出范围 [1," << n << "]" << endl;
            return false;
        }
        if (used_a[a]) {
            cerr << filename << " 第二行数字 " << a << " 出现重复，不是排列" << endl;
            return false;
        }
        used_a[a] = true;
    }
    if (ss2 >> extra) {
        cerr << filename << " 第二行数字个数超过 " << n << endl;
        return false;
    }

    // 第三行：k
    if (!getline(fin, line)) {
        cerr << filename << " 缺少第三行 k" << endl;
        return false;
    }
    trim_r(line);
    if (!check_line_end(line, filename, 3)) return false;
    stringstream ss3(line);
    if (!(ss3 >> k)) {
        cerr << filename << " 第三行 k 不是整数" << endl;
        return false;
    }
    if (ss3 >> extra) {
        cerr << filename << " 第三行有多余内容" << endl;
        return false;
    }
    if (k < 1 || k > n) {
        cerr << filename << " k 超出范围 [1,n]，实际为 " << k << endl;
        return false;
    }

    // 第四行：k 个互不相同的标记位置
    if (!getline(fin, line)) {
        cerr << filename << " 缺少第四行标记位置" << endl;
        return false;
    }
    trim_r(line);
    if (!check_line_end(line, filename, 4)) return false;
    stringstream ss4(line);
    vector<bool> used_pos(n + 1, false);
    int p;
    for (int i = 0; i < k; i++) {
        if (!(ss4 >> p)) {
            cerr << filename << " 第四行数字个数不足 " << k << endl;
            return false;
        }
        if (p < 1 || p > n) {
            cerr << filename << " 第四行位置 " << p << " 超出范围 [1," << n << "]" << endl;
            return false;
        }
        if (used_pos[p]) {
            cerr << filename << " 第四行位置 " << p << " 出现重复" << endl;
            return false;
        }
        used_pos[p] = true;
    }
    if (ss4 >> extra) {
        cerr << filename << " 第四行数字个数超过 " << k << endl;
        return false;
    }

    // 检查文件是否还有多余内容
    char ch;
    if (fin >> ch) {
        cerr << filename << " 存在多余内容" << endl;
        return false;
    }

    return true;
}

int main(int argc, char *argv[]) {
    int N = 20;
    if (argc >= 2) {
        N = atoi(argv[1]);
        if (N <= 0) {
            cerr << "组数必须为正整数" << endl;
            return 1;
        }
    }

    bool all_ok = true;
    for (int i = 1; i <= N; i++) {
        if (check_file(i)) {
            cout << "Data " << i << ": OK" << endl;
        } else {
            all_ok = false;
            cout << "Data " << i << ": FAILED" << endl;
        }
    }

    if (all_ok) {
        cout << "All files passed." << endl;
        return 0;
    } else {
        cout << "Some files failed." << endl;
        return 1;
    }
}
