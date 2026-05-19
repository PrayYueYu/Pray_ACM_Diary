#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+2e6+10,M=1e9+7;
int n,ans,f1[N], f2[N],num;
string s1;
char s[N];
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void Pre(){
	s[0]='&';
	s[1]='#';
	int L=s1.size();
	num=1;
	for(int i=0;i<L;i++)s[++num]=s1[i],s[++num]='#';
	s[++num]='^';
}
void solve() {
	getline(cin,s1);
	Pre();int mid=0;
	for(int i = 0; i <= num; i++) f1[i] = f2[i] = 0;
	ans = 0;
	for(int i=2;i<=num-2;i++){
		if(i<=mid+f1[mid])f1[i]=min(f1[2*mid-i],mid+f1[mid]-i+1);
		else f1[i]=1;
		while(s[i-f1[i]]==s[i+f1[i]])f1[i]++;
		f1[i]--;
		if(i+f1[i]>mid+f1[mid])mid=i;
	}
	mid = 0;
	for(int i=2;i<=num-2;i++){
		if(i<=mid+f2[mid])f2[i]=min(f2[2*mid-i],mid+f2[mid]-i+1);
		else f2[i]=1;
		if(s[i] == '#') {
			while(s[i - f2[i]] == s[i + f2[i]] && ((s[i + f2[i]] != '#' && s[i + f2[i]] == s[i + 1]) || s[i + f2[i]] == '#')) f2[i]++;
		}
		else {
			while(s[i-f2[i]]==s[i+f2[i]] && ((s[i + f2[i]] != '#' && s[i + f2[i]] == s[i]) || (s[i + f2[i]] == '#'))) f2[i]++;
		}
		f2[i]--;
		if(i+f2[i]>mid+f2[mid])mid=i;
		ans = std::max(ans, (f1[i] - f2[i]) / 2 + f2[i]);
	}	
	std::cout << ans << '\n';

}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}
