#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// ---------- 你提供的随机数引擎 ----------
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll RandLL(ll L, ll R) {
    return uniform_int_distribution<ll>(L, R)(rng);
}
// --------------------------------------

const int M = 100;
const int K = 10;
const int N = 10;
const int TOTAL = N * N; // 100

// 顺时针旋转矩阵中左上角 (r,c) 的 4×4 块
void rotateBlock(vector<vector<int>>& mat, int r, int c) {
    int block[4][4];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            block[i][j] = mat[r + i][c + j];

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            mat[r + i][c + j] = block[3 - j][i];
}

// 生成一个玩具（bad = true 表示 Bob 随机重排）
vector<vector<int>> generateToy(bool bad) {
    vector<vector<int>> mat(N, vector<int>(N));

    // 初始有序 1..100
    int val = 1;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            mat[i][j] = val++;

    if (bad) {
        // Bob 随机重排：将 1..100 打乱
        vector<int> flat(TOTAL);
        iota(flat.begin(), flat.end(), 1);
        shuffle(flat.begin(), flat.end(), rng);   // 直接使用全局 rng
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                mat[i][j] = flat[i * N + j];
    } else {
        // 正常玩具：300 ~ 700 次随机 4×4 旋转
        int ops = (int)RandLL(300, 700);
        for (int t = 0; t < ops; ++t) {
            int r = (int)RandLL(0, N - 4);
            int c = (int)RandLL(0, N - 4);
            rotateBlock(mat, r, c);
        }
    }
    return mat;
}

int main() {
    // 生成 10 组数据
    for (int testId = 1; testId <= 10; ++testId) {
        string inName  = "qqhjh" + to_string(testId) + ".in";
        string outName = "qqhjh" + to_string(testId) + ".out";

        // 决定哪 50 套是坏的（随机挑选）
        bool isBad[M];
        fill(isBad, isBad + M, false);
        vector<int> indices(M);
        iota(indices.begin(), indices.end(), 0);
        shuffle(indices.begin(), indices.end(), rng);
        for (int i = 0; i < 50; ++i)
            isBad[indices[i]] = true;

        // 答案字符串
        string ans;
        for (int i = 0; i < M; ++i)
            ans.push_back(isBad[i] ? '1' : '0');

        // 写入 .in 文件
        ofstream fin(inName);
        if (!fin) {
            cerr << "无法创建 " << inName << endl;
            return 1;
        }
        int id = (testId - 1) % 10;
        fin << id << ' ' << M << ' ' << K << ' ' << N << '\n';

        for (int s = 0; s < M; ++s) {
            for (int t = 0; t < K; ++t) {
                auto mat = generateToy(isBad[s]);
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < N; ++j) {
                        fin << mat[i][j];
                        if (j + 1 < N) fin << ' ';
                    }
                    fin << '\n';
                }
            }
        }
        fin.close();

        // 写入 .out 文件
        ofstream fout(outName);
        if (!fout) {
            cerr << "无法创建 " << outName << endl;
            return 1;
        }
        fout << ans;
        fout.close();

        cout << "生成 " << inName << " 和 " << outName << " 完成" << endl;
    }

    return 0;
}
