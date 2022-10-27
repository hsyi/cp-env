// abc 129 F;
#include<bits/stdc++.h>
#define int long long
using namespace std;
int l,a,b,MOD;
struct matrix{	
	static int const N=3;
	int v[N][N]={};
	int*operator[](int x){
		return v[x];
	}
	const int*operator[](int x)const{
		return v[x];
	}
	matrix operator*(const matrix&rhs)const{
		matrix res;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				for(int k=0;k<N;k++)
					res[i][j]=(res[i][j]+v[i][k]%MOD*(rhs[k][j]%MOD)%MOD)%MOD;
		return res;
	}
	matrix qpow(int y){
		matrix ans,t=*this;
		for(int i=0;i<N;i++)
			ans[i][i]=1;
		for(;y;y>>=1,t=t*t)
			if(y&1)ans=ans*t;
		return ans;
	}
}ans,f;
signed main(){
	ios::sync_with_stdio(0);
	cin>>l>>a>>b>>MOD;
	ans={{
		{0,0,0},
		{a,0,0},
		{1,0,0}
	}};
	for(int i=10;;i*=10){
		if(a>=i)continue;
		int p=min(l,(i-a-1)/b+1);
		if(!p)break;
		l-=p,a+=p*b;
		f={{
			{i,1,0},
			{0,1,b},
			{0,0,1}
		}};
		ans=f.qpow(p)*ans;
	}
	cout<<ans[0][0]<<"\n";
}
