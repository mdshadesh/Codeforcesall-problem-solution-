#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string,string> map ;
    int n,m;
    cin>>n>>m;
    string s1,s2;
    for (int i = 0; i < m; ++i) {
        cin>>s1>>s2;
        map[s1]=s2;
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        if(s.size()<=map[s].size())cout<<s<<" ";
        else cout<<map[s]<<" ";
    }
    cout<<endl;
}
