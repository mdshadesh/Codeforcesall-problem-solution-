#include<bits/stdc++.h>
 
using namespace std;
#define N 1010
#define ll long long
#define ii pair<ll,int>
#define fs first
#define sc second
#define pb push_back
#define NUMCHAR 22
#define MINCHAR 0
#define vec vector<int>
#define ld long double
 
const ld eps=0.000000001;
 
int n,m;
ld x,y;
 
ld sqr(ld x)
{
    return x*x;
}
 
ld xuli(ld n)
{
    ld k,S=n/2;
    cin>>k;
   // cout<<k<<" "<<n<<endl;
    ld l=0,r=n-1,val;
    for(int i=1;i<=200;i++)
    {
        ld mid=(l+r)/2;
        val=S*sqr((n-mid)/n)-S*sqr((n-mid-1)/n);
      //  cout<<l<<" "<<r<<" "<<mid<<" "<<val<<" "<<k<<endl;
        if(val>=k)
            l=mid;
                else r=mid;
    }
    return l;
}
 
int main()
{
    #ifdef TTCC
    freopen("A.inp","r",stdin);///
    freopen("A.out","w",stdout);
    #endif // TTCC
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    cout<<"? "<<(n+1)*2<<endl;
    cout<<0<<" "<<-1<<endl;
    cout<<0<<" "<<m<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<i<<" "<<0<<endl;
        cout<<i<<" "<<m<<endl;
    }
    cout<<n<<" "<<0<<endl;
    cout<<n<<" "<<-1<<endl;
    y=xuli(m);
    cout<<"? "<<(m+1)*2<<endl;
    cout<<-1<<" "<<0<<endl;
    cout<<n<<" "<<0<<endl;
    for(int i=1;i<m;i++)
    {
        cout<<0<<" "<<i<<endl;
        cout<<n<<" "<<i<<endl;
    }
    cout<<0<<" "<<m<<endl;
    cout<<-1<<" "<<m<<endl;
    x=xuli(n);
    for(int i=1;i<=3;i++)
    {
       cout<<"? 1000"<<endl;
       for(int j=1;j<=1000;j++)cout<<rand()*rand()%20000-10000<<" "<<rand()*rand()%20000-10000<<endl;
    }
    cout<<"! "<<setprecision(14)<<fixed<<x<<" "<<y<<endl;
    return 0;
}