#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int hi,mi,cnt=1;
    cin>>mi>>hi;
    int m=mi,mxx=1;
    int h=hi;
    while(t!=1)
    {
        cin>>mi>>hi;
        if((m==mi&&hi==h)) cnt++;
        else
        {
            mxx=max(mxx, cnt);
            cnt=1;
            h=hi;
            m=mi;
        }

        t--;
    }
    cout<<max(mxx,cnt)<<endl;
}


