#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b,G,i,ans;
map<int,int>M[5009];
struct nod{
	int a,b,ans;
}t;
queue<nod>q;
signed main(){
//	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		while(!q.empty())q.pop();ans=99999;
		scanf("%lld%lld",&a,&b);
		for(i=0;i<=5000;i++)M[i].clear();
		t.a=a;t.b=b;t.ans=0;q.push(t);
		while(!q.empty()){
			t=q.front();q.pop();
			if(t.a>t.b)continue;
			if(M[t.a][t.b])continue;
			else M[t.a][t.b]=1;
			if(t.a==0){
				ans=min(ans,t.ans);
				continue;
			}
			if(t.ans>=ans)continue;
			G=__gcd(t.a,t.b);
			t.a/=G;t.b/=G;t.ans++;
			t.a--;q.push(t);t.a++;
			t.b--;q.push(t);t.b++;
		}
		printf("%lld\n",ans+1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
