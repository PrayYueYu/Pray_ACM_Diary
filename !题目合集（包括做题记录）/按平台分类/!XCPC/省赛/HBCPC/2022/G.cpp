#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+2e6+10,M=1e9+7;
int n,ans,f[N],num, L[N];
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
	int now = 0;
	for(int i = 0; i < s1.size(); i++) {
		if(!i || s1[i] != s1[i - 1]) {
			now = i;
		}
		L[i] = now;
	}
	Pre();int mid=0;
	for(int i = 0; i <= num; i++) f[i] = 0;
	ans = 0;
	for(int i=2;i<=num-2;i++){
		if(i<=mid+f[mid])f[i]=min(f[2*mid-i],mid+f[mid]-i+1);
		else f[i]=1;
		while(s[i-f[i]]==s[i+f[i]])f[i]++;
		f[i]--;
		if(i+f[i]>mid+f[mid])mid=i;
		int l = i - f[i] + 1, r = i + f[i] - 1;
		l /= 2, r /= 2;
		if(l > r) continue;
		l--, r--;
		if(L[r] <= l) ans = std::max(ans, r - l + 1);
		else ans = std::max(ans, (r - l + 1) / 2 + 1);
//		std::cout << s[i] << ' ' << f[i] << '\n';
//		std::cout << l << ' ' << r << "\n\n";
	}
	std::cout << ans << '\n';

}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}
