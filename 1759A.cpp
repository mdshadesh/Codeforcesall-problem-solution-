#include<bits/stdc++.h>
using namespace std;
#define e endl
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
const int N = 1e5;

int main(){
    int q;
    cin>>q;
    while (q--){
    string t = {"Yes"};
    string s;
    cin>>s;
    bool ans = true;
    if (s[0]=='Y'){
        int p=0;
    for (int i=0;i<s.size();i++){
        if (p>2){
            p=0;
        }
        if (s[i]==t[p]){
            ans=true;
        }
        else {
            ans=false;
            break;
        }
        p++;
    }
    }
    else if (s[0]=='e'){
        int p=1;
    for (int i=0;i<s.size();i++){
        if (p>2){
            p=0;
        }
        if (s[i]==t[p]){
            ans=true;
        }
        else {
            ans=false;
            break;
        }
        p++;
    }
    }
    else if (s[0]=='s'){
         int p=2;
    for (int i=0;i<s.size();i++){
        if (p>2){
            p=0;
        }
        if (s[i]==t[p]){
            ans=true;
        }
        else {
            ans=false;
            break;
        }
        p++;
    }
    }
    else {
        ans=false;
    }

    if (ans){
        cout<<"YES"<<e;
    }
    else{
        cout<<"NO"<<e;
    }
    }
    return 0;
}
