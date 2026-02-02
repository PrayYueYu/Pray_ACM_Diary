#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[109];
int T,i,n,t1,t2,t3,t4,t5,t6,j,ans,sum,p,S,kk,cc;
struct nod{
	int val,t;
}a[9];
bool cmp(nod x,nod y){
	return x.val>y.val;
}
signed main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;a[1].val=a[2].val=a[3].val=a[4].val=0;
		for(i=1;i<=n;i++)cin>>s[i];
		for(i=1;i<=n;i++){
			if(s[i][1]=='D')a[1].val++;
			if(s[i][1]=='C')a[2].val++;
			if(s[i][1]=='H')a[3].val++;
			if(s[i][1]=='S')a[4].val++;
		}
		cin>>a[1].t>>a[2].t>>a[3].t>>a[4].t>>t5>>t6;
		ans=0;
		for(i=1;i<=4;i++){
			ans+=a[i].val/5;
			a[i].val%=5;
		}
		sum=a[1].val+a[2].val+a[3].val+a[4].val;
		sort(a+1,a+1+4,cmp);
		if(sum<5)cout<<ans<<endl;
		else{
			p=t5+t6;S=sum;
			for(i=1;i<=4;i++){
				S-=a[i].val;
				if(S<0)break;
				if(a[i].t==1){
					if(a[i].val>=2&&a[i].val+S>=5){
						S-=(5-a[i].val);
						a[i].val=0;a[i].t=0;
						ans++;
					}
					else S+=a[i].val;
				}
				else S+=a[i].val;
			}
			if(S>=5){
				kk=0;
				for(i=1;i<=4;i++){
					if(a[i].t==1&&a[i].val==1){
						kk++;
					}
					else if(a[i].t==0&&a[i].val==4)kk++;
				}
				cc=min(min(S/5,kk),p);
				ans+=cc;S-=5*cc;p-=cc;
			}
			if(S>=5&&p==2){
				kk=0;
				for(i=1;i<=4;i++){
					if(a[i].t==1&&a[i].val==0){
						kk++;
					}
					else if(a[i].t==0&&a[i].val==3)kk++;
				}
				cc=min(min(S/5,kk),p/2);
				ans+=cc;S-=5*cc;
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
