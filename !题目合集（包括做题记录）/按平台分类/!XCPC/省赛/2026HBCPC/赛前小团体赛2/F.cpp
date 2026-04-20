#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans, vis[5000];
signed main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '0') vis[j] = true;
        }
    }
    for(int i = 0; i < m; i++) {
        if(!vis[i]) ans++;
    }
    std::cout<< ans;
    return 0;
}