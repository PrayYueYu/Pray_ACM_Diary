#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main() {
    std::cin >> n;
    if(n == 2 || n == 4) {
        std::cout << "-1";
        return 0;
    }
    if(n & 1) {
        int k = (n + 1) / 2;
        std::cout << k << '\n';
        for(int i = 1; i <= k; i++) std::cout << i << ' ';
    }
    else {
        int k = n / 2;
        std::cout << k << '\n';
        for(int i = 1; i <= k + 1; i++) {
            if(i == k) continue;
            std::cout << i << ' ';
        }
    }
    return 0;
}