#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=998244353LL;
int T,n,l[1000009],r[1000009],i,j,L,R,f[1000009],p,last;
int now,k,FF,ans,a,b;
signed main(){
    // freopen("F.in", "r", stdin);
    cin>>T;
    while(T--){
        scanf("%lld",&n);L=R=0;ans=0;
        for(i=1;i<=n;i++)f[i]=-1;f[0]=0;f[n+1]=INF;
        for(i=1;i<=n;i++)scanf("%lld",&l[i]);
        for(i=1;i<=n;i++)scanf("%lld",&r[i]);
        for(i=1;i<=n;i++)if(l[i]==r[i])f[i]=r[i];
        //for(i=1;i<=n;i++)cout<<f[i]<<endl;
        i=1;
        for(i=1;i<=n;i++){
            if(f[i]==-1){
                for(j=i;j<=n+1;j++)if(f[j]>0){
                    p=j;
                    break;
                }p--;
                if(i==p){
                    if(r[i]-l[i]>=2){
                       ans++;continue;
                    }
                    else{
                        a=min(f[i-1],f[i+1]);
                        b=max(f[i-1],f[i+1]);
                        if(a==l[i]&&b==r[i]){
                            now=f[i-1];k=0;
                            for(j=i-1;j>=1;j--){
                                if(f[j]==now)k++;
                                else break;
                            }L=k;
                            now=f[i+1];k=0;
                            for(j=i+1;j<=n;j++){
                                if(f[j]==now)k++;
                                else break;
                            }R=k;
                            if(L>R)f[i]=f[i+1];
                            else f[i]=f[i-1];
                        }
                        else ans++;
                    }
                }
                else{
                    last=f[i-1];FF=0;
                    for(j=i;j<=p;j++){
                        if(r[j]-l[j]>=2){
                            FF=1;
                        }
                        else{
                            if(r[j]==last||l[j]==last){
                                if(r[j]==last)last=l[j];
                                else last=r[j];
                            }
                            else{
                                FF=1;
                            }
                        }
                    }
                    if(FF==0){
                        for(j=i;j<=p;j++)ans+=1;
                        if(last==f[p+1])ans+=2;
                    }
                    else for(j=i;j<=p;j++)ans+=1;
                    //cout<<ans<<endl;
                }
                i=p;
            }
            else continue;
        }
        now=-INF;k=0;
        for(i=1;i<=n;i++){
            if(f[i]>=0){
                if(f[i]==now){
                    k++;
                }
                else{
                    ans+=k*k;
                    k=1;
                    now=f[i];
                }
            }
            else{
                ans+=k*k;
                now=-INF;
                k=0;
            }
        }
        ans+=k*k;
        printf("%lld\n",ans);
    }
    return 0;
}
/*
2
5
4 4 5 6 7
4 5 6 7 7
5
4 4 5 6 7
4 5 6 7 7
*/
