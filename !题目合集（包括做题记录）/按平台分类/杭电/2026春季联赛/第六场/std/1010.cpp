#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
const int Mod=998244353,inv2=499122177;
unsigned M=1;

int read(){int x=0,y=1;char c=getchar();
while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}
inline int fpow(long long x,int y=Mod-2){
int z=1;while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

inline void FWT(int* F){
    unsigned i=0,j=0;
    for(unsigned o=2,k=1;o<=M;o*=2,k*=2){
		for(i=0;i<M;i+=o){
			for(j=0;j<k;++j){
				F[i+j]+=F[i+j+k];
				if(F[i+j]>=Mod)F[i+j]-=Mod;
				F[i+j+k]=F[i+j]-F[i+j+k]*2;
				if(F[i+j+k]<0)F[i+j+k]+=Mod;
				if(F[i+j+k]<0)F[i+j+k]+=Mod;
			}
		}
	}
	return;
}

inline void IFWT(int* F){
    unsigned i=0,j=0;
	for(unsigned o=2,k=1;o<=M;o<<=1,k<<=1){
		for(i=0;i<M;i+=o){
			for(j=0;j<k;++j){
			    F[i+j]+=F[i+j+k];
				if(F[i+j]>=Mod)F[i+j]-=Mod;
				if(F[i+j]&1)F[i+j]=inv2+(F[i+j]>>1);
				else F[i+j]>>=1;
				F[i+j+k]=F[i+j]-F[i+j+k];
				if(F[i+j+k]<0)F[i+j+k]+=Mod;
			}
		}
	}
	return;
}

inline vector<int> mul(const vector<int>& x,const vector<int>& y){
    vector<int> z(M,0);
    for(unsigned i=0;i<M;i++)z[i]=1ll*x[i]*y[i]%Mod;
    return z;
}

inline void sub(vector<int>& x,const vector<int>& y){
    for(unsigned i=0;i<M;i++){
        if(y[i]<=x[i])x[i]-=y[i];
        else x[i]+=Mod-y[i];
    }
    return;
}

vector<int> f[256];
int n,k,num[N],cnt;
map<int,int> Id;

inline vector<int> int_vec(int x){
    vector<int> res;
    while(x)res.push_back(x%10),x/=10;
    return res;
}

void query(int x){
    if(Id[x])return;
    Id[x]=++cnt;
    int id=cnt;
    f[id].resize(M);
    if(x<10){
        if(x&1){
            for(int i=1;i<=n;i++)++f[id][num[i]];
        }
        else f[id][0]=n;
        FWT(&f[id][0]);
        return;
    }
    vector<int> t=int_vec(x);
    reverse(t.begin(),t.end());
    int m=t.size()-1;
    int y=0,z=t[m];
    for(int i=0;i<m;i++){
        y=y*10+t[i];
    }
    query(y),query(z);
    f[id]=mul(f[Id[y]],f[Id[z]]);
    t.resize(m);
    for(int i=0;i<m;i++){
        vector<int> _t=t;
        _t[i]+=z;
        sort(_t.begin(),_t.end());
        y=0;
        for(int j=m-1;j>=0;j--)y=y*10+_t[j];
        query(y);
        sub(f[id],f[Id[y]]);
    }
    return;
}

signed main(){
//	freopen("data.in","r",stdin);
//    freopen("data.out","w",stdout);
	int T=0;
	T=read();
    while(T--){
    	n=read(),k=read();
    	M=1;
    	Id.clear();
    	for(int i=1;i<=cnt;i++)f[i].resize(0);
    	cnt=0;
	    for(int i=1;i<=n;i++){
	        num[i]=read();
	        while(int(M)<=num[i])M*=2;
	    }
	    int t=0;
	    for(int i=1;i<=k;i++)t=t*10+1;
	    query(t);
	    IFWT(&f[Id[t]][0]);
	    int ans=f[Id[t]][0];
	    for(int i=1;i<=k;i++)ans=1ll*ans*fpow(i)%Mod;
	    printf("%d\n",ans);
	}
    
    return 0;
}


