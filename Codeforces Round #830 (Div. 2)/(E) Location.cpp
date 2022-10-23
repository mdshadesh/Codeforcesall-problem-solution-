#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
const int V=5e4;
const int NN=350;
const int SN=170;
const unsigned inf=3e9;
int n,m,x,y,nn,sn,opt,v;
unsigned ans;
int id[N],bl[SN],br[SN];
int a[N],b[N];
unsigned S[SN][N];
unsigned bv[SN];
int cov[SN],cv,d,i;
inline void cmin(unsigned &x,unsigned y){y<x&&(x=y);}
inline void gcd(int x,int y){
	while(x&&y)x<y?y%=x:x%=y;
	d=x|y;
}
void inquiry_fragment(int x,int y){
	if(cv=cov[id[x]]){
		for(i=x;i<=y;++i){
			gcd(cv,b[i]);
			cmin(ans,1u*cv/d*b[i]/d);
		}
	}
	else {
		for(i=x;i<=y;++i){
			gcd(a[i],b[i]);
			cmin(ans,1u*a[i]/d*b[i]/d);
		}
	}
}
void inquiry(int x,int y){
	ans=inf;
	if(id[x]==id[y])inquiry_fragment(x,y);
	else {
		inquiry_fragment(x,br[id[x]]);
		inquiry_fragment(bl[id[y]],y);
		for(i=id[x]+1;i<id[y];++i){
			cmin(ans,bv[i]);
		}
	}
}
void bdown(int x,int y){
	for(i=x;i<=y;++i)a[i]=cv;
	cov[id[x]]=0;
}
void reset(int x,int y,int p){
	bv[p]=inf;
	for(i=x;i<=y;++i){
		gcd(a[i],b[i]);
		cmin(bv[p],1u*a[i]/d*b[i]/d);
	}
}
void modify(int x,int y,int v){
	if(id[x]==id[y]){
		if(cv=cov[id[x]])
			bdown(bl[id[x]],br[id[x]]);
		for(i=x;i<=y;++i)a[i]=v;
		reset(bl[id[x]],br[id[x]],id[x]);
	}
	else {
		if(cv=cov[id[x]])
			bdown(bl[id[x]],br[id[x]]);
		if(cv=cov[id[y]])
			bdown(bl[id[y]],br[id[y]]);
		for(i=br[id[x]];i>=x;--i)a[i]=v;
		for(i=bl[id[y]];i<=y;++i)a[i]=v;
		reset(bl[id[x]],br[id[x]],id[x]);
		reset(bl[id[y]],br[id[y]],id[y]);
		for(i=id[x]+1;i<id[y];++i){
			cov[i]=v;
			bv[i]=S[i][v];
		}
	}
}
int L,R;
bool bb[N];
int mnp[N],mnb[N];
void pre_work(unsigned *S){
	int j,l;
	for(i=1;i<=V;++i)S[i]=inf;
	for(i=L;i<=R;++i)bb[b[i]]=1;
	for(i=1;i<=V;++i){
		mnp[i]=V+1;
		for(l=1,j=i;j<=V;j+=i,++l)if(bb[j]){
			mnp[i]=l;break;
		}
	}
	for(i=1;i<=V;++i)if(mnp[i]!=V+1){
		for(l=1,j=i;j<=V;j+=i,++l){
			cmin(S[j],1u*l*mnp[i]);
		}
	}
	for(i=L;i<=R;++i)bb[b[i]]=0;
}
char ch;
inline void read(int &x){
	x=0;ch=getchar();while(ch<47)ch=getchar();
	while(ch>47)x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
}
void write(unsigned x){
	if(x>9)write(x/10);putchar(48|x%10);
} 
main(){
	read(n),read(m);int i,j;
	for(i=1;i<=n;++i)read(a[i]);
	for(i=1;i<=n;++i)read(b[i]);
	nn=min((int)(sqrt(n*log(max(n,m)+1))),341);
//	nn=1;
	for(L=1;L<=n;L=R+1){
		++sn;
		R=min(L+nn-1,n);
		bl[sn]=L,br[sn]=R;
		for(i=L;i<=R;++i)id[i]=sn;
		pre_work(S[sn]);
		bv[sn]=inf;
		for(i=L;i<=R;++i){
			gcd(a[i],b[i]);
			cmin(bv[sn],1u*a[i]/d*b[i]/d);
		}
	}
	while(m--){
		read(opt),read(x),read(y);
		if(opt==1)read(v),modify(x,y,v);
		else {
			inquiry(x,y);
			write(ans),putchar('\n');
		}
	}
}