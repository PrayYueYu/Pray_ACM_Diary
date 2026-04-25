#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(1);
    int T;
    cin >> T;
    while (T--)
    {
        int s1, s2;
        cin >> s1 >> s2;
        if (s2 < 45) {cout << 0.0 << endl; continue;}
        int s = (s1 * 6 + s2 * 4 + 9) / 10;
        if (s >= 95) cout << 5.0 << endl;
        else if (s < 60) cout << 0.0 << endl;
        else cout << 5 - 0.1 * (95 - s) << endl;
    }
}
