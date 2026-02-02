#include<bits/stdc++.h>
using namespace std;
int p[100005];
void solve(){
	int n;
	string s;
	cin>>n>>s;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]!=i)cnt++;
	}
	if(n==2){
		cout<<"Alice\n";
	}else {
		if(n==3 && s=="Bob" && ((p[1]==3 && p[2]==1 &&p[3]==2)||(p[1]==2 && p[2]==3 &&p[3]==1))){
			cout<<"Alice\n";
			return;
		}
		if(cnt==2 && s=="Alice"){
			cout<<"Alice\n";	
		}else cout<<"Bob\n";
	}
}


signed main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
