#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N = 1e6 + 100, INF = 2e18; 
int read() {
    int x;
    scanf("%lld", &x);
    return x;
}
double calc(double xs, double ys, double xt, double yt) {
    double s1 = fabs(xs - xt);
    double s2 = fabs(ys - yt);
    s1 = s1 * s1;
    s2 = s2 * s2;
    double ans = (double)sqrt(s1 + s2);
    return ans;
}
void solve() {
    double xg, yg, xt, yt;
    cin >> xg >> yg >> xt >> yt;
    double ans = calc(xg, -yg, xt, yt);
    ans = min(ans, calc(-xg, yg, xt, yt));
    int ansx = ans; double ansy = ansx, eps = 1e-10;
    //if(ans - ansy <= eps) cout << ansx << '\n';
    //else 
    printf("%.10Lf\n", ans);
}
signed main() {
    int T = read();
    while(T--) {
        solve();
    }
    return 0;
}
/*
 
*/
