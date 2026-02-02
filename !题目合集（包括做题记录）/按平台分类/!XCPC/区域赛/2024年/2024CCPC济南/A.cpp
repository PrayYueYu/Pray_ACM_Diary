#include<bits/stdc++.h>
using namespace std;
string s[205][205];
map<string,int> cnt;
signed main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			string t="";
			for(int l=1;l<=k;l++){
				char c;
				cin>>c;
				t+=c;
			}
			s[i][j]=t;
			cnt[t]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(cnt[s[i][j]]==1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	
}
