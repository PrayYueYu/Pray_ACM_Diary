#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 生成设置特定单元格值的BF代码
string generateSetValue(int target) {
    string code;
    // 使用优化的方式：尽量接近目标值
    if (target <= 10) {
        // 小数值直接加
        code += string(target, '+');
    } else {
        // 大数值使用乘法优化
        // 寻找最佳的因子分解
        int bestFactor = 1;
        int bestQuotient = target;
        
        for (int i = 2; i <= 15 && i <= target; i++) {
            if (target % i == 0) {
                int quotient = target / i;
                if (quotient < bestQuotient) {
                    bestFactor = i;
                    bestQuotient = quotient;
                }
            }
        }
        
        if (bestFactor > 1) {
            // 使用循环乘法
            code += string(bestFactor, '+');  // 设置计数器
            code += "[>";                      // 开始循环
            code += string(bestQuotient, '+'); // 增加值
            code += "<-]";                     // 结束循环
        } else {
            // 无法优化，使用直接加法
            code += string(target, '+');
        }
    }
    return code;
}

// 将单个字符转换为BF代码
string charToBrainfuck(char c, int &currentCell) {
    string code;
    int targetValue = (unsigned char)c;
    int diff = targetValue - currentCell;
    
    // 计算最短路径（考虑环绕）
    // 由于BF单元格是0-255，我们可以选择+或-的方向
    if (diff > 0) {
        if (diff <= 128) {
            code += string(diff, '+');
        } else {
            // 反向环绕更短
            code += string(256 - diff, '-');
        }
    } else if (diff < 0) {
        if (-diff <= 128) {
            code += string(-diff, '-');
        } else {
            // 正向环绕更短
            code += string(256 + diff, '+');
        }
    }
    // diff == 0 时不需要操作
    
    code += ".";  // 输出字符
    currentCell = targetValue;
    return code;
}

// 主转换函数
string textToBrainfuck(const string &text) {
    string bfCode;
    int currentCell = 0;  // 当前内存单元的值
    
    for (char c : text) {
        bfCode += charToBrainfuck(c, currentCell);
    }
    
    return bfCode;
}

// 优化版本：尝试减少单元格移动
string textToBrainfuckOptimized(const string &text) {
    string bfCode;
    
    // 使用两个单元格交替工作，减少清零开销
    int cell0 = 0, cell1 = 0;
    bool useCell1 = false;
    
    for (size_t i = 0; i < text.length(); i++) {
        char c = text[i];
        int target = (unsigned char)c;
        
        // 决定使用哪个单元格
        int diff0 = abs(target - cell0);
        int diff1 = abs(target - cell1);
        
        // 考虑环绕
        diff0 = min(diff0, 256 - diff0);
        diff1 = min(diff1, 256 - diff1);
        
        if (diff0 <= diff1) {
            // 使用单元格0
            if (useCell1) {
                bfCode += "<";
                useCell1 = false;
            }
            
            int diff = target - cell0;
            if (diff > 0) {
                if (diff <= 128) bfCode += string(diff, '+');
                else bfCode += string(256 - diff, '-');
            } else if (diff < 0) {
                if (-diff <= 128) bfCode += string(-diff, '-');
                else bfCode += string(256 + diff, '+');
            }
            
            cell0 = target;
        } else {
            // 使用单元格1
            if (!useCell1) {
                bfCode += ">";
                useCell1 = true;
            }
            
            int diff = target - cell1;
            if (diff > 0) {
                if (diff <= 128) bfCode += string(diff, '+');
                else bfCode += string(256 - diff, '-');
            } else if (diff < 0) {
                if (-diff <= 128) bfCode += string(-diff, '-');
                else bfCode += string(256 + diff, '+');
            }
            
            cell1 = target;
        }
        
        bfCode += ".";  // 输出
    }
    
    return bfCode;
}

// 极简版本：每个字符独立设置（代码更长但逻辑简单）
string textToBrainfuckSimple(const string &text) {
    string bfCode;
    
    for (char c : text) {
        unsigned char uc = c;
        // 清零当前单元格（如果非零）
        bfCode += "[-]";  // 确保单元格为0
        // 设置值
        bfCode += string(uc, '+');
        // 输出
        bfCode += ".";
    }
    
    return bfCode;
}

int main() {
    cout << "=== Brainfuck 代码生成器 ===" << endl;
    cout << "输入英语句子，生成对应的BF代码" << endl;
    cout << "输入 'quit' 退出程序" << endl << endl;
    
    string input;
    
    while (true) {
        cout << "请输入文本: ";
        getline(cin, input);
        
        if (input == "quit" || input == "exit") {
            break;
        }
        
        if (input.empty()) {
            continue;
        }
        
        cout << "\n--- 标准版本 ---\n";
        string standard = textToBrainfuck(input);
        cout << "BF代码长度: " << standard.length() << endl;
        cout << standard << endl;
        
        cout << "\n--- 优化版本 ---\n";
        string optimized = textToBrainfuckOptimized(input);
        cout << "BF代码长度: " << optimized.length() << endl;
        cout << optimized << endl;
        
        cout << "\n--- 极简版本 ---\n";
        string simple = textToBrainfuckSimple(input);
        cout << "BF代码长度: " << simple.length() << endl;
        cout << simple << endl;
        
        cout << "\n" << string(50, '=') << "\n\n";
    }
    
    cout << "程序已退出。" << endl;
    return 0;
}
