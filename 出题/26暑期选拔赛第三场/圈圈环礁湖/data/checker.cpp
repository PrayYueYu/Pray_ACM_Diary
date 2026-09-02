#include <bits/stdc++.h>
using namespace std;

// 检查一组文件
bool checkOne(const string& inFile, const string& outFile, bool verbose = true) {
    ifstream fin(inFile);
    if (!fin) {
        cerr << "? 无法打开 " << inFile << endl;
        return false;
    }
    ifstream fout(outFile);
    if (!fout) {
        cerr << "? 无法打开 " << outFile << endl;
        return false;
    }

    int id, m, k, n;
    fin >> id >> m >> k >> n;
    const int EXPECT_M = 100, EXPECT_K = 10, EXPECT_N = 10;
    if (m != EXPECT_M || k != EXPECT_K || n != EXPECT_N) {
        cerr << "? " << inFile << " 头部错误: m=" << m << ", k=" << k << ", n=" << n
             << " (期望 " << EXPECT_M << ' ' << EXPECT_K << ' ' << EXPECT_N << ")\n";
        return false;
    }

    string ans;
    fout >> ans;
    if ((int)ans.size() != m) {
        cerr << "? " << outFile << " 答案长度 " << ans.size() << " != m=" << m << "\n";
        return false;
    }
    for (char c : ans) {
        if (c != '0' && c != '1') {
            cerr << "? " << outFile << " 包含非法字符 '" << c << "'\n";
            return false;
        }
    }

    int totalSize = n * n;
    bool ok = true;

    for (int setIdx = 0; setIdx < m && ok; ++setIdx) {
        vector<int> parity(k, -1);

        for (int toyIdx = 0; toyIdx < k; ++toyIdx) {
            vector<int> mat(totalSize);
            for (int i = 0; i < totalSize; ++i) {
                fin >> mat[i];
            }

            // 检查排列
            vector<bool> seen(totalSize + 1, false);
            bool perm = true;
            for (int v : mat) {
                if (v < 1 || v > totalSize || seen[v]) {
                    perm = false;
                    break;
                }
                seen[v] = true;
            }
            if (!perm) {
                cerr << "? " << inFile << " 第 " << setIdx << " 套，玩具 " << toyIdx
                     << " 不是 1.." << totalSize << " 的排列\n";
                return false;
            }

            // 逆序数奇偶
            int inv = 0;
            for (int i = 0; i < totalSize; ++i) {
                for (int j = i + 1; j < totalSize; ++j) {
                    if (mat[i] > mat[j]) inv ^= 1;
                }
            }
            parity[toyIdx] = inv;
        }

        // 如果答案标记为 0，则所有玩具必须为偶排列
        if (ans[setIdx] == '0') {
            for (int p : parity) {
                if (p != 0) {
                    cerr << "? " << inFile << " 第 " << setIdx << " 套标记为 0（好套），但存在奇排列玩具\n";
                    return false;
                }
            }
        }
    }

    if (verbose) cout << " " << inFile << " 检查通过" << endl;
    return true;
}

int main() {
    int total = 10;
    int passed = 0;
    bool allOk = true;

    for (int i = 1; i <= total; ++i) {
        string inFile = "qqhjh" + to_string(i) + ".in";
        string outFile = "qqhjh" + to_string(i) + ".out";
        if (checkOne(inFile, outFile, true)) {
            ++passed;
        } else {
            allOk = false;
            // 不退出，继续检查后续，方便看到所有错误
        }
    }

    cout << "\n========================================\n";
    cout << "检查完成: " << passed << "/" << total << " 组通过\n";
    if (allOk) {
        cout << "所有数据均正确！\n";
        return 0;
    } else {
        cout << "存在错误数据，请检查生成器。\n";
        return 1;
    }
}
