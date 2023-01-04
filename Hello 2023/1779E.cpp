#include <bits/stdc++.h>
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void read(T &f)
{
    f=0;T fu=1;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-'){fu=-1;}c=getchar();}
    while(c>='0'&&c<='9') {f=(f<<3)+(f<<1)+(c&15);c=getchar();}
    f*=fu;
}
template <typename T> 
void print(T x,char c=0)
{
    if(x<0) putchar('-'),x=-x;
    if(x<10) putchar(x+48);
    else print(x/10),putchar(x%10+48);
    if(c) putchar(c);
}
inline void reads(string &f)
{
    string str="";char ch=getchar();
    while(ch<'!'||ch>'~') ch=getchar();
    while((ch>='!')&&(ch<= '~')) str+=ch,ch=getchar();
    f=str;
}
void prints(string s)
{
    for(int i=0;s[i];++i) 
    putchar(s[i]);
}
typedef long long ll;
const int multicase=0,debug=0,maxn=2e5+50;
int n;
struct node
{
    int out,id;
}a[255];
char s[255];
char ans[255];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) s[i]='1';
    for(int i=1;i<=n;++i)
    {
        printf("? %d ",i);
        s[i]='0';
        for(int j=1;j<=n;++j)
        {
            printf("%c",s[j]);
        }
        s[i]='1';
        printf("\n");
        fflush(stdout);
        scanf("%d",&a[i].out);
        a[i].id=i;
    }
    sort(a+1,a+1+n,[](node x,node y){return x.out>y.out;});
    int sum=0;
    for(int i=1;i<=n;++i) ans[i]='0';
    for(int i=1;i<=n;++i)
    {
        sum+=a[i].out;
        int tmp=(n-i)*i+i*(i-1)/2;
        if(sum==tmp) 
        {
            for(int j=1;j<=i;++j)
            {
                ans[a[j].id]='1';
            }
            printf("! ");
            for(int j=1;j<=n;++j)
            {
                printf("%c",ans[j]);
            }
            //fflush(stdout);
            return ;
        }
    }
    for(int j=1;j<=n;++j)
    {
        printf("%c",ans[j]);
    }
    fflush(stdout);
}
int main()
{
    #ifdef AC
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    clock_t program_start_clock=clock();
    int _=1;
    if(multicase) read(_);
    while(_--) solve();
    fprintf(stderr,"\nTotal Time: %lf ms",double(clock()-program_start_clock)/1000);
    return 0;
}