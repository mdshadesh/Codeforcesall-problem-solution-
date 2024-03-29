#include <iostream>
#include <string>
 
#define M 8037
#define N 27
#define p 1000000007
 
using namespace std;
 
int n,m,d[M],b[2];
string f[N],s,a[2],ps;
 
void pre(void){
    f[1]="a";
    f[2]="b";
    for (int i=3; f[i-1].length()<M; ++i)
    f[i]=f[i-1]+f[i-2],m=i;
    a[m%2]=f[m];
    a[(m-1)%2]=f[m-1];
}
 
void din(void){
    int len=s.length(),del,le;
    
    b[0]=b[1]=0;
    
    for (int i=0; i<2; ++i){
        ps=a[i]+f[m],del=a[i].length();
        
        le=ps.length();
        
        for (int j=0; j+len<=le; ++j)
        if (j<del && j+len>del && ps.substr(j,len)==s)
        b[i]++;
    }
    
    d[1]=(s=="a" ? 1:0);
    d[2]=(s=="b" ? 1:0);
    
    for (int i=3; i<=n; ++i){
        d[i]=d[i-1]+d[i-2];
        
        if (i<=m){
            ps=f[i],del=f[i-1].length();
            
            le=ps.length();
            for (int j=0; j+len<=le; ++j)
            if (j<del && j+len>del && ps.substr(j,len)==s)
            d[i]++;
        }
        else
        d[i]+=b[(i-1)%2];
        
        if (d[i]>=p)
        d[i]-=p;
    }
    
    cout<<d[n]<<"\n";
    
}
 
int main()
{
    int t;
    pre();
    cin>>n>>t;
    while (t--){
        cin>>s;
        din();
    }
    return 0;
}

