#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int cnt[27];
signed main() {
    int n;
    cin >> n;
    int a1 = -1, a2 = -1, a3 = -1;
    for (int i = 1; i <= n; i++) {
        char e;
        cin >> e;
        int c = e - 'a';
        cnt[c]++;
        if (a1 == -1 && cnt[c] == 5) {
            a1 = c;
            for (int j = 0; j < 26; j++) {
                cnt[j] = 0;
            }
        } else if (a1 != -1 && a2 == -1 && cnt[c] == 7) {
            a2 = c;
            for (int j = 0; j < 26; j++) {
                cnt[j] = 0;
            }
        } else if (a1 != -1 && a2 != -1 && a3 == -1 && cnt[c] == 5) {
            a3 = c;
            for (int j = 0; j < 26; j++) {
                cnt[j] = 0;
            }
        }
    }
    if (a3 == -1) {
        cout << "none";
    } else {
        for (int i = 0; i < 5; i++) {
            cout << (char)('a' + a1);
        }
        for (int i = 0; i < 7; i++) {
            cout << (char)('a' + a2);
        }
        for (int i = 0; i < 5; i++) {
            cout << (char)('a' + a3);
        }
    }

    return 0;
}