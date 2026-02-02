#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define FU(i, a, b) for (int i = (a); i <= (b); ++i)
#define FD(i, a, b) for (int i = (a); i >= (b); --i)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 5e5 + 5, MAXN = maxn;

struct node {
    int x, y, z, idx, idy, idz;
};

bool cmpx(node &x, node &y) {
    return x.x < y.x;
}

bool cmpy(node &x, node &y) {
    return x.y < y.y;
}

bool cmpz(node &x, node &y) {
    return x.z < y.z;
}

vector<node> ns;
void solve() {
    int L, W, H;
    cin >> L >> W >> H;
    int p, q, r;
    cin >> p >> q >> r;
    int hs = (p + 1) * (q + 1) * (r + 1);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x,y,z;
        cin>>x>>y>>z;
        ns.push_back(node{x,y,z,0,0,0});
    }
    if(n<hs || n%hs!=0){
        cout<<"0\n";return;
    }
    vector<vector<vector<int>>> v(p + 5, vector<vector<int>>(q + 5, vector<int>(r + 5, 0)));

    //xx
    sort(ns.begin(),ns.end(),cmpx);
    int cnt = 1;
    for(int i=1;i<=p;i++){
        int xh=n/(p+1)*i;
        cnt = cnt *(ns[xh].x-ns[xh-1].x)%MOD;
        int ls = n / (p + 1) * (i - 1);
        for(int j = ls; j < xh; j++) {
        	ns[j].idx = i;
		}
    }
    for(int i = 0; i < n; i++) {
    	if(!ns[i].idx) ns[i].idx = p + 1;
	}
    //yy
    sort(ns.begin(),ns.end(),cmpy);
    for(int i=1;i<=q;i++){
        int xh=n/(q+1)*i;
        cnt = cnt *(ns[xh].y-ns[xh-1].y)%MOD;
        int ls = n / (q + 1) * (i - 1);
        for(int j = ls; j < xh; j++) {
        	ns[j].idy = i;
		}
    }
    for(int i = 0; i < n; i++) {
    	if(!ns[i].idy) ns[i].idy = q + 1;
	}
    //zz
    sort(ns.begin(),ns.end(),cmpz);
    for(int i=1;i<=r;i++){
        int xh=n/(r+1)*i;
        cnt = cnt *(ns[xh].z-ns[xh-1].z)%MOD;
        int ls = n / (r + 1) * (i - 1);
        for(int j = ls; j < xh; j++) {
        	ns[j].idz = i;
		}
    }
    for(int i = 0; i < n; i++) {
    	if(!ns[i].idz) ns[i].idz = r + 1;
	}
    for(int i = 0; i < n; i++) {
    	v[ns[i].idx][ns[i].idy][ns[i].idz]++;
//    	cout << ns[i].idx << ' ' << ns[i].idy << ' ' << ns[i].idz << '\n';
	}
	n /= (p + 1);
	n /= (q + 1);
	n /= (r + 1);
//	cout << n << '\n';
	int f = 1;
	for(int i = 1; i <= p; i++) {
		for(int j = 1; j <= q; j++) {
			for(int k = 1; k <= r; k++) {
				if(v[i][j][k] != n) {
					f = false;
				}
			}
		}
	}
	if(!f) {
		cout << 0 << '\n';
		return;
	}
    cout<<cnt%MOD<<endl;


}

signed main() {
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
