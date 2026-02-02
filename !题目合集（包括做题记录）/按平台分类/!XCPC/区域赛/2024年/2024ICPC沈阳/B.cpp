#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,k,a[1000009],b[1000009],n,m,FF,tow,vis[1000009];
signed main(){
//	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		if(n==1&&m==1){
			printf("Yes\n");
			printf("0\n");
			printf("0\n");
		}
		else if(n==1){
			printf("Yes\n");
			printf("1\n");
			for(i=0;i<m;i++){
				if(i==m-1)printf("%lld\n",i);
				else printf("%lld ",i);
			}
		}
		else if(m==1){
			printf("Yes\n");
			for(i=0;i<n;i++){
				if(i==n-1)printf("%lld\n",i);
				else printf("%lld ",i);
			}
			printf("1\n");
		}
		else{
			for(i=0;i<n*m;i++)vis[i]=0;FF=1;tow=1;
			if(n<m){
				for(i=0;i<m;i++)b[i+1]=i*n+1;
				for(i=1;i<=n;i++){
					while(tow<n*m&&(vis[tow]==1||__gcd(tow,m)>1))tow++;
					if(tow>=n*m){
						FF=0;
						break;
					}
					a[i]=tow;
					for(j=1;j<=m;j++){
						k=(a[i]*b[j])%(n*m);
						vis[k]=1;
					}
				}
			}
			else{
				for(i=0;i<n;i++)a[i+1]=i*m+1;
				for(i=1;i<=m;i++){
					while(tow<n*m&&(vis[tow]==1||__gcd(tow,n)>1))tow++;
					if(tow>=n*m){
						FF=0;
						break;
					}
					b[i]=tow;
					for(j=1;j<=n;j++){
						k=(a[j]*b[i])%(n*m);
						vis[k]=1;
					}
				}
			}
			if(FF==0)printf("No\n");
			else{
				printf("Yes\n");
				for(i=1;i<=n;i++){
					if(i==n)printf("%lld\n",a[i]);
					else printf("%lld ",a[i]);
				}
				for(i=1;i<=m;i++){
					if(i==m)printf("%lld\n",b[i]);
					else printf("%lld ",b[i]);
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
