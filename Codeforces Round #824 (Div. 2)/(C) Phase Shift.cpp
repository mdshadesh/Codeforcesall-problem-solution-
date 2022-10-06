#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5+10;

int par[N], Size[N];

///DSU---->
void Make(int n=26)
{
    for(int i=0;i<n;i++){
            par[i]=i;
    }
}
int Find(int v)
{
   if(par[v]==v)return par[v];
   return par[v]= Find(par[v]); ///Path compression:
}
void Union(int a,int b)
{
  int p=Find(a);
  int q=Find(b);
  if(p!=q)par[p]=q;

}

int main()
{


    int tc=1;
    cin>>tc;
    while(tc--)
    {

        int n;
        cin>>n;
        string s;
        cin>>s;
        Make();
        map<char,char>mp;
        string ss="abcdefghijklmnopqrstuvwxyz";
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int tmp = s[i]-'a';
            if(mp[s[i]]>='a' && mp[s[i]]<='z')
            {
               cout<<mp[s[i]];
               continue;
            }
            for(int j=0;j<26;j++)
            {
               if(ss[j]=='#')continue;
               if(Find(j)==Find(tmp) && cnt<25)continue;
               Union(tmp,j);
               cnt++;
               mp[s[i]]=ss[j];
               ss[j]='#';
               break;

            }
            cout<<mp[s[i]];



        }
        cout<<endl;

    }



}


