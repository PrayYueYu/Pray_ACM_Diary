#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+9;
int T,n,i,j,k,l,r,ans,cnt,now,mx;
int a[N],b[N],c[N],bit[109];
bool check(){
	int i,j,k;
	for(i=2;i<=n;i++){
		if(b[i]<b[i-1]){
			j=0;
			for(l=0,r=cnt-1;r>=0;l++,r--){
				if(b[i]+(1<<bit[l])<b[i-1]){
					j+=(1<<r);
				}
			}
			j++;k=0;
			for(l=0,r=cnt-1;r>=0;l++,r--){
				if(j&(1<<r))k|=(1<<bit[l]);
			}
			b[i]+=k;
		}
	}
	for(i=2;i<=n;i++)if(b[i]<b[i-1])return true;
	return false;
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n;ans=0;cnt=0;mx=0;
		for(i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
		for(j=30;j>=0;j--){
			if((mx>>j)==0)continue;
			k=1<<j;
			for(i=1;i<=n;i++)b[i]=(a[i]>>j)<<j;
			if(check()){
				ans|=k;bit[cnt++]=j;
				for(i=1;i<=n;i++)if(a[i]&k)a[i]-=k;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1
6
22 0 30 8 30 8
*/
