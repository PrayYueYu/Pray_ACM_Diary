#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    // 读取输入文件头部
    int id = inf.readInt();
    int m = inf.readInt();
    int k = inf.readInt();
    int n = inf.readInt();
    const int TOTAL = n * n;

    // 计算真实答案：trueAns[i] = 1 表示坏套，0 表示好套
    vector<int> trueAns(m, 0);
    for (int s = 0; s < m; ++s) {
        bool hasOdd = false;
        for (int t = 0; t < k; ++t) {
            vector<int> mat(TOTAL);
            for (int i = 0; i < TOTAL; ++i)
                mat[i] = inf.readInt();

            // 计算逆序数奇偶性
            int parity = 0;
            for (int i = 0; i < TOTAL; ++i)
                for (int j = i + 1; j < TOTAL; ++j)
                    if (mat[i] > mat[j]) parity ^= 1;
            if (parity) hasOdd = true;
        }
        if (hasOdd) trueAns[s] = 1;
    }

    // 读取选手输出
    string player = ouf.readToken();
    if ((int)player.size() != m)
        quitf(_wa, "输出长度错误：期望 %d，实际 %d", m, (int)player.size());

    int correct = 0;
    for (int i = 0; i < m; ++i) {
        if (player[i] != '0' && player[i] != '1')
            quitf(_wa, "第 %d 位包含非法字符 '%c'", i + 1, player[i]);
        if ((player[i] - '0') == trueAns[i]) ++correct;
    }

    // 检查是否至少 90 个正确
    if (correct >= 90)
        quitf(_ok, "正确个数：%d/100", correct);
    else
        quitf(_wa, "正确个数：%d/100，不足 90", correct);
}
