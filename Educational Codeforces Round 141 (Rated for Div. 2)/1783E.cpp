#include <bits/stdc++.h>
using namespace std;
 
int32_t main(){
 
    int TQ;cin>>TQ;
    while(TQ--){
 
        int n;
        cin>>n;
        int Arr[n+12],Brr[n+12];
        for(int i=1;i<=n;i++)cin>>Arr[i];
        for(int i=1;i<=n;i++)cin>>Brr[i];
        int Dx[n+12];
        fill(Dx,Dx+n+2,0);
        vector<pair<int,int>>v;
        for(int i=1;i<=n;i++){
            if(Arr[i]<=Brr[i])continue;
            else {
                   Dx[Brr[i]]++;
                   Dx[Arr[i]]--;
            }
            }
        Dx[0]=0;
        for(int i=1;i<=n;i++){
                Dx[i]+=Dx[i-1];
                //cout<<Dx[i]<<" ";
        }
        vector<int>Ans;
        for(int k=1;k<=n;k++){
            bool Check=1;
            for(int nk=k;nk<=n;nk+=k){
                if(Dx[nk]!=0)Check=0;
            }
            if(Check)Ans.push_back(k);
        }
        cout<<Ans.size()<<"\n";
        for(auto It:Ans)cout<<It<<" ";
            cout<<"\n";
 
 
        }
    return 0;
}