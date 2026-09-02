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

    // 从标准答案文件读取正确的 01 串
    string correct = ans.readToken();
    // 从选手输出读取选手答案
    string player = ouf.readToken();

    // 长度检查
    if ((int)correct.size() != m)
        quitf(_fail, "标准答案长度错误，期望 %d，实际 %d", m, (int)correct.size());
    if ((int)player.size() != m)
        quitf(_wa, "选手输出长度错误，期望 %d，实际 %d", m, (int)player.size());

    // 统计正确数，同时检查字符合法性
    int correctCnt = 0;
    for (int i = 0; i < m; ++i) {
        if (player[i] != '0' && player[i] != '1')
            quitf(_wa, "第 %d 位含有非法字符 '%c'", i + 1, player[i]);
        if (player[i] == correct[i]) ++correctCnt;
    }

    // 计算阈值：至少 90% 正确（向上取整）
    int need = (m * 9 + 9) / 10; // ceil(0.9 * m)

    if (correctCnt >= need)
        quitf(_ok, "正确个数：%d/%d (≥ %d)", correctCnt, m, need);
    else
        quitf(_wa, "正确个数：%d/%d (< %d)", correctCnt, m, need);
}
