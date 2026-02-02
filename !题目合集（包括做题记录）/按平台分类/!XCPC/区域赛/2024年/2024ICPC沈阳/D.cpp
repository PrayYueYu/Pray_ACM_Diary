#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int A[maxn],B[maxn];
int b[maxn]={};
int cnt=0;
void merge_sortA(int l,int r){
	if(r>l){
		int mid = (l+r)/2;
		int i=l;
		int p=l,q=mid+1;
		merge_sortA(l,mid);
		merge_sortA(mid+1,r);
		while(p<=mid || q<=r){
			if(q>r || (p<=mid && A[p]<=A[q])){
				b[i++]=A[p++];
			}else{
				b[i++]=A[q++];
				cnt+=mid-p+1;
			}
		}
		for(i=l;i<=r;i++) A[i]=b[i];
	}
}

void merge_sortB(int l,int r){
	if(r>l){
		int mid = (l+r)/2;
		int i=l;
		int p=l,q=mid+1;
		merge_sortB(l,mid);
		merge_sortB(mid+1,r);
		while(p<=mid || q<=r){
			if(q>r || (p<=mid && B[p]<=B[q])){
				b[i++]=B[p++];
			}else{
				b[i++]=B[q++];
				cnt+=mid-p+1;
			}
		}
		for(i=l;i<=r;i++) B[i]=b[i];
	}
}

void solve(){
	int n;
	cin>>n;
	int nxa=0,nxb=0;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		b[i]=0;
	}
	cnt=0;
	merge_sortA(1,n);
	nxa=cnt;
	for(int i=1;i<=n;i++){
		cin>>B[i];
		b[i]=0;
	}
	cnt=0;
	merge_sortB(1,n);
	nxb=cnt;
//	cout<<nxa<<" "<<nxb<<endl;
	bool aj=0,bj=0;
	if(nxa%2==1)aj=1;
	if(nxb%2==1)bj=1;
	if(aj!=bj){
		cout<<"A";
	}else cout<<"B";	
	for(int i=1;i<=n-1;i++){
		char ti;
		int l,r,d;
		cin>>ti>>l>>r>>d;
		int len = r-l+1;
		int ca=d%len;
		int cb=len-ca;
		if((ca*cb) %2==1){
			if(ti=='A'){
				aj^=1;
			}else{
				bj^=1;
			}
		};
		if(aj!=bj){
			cout<<"A";
		}else cout<<"B";	
	}
	cout<<"\n";
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}
