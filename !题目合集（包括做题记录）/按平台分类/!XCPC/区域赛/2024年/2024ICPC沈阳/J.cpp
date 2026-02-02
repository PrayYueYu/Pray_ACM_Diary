#include<bits/stdc++.h>
using namespace std;
//string a[8]={"LNG","WBG","HLE","BLG","TES","T1","GEN","FLY"};
//int z[8];
pair<int,string> a[8];

pair<int,string> max1(pair<int,string> a,pair<int,string> b){
	if(a.first < b.first){
		return b;
	}else return a;
}
pair<int,string> min1(pair<int,string> a,pair<int,string> b){
	if(a.first < b.first){
		return a;
	}else return b;
}

signed main(){
	string s;
	for(int i=0;i<8;i++){
		cin>>a[i].second;
		cin>>a[i].first;
	}
	pair<int,string> gj=max1(max1(max1(a[0],a[1]),max1(a[2],a[3])),max1(max1(a[4],a[5]),max1(a[6],a[7])));
	pair<int,string> yj=min1(max1(max1(a[0],a[1]),max1(a[2],a[3])),max1(max1(a[4],a[5]),max1(a[6],a[7])));
	cout<<gj.second<<" beats "<<yj.second;
}
