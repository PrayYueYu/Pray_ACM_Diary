#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[20], m;
int read() {
    int x;
    scanf("%lld", &x);
    return x;
}
void solve() {
    int len = read(), ans = 0;
    queue<int> q[12];
    for(int i = 1; i <= len; i++) {
        int x = read();
        q[x].push(i);
    }
    while(true) {
        int now = 0, f = 0;
        for(int i = 1; i <= n; i++) {
            while(!q[a[i]].empty()) {
                int x = q[a[i]].front();
                q[a[i]].pop();
                if(x > now) {
                    now = x;
                    f = i;
                    break;
                }
            }
            if(f != i) break;
        }
        if(f == n) ans++;
        else break;
    }
    cout << ans << '\n';
}
signed main() {
    n = read();
    for(int i = 1; i <= n; i++) {
        a[i] = read();
    }
    m = read();
    while(m--) solve();
    return 0;
}
