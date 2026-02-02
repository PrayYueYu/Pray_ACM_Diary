#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define FOR() ll le=e[u].size();for(ll i=0;i<le;i++)
#define QWQ cout<<"QwQ\n";
#define ll long long
#include <vector>
#include <queue>
#include <map>

using namespace std;
const ll N=2201010;
const ll qwq=303030;
const ll inf=0x3f3f3f3f;
const ll p=1000000007, in3=333333336;

ll T;
ll n,m,k;
char s[N],t[N];
ll a[N],b[N],c[N];
ll ans;
ll f[N];

inline ll read() {
    ll sum = 0, ff = 1; char c = getchar();
    while(c<'0' || c>'9') { if(c=='-') ff = -1; c = getchar(); }
    while(c>='0'&&c<='9') { sum = sum * 10 + c - '0'; c = getchar(); }
    return sum * ff;
}

inline ll ksm(ll aa,ll bb) {
    ll sum = 1;
    while(bb) {
        if(bb&1) sum = sum * aa %p;
        bb >>= 1; aa = aa * aa %p;
    }
    return sum;
}

void chushihua() {
    ans = 0;
}

inline ll duan(ll i) {
    if(i<=N-10) return f[i];
    return (ksm(4,i)-1+p) * in3 %p;
}

int main() {
	freopen("1.in", "r", stdin);
    f[1] = 1;
    for(int i=1;i<=N-10;i++) f[i] = (f[i-1] * 4ll + 1ll) %p;
    T = read();
    while(T--) {
        chushihua();
        scanf("%s%s",s+1,t+1); n = strlen(s+1); m = strlen(t+1);
        k = read();
        ll len = max(n,m);
        if(len&1) len++;
        for(ll i=1;i<=len;i++) {
            if(i<=n) a[i] = s[n+1-i] - '0'; else a[i] = 0;
            if(i<=m) b[i] = t[m+1-i] - '0'; else b[i] = 0;
        }
        len >>= 1;
        int you = 0;
        for(ll i=1;i<=len;i++) {
            int yi = a[(i<<1)-1] ^ b[(i<<1)-1];
            int er = a[i<<1] ^ b[i<<1];
            if(yi && er) c[i] = 2;
            if(yi && !er) c[i] = 1;
            if(!yi && er) c[i] = 3;
            if(!yi && !er) c[i] = 0;
            if(c[i] && !you) you = i;
        }
        if(!you) {
            cout<<(duan(k)-1+p)%p<<"\n";
            continue;
        }
        if(k>you) { cout<<"-1\n"; continue; }
        c[k-1] = 4;
        for(ll i=1;i<=len;i++) {
            (ans += c[i] * duan(i) %p) %= p;
        }
        cout<<(ans%p+p)%p<<"\n";
    }
    return 0;
}

