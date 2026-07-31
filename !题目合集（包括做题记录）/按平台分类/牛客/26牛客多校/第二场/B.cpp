#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,S[500009],a[109],ans,kk;
void insert(int x){
    int i;
    for(i=30;i>=0;i--){
        if(x&(1LL<<i)){
            if(a[i]==0){
                a[i]=x;
                break;
            }
            else x^=a[i];
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;ans=0;kk=0;
        for(i=0;i<=30;i++)a[i]=0;
        for(i=1;i<=n;i++){
            cin>>S[i];kk^=S[i];
        }
        for(int i = 1; i <= n;i++) {
        	int now = 0;
        	for(int j = 0; j <= 30; j++) {
        		if(!(kk >> j & 1)) {
        			if(S[i] >> j & 1) {
        				now ^= (1 << j);
					}
				}
			}
//			std::cout << now << '\n';
			insert(now);
		}
        for(i=30;i>=0;i--){
            if((a[i]>0)&&(ans&(1LL<<i))==0){
                ans^=a[i];
            }
        }
        ans=ans+(kk^ans);
        cout<<ans<<'\n';
    }
    return 0;
}
